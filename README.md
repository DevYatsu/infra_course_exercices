# docker exercices

Partie 1  - Containers
Exercice 1.1 - Hello world:

Lancer et créez un container de l'image hello-world et notez le résultat.
Exercice 1.2 - Redirection de port

Créez un container nginx redirigez le port 8080 de votre machine vers le port 80 du container.

Ouvrez votre navigateur web et rendez-vous sur http://localhost:8080, qu'est-t-il écrit ?
Exercice 1.3 - Variables d'environnement


Créer un container mysql et paramétrez-le comme suit :

    User : <prenom>
    Password : <votre choix>
    Database : <prenom>

Redirigez le port 3306 de votre machine vers le port 3306 du container.
En utilisant un outil d'administration de base de donnée (Par exemple Beekeeper studio) ou la ligne de commande du container, créez une table et insérez des données à l'intérieur.
Exercice 1.4 - Volumes + Docker run

Créez un répertoire sur votre machine
Créez un mini script python de votre choix dans ce répartoire (Pas besoin de faire quelque chose de compliqué, par exemple afficher les 10 premiers nombres de fibonacci ou un fizz buzz)
Lancez un container python avec un "shell" avec le répertoire monté vers le dossier "/mnt/python_mount" du container.
Utiliser la commande python pour lancer votre script : python /mnt/python_mount/<my_script>.py
Exercice 1.5 - Networking

Réutiliser le container l'exercice 1.3
Créer un container phpMyAdmin et configurer le pour que celui-ci puisse se connecter à la base de donnée en utilisant un network.
Partie 2 - Images
Exercice 2.1 - Site web statique


Dans un répertoire, créez un mini site html statique (par exemple CV) avec les éléments suivants :

    img/splash.png (une image de votre choix)
    css/index.css (fichier css simple qui modifie légèrement la mise en page de votre site)
    index.html : Fera la navigation vers les autres pages et affiche l'image
    2 autres pages : Simple avec quelques images, textes, liens

Créer un Dockerfile se basant sur l'image nginx et qui va servir votre site. (sans utiliser de volume)
Publiez votre image sur le docker hub.
Sur le PC d'un camarade, lancez votre container et accédez à votre site.
Exercice 2.2 - Multistage

Créer un programme en c++ qui affiche les 2000 premiers nombres de la suite de Fibonacci.
Créer un Dockerfile multistage avec les stages suivants :

    Compiler l'application et créer un exécutable nommé "fibo"
    Récupère l'exécutable du précédent stage et le place dans /bin
    Au lancement du container, exécute le fichier /bin/fibo

Une fois le build de votre image terminé, créez un container et démarez-le. Quels sont les 2000 premiers nombres de la suite de Fibonacci ?
Partie 3 - Docker Compose

Reproduire les exercices précédents avec docker-compose.
