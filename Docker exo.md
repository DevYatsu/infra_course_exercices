# Docker exo

> Réalisé par YANIS AMANI

### Exercice 1.1 - Hello world:

`docker pull henriquemarquesreis/app_cours_docker`
`docker run -p 8080:8080 henriquemarquesreis/app_cours_docker`

RESULTAT:

Page web avec ecrit **Hello World!**
et dans le shell:

```shellscript
 * Debug mode: off
WARNING: This is a development server. Do not use it in a production deployment. Use a production WSGI server instead.
 * Running on all addresses (0.0.0.0)
 * Running on http://127.0.0.1:8080
 * Running on http://172.17.0.3:8080
Press CTRL+C to quit
```

### Exercice 1.2 - Redirection de port

`docker pull nginx`
`docker run -p 8080:80 nginx`

RESULTAT:

```text
Welcome to nginx!

If you see this page, the nginx web server is successfully installed and working. Further configuration is required.

For online documentation and support please refer to nginx.org.
Commercial support is available at nginx.com.

Thank you for using nginx.
```

Exercice 1.3 - Variables d'environnement
`docker pull mysql`
`docker run --name mydb -p 3306:3306 -e MYSQL_USER=Yanis -e MYSQL_PASSWORD=test -e MYSQL_DATABASE=db -e MYSQL_ROOT_PASSWORD=passwd mysql`
`docker exec -it mydb mysql -uYanis -ptest`

Puis dans la ligne de commande mysql
```sql
SHOW DATABASES;
USE DB;
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100)
);
INSERT INTO users (name, email) VALUES ('Yanis', 'y@he-arc.ch');
```

### Exercice 1.4 - Volumes + Docker run

`docker pull python`
`docker run -it --rm -v "$PWD":/mnt/python_mount -w /mnt/python_mount python bash`
puis dans bash: `python fib.py`

* -v: copier le repertoire actuel dans le dir en question
* -w: set le repertoire en tant que WORKDIR

### Exercice 1.5 - Networking

`docker pull phpmyadmin`
`docker run -d --name mydb -p 3306:3306 -e MYSQL_USER=Yanis -e MYSQL_PASSWORD=test -e MYSQL_DATABASE=db -e MYSQL_ROOT_PASSWORD=passwd mysql`
`docker run --name phpmyadmin -d --link mydb:db -p 8080:80 phpmyadmin`
et enfin on va sur `http://localhost:8080`

## Partie 2 - Images

### Exercice 2.1 - Site web statique

**Le Dockerfile:**
```docker
FROM nginx:alpine3.22-slim
COPY ./ /usr/share/nginx/html
```

Pour tester le site vous avez juste à executer ces deux commandes: 
* `docker pull devyatsuu/example_static_nginx` 
* `docker run -d -p 8080:80 devyatsuu/example_static_nginx`
* puis accédez-y via http://localhost:8080

### Exercice 2.2 - Multistage

\[...]
Une fois le build de votre image terminé, créez un container et démarez-le. Quels sont les 2000 premiers nombres de la suite de Fibonacci ?

Voyez par vous même je n'ai pas la place pour copier tous ces nombres: 
`docker push devyatsuu/example_fib_2000`

## Partie 3 - Docker Compose

Reproduire les exercices précédents avec docker-compose.

exo 1.1: `docker compose run exo1.1`
exo 1.2: `docker compose run exo1.2`

exo 1.3:
`docker compose run exo1.3`
Puis après une dizaine de secondes:
`docker compose run mysql-client`

exo 1.4:
`docker compose run --rm exo1.4 bash`
Puis: `python fib.py`

exo 1.5: `docker compose run -p 1500:80 exo1.5`
exo 2.1: `docker compose run -p 2100:80 exo2.1`
exo 2.2: `docker compose run -p 2200:80 exo2.2`


PUIS POUR TOUS LES LANCER EN MEME TEMPS: `docker compose up`

> PS: n'oubliez pas de tuer les orphelins
