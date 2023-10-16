# Boot2root
## Rendu numero 2

Dans ce projet, l'objectif est d'acquérir les privilèges root sur une VM. Afin de valider la partie obligatoire du projet, il faut obtenir les privilèges root sur le serveur en utilisant deux méthodes différentes.
Chaque méthode employée doit être accompagnée d'un compte rendu complet expliquant les différentes étapes pour devenir root sur le serveur.


## SSH ZAZ

Nous commencerons la solution 2 a partir du profil de zaz en ssh

	ssh zaz@192.168.56.107

Mot de passe :

	646da671ca01bb5d84dbb5fb2238dc8e

## Faille Dirty Cow

La vulnérabilité Dirty COW permet à un attaquant de modifier un fichier système protégé en mémoire en le rendant accessible en écriture même s'il était normalement en lecture seule. Cela peut être utilisé pour élever les privilèges d'un processus non privilégié pour devenir root.

Le nom "Dirty COW" provient du jeu de mots "copy-on-write" (copie-sur-écriture) et fait référence au fait que l'exploit exploite une condition de course (race condition) dans le mécanisme de copie-sur-écriture.

Le programme dirtycow.c genere une nouvelle ligne de mot de passe pour la remplacer dans le fichier /etc/passwd.

Le code commence par sauvegarder le fichier /etc/passwd en le copiant vers /tmp/passwd.bak. Il le fait en utilisant la fonction copy_file pour effectuer la copie.
Ces informations sont destinées à être utilisées pour créer un nouvel utilisateur dans le fichier /etc/passwd.
Le mot de passe renseigne est ensuite hache. Ensuite le code génère une ligne au format /etc/passwd en utilisant les informations d'utilisateur et le hachage de mot de passe.
Le code exploite la vulnérabilité Dirty COW en utilisant une technique de race condition avec les fonctions mmap, fork, ptrace et pthread. Cette exploitation permet d'écrire la ligne /etc/passwd modifiée directement dans la mémoire du processus parent qui exécute le code, contournant ainsi les mécanismes de sécurité du noyau Linux. Une fois que la modification est effectuée dans la mémoire, le processus parent sauvegarde la ligne modifiée dans le fichier /etc/passwd réel.

### Programme sur la VM

On recupere le fichier 'dirty cow' :

	scp ./dirtycow.c zaz@192.168.56.108:/home/zaz/

On compile comme ceci :

	gcc -pthread dirtycow.c -o dirty -lcrypt

`-phthread` : inclusion de la bibliothèque pthread (POSIX threads)
`-lcrypt` : inclusion de la bibliothèque crypt (chiffrement du mot de passe)

On lance le programme :

	zaz@BornToSecHackMe:~$ ./dirty 
	/etc/passwd successfully backed up to /tmp/passwd.bak
	Please enter the new password: 

Ici le programme nous demande de donner un password pour notre creation d'utilisateur `root`, uid(0), euid(0).

	Complete line:
	root:rovbaUosoT2Is:0:0:pwned:/root:/bin/bash

	mmap: b7fda000

Une fois le programme terminee, on peut faire

	sudo su

et se connecter avec le nouveau mot de passe qu'on a renseignee.
Nous voila connecter en tant que root :

	root@BornToSecHackMe:/home/zaz# whoami
	root
	root@BornToSecHackMe:/home/zaz# id
	uid=0(root) gid=0(root) groups=0(root)