# Le compilateur g++

## Sous Linux Debian Stretch

Je dispose de **Stretch** qui est la dernière version de **Debian** et donc vous devrez adapter l'installation à votre système si ce n'est pas la distribution Linux que vous avez.

### Noms connus pour invoquer le compilateur

Parmi les noms connus pour faire "de la compilation", on trouve :
**c++**, **cpp**, **g++**, **gcc**, **gcc-x**, **c++**, **cpp-x** (x est le numéro de version du fichier). 

Comme on s'y perd un peu parmi ces noms, il faut comprendre que **g++** est le "**front end**", ce qui veut dire qu'il s'occupe de lancer dans cet ordre toute la chaîne de compilation. Il remplace **gcc** qui est prévu à l'origine pour le langage **C**, bien que **gcc** puisse compiler du code source c++ avec certaines options. Comme son nom l'indique, *Gcc* veut dire : " **Gnu Compileur collection** ". Il s'agit d'une collection d'outils **Gnu** pour compiler des codes sources dans différents langages (dont C et C++). 

### Les éléments de la chaîne de compilation

Le programme **g++** gère la chaîne de compilation. Les programmes sont les suivants et fonctionnent dans cet ordre :
- le préprocesseur **cpp** s'occupe d'intégrer des morceaux de code (inclusion) disponibles dans d'autres fichiers (comme les fichiers d'entête ou "headers"). Il s'occupe aussi d'intégrer d'autres éléments (macro) et permet la compilation conditionnelle (on compile d'une façon ou d'une autre selon les directives, par exemple selon le système d'exploitation).
- le compilateur **cclplus** a pour but de générer le fichier assembleur à partir du code source produit par le prépocesseur et d'afficher éventuellement des erreurs.
- l'assembleur **gas** a pour but de transformer le code assembleur en langage machine (binaire) directement lisible par le processeur mais aussi de mettre des informations additionnelles comme les informations de déboguage. L'assembleur produit des fichiers de type objet (.o) ou lib (.lib).
- l'éditeur de lien **ld** rassemble les fichiers" objets et lib pour produire un exécutable (par exemple au format "**elf**").
Dorénavant, je vais appeler "**compilateur**" le programme **g++** chargé de l'ensemble de la compilation.

### Obtenir la version du compilateur

Il est très important d'obtenir la version car les prises en charge du langage (C++11, C++14, etc.) ne sont pas les mêmes selon la version du compilateur.

​    g++ --version

### Obtenir les options de compilation

Les premières options de compilations peuvent être obtenue avec la commande :

    g++ --h

Bien sûr on peut afficher la page de manuel et de nombreuses informations avec la commande :

    man g++

### Où se trouve le compilateur ?

Tout d'abord, il est important de dire que la commande **g++** n'invoque pas directement le compilateur. Il s'agit souvent d'un lien symbolique qui mène vers le vrai fichier exécutable (par exemple **x86_64-linux-gnu-g++-6**).

Je vais donc expliquer comment j'ai fait pour obtenir le vrai fichier exécutable (je dispose de **Debian Stretch**  comme je l'ai déja dit).

### Installation du paquet g++ dans Debian

C'est très simple, il suffit de taper la commande :

    sudo apt-get install g++

### Trouver l'endroit de l'exécutable réel pour g++
Pour  connaître le dossier d'origine de la commande **g++** que vous tapez, vous devez utiliser la commande **which**, voici le résultat :

    yannick@debian:/$ which g++
    /usr/bin/g++

Ensuite, vous devez vous rendre dans le dossier concerné :

    yannick@debian:/$ cd /usr/bin/
    yannick@debian:/usr/bin$

Une fois rendu dans le dossier en question,  il est possible de vérifier si le fichier **g++** est un lien ou pas : la présence de -> montre qu'il y a présence d'un lien :

    yannick@debian:/usr/bin$ ls -l g++
    lrwxrwxrwx 1 root root 5 avril  8  2017 g++ -> g++-6

On vient d'obtenir une information sur la version qui est "6" dans mon cas. On vérifie à nouveau :

        yannick@debian:/usr/bin$ ls -l g++-6
        lrwxrwxrwx 1 root root 22 févr. 14  2018 g++-6 -> x86_64-linux-gnu-g++-6
        yannick@debian:/usr/bin$ ls -l x86_64-linux-gnu-g++-6
        -rwxr-xr-x 1 root root 953112 févr. 14  2018 x86_64-linux-gnu-g++-6

Il peut exister de nombreux liens chaînés comme le montrent les commandes ci-dessus.

Au final, on voit sur l'exemple ci-dessus que le véritable nom du compilateur (le fichier exécutable) est **x86_64-linux-gnu-g++-6** (me concernant). Selon votre système, il sera peut-être différent (32 ou 64 bits).

**Note :**  on peut afficher la liste des liens dans un dossier avec la commande  :

    ls -F

Les liens seront reconnaissables car alors terminés par le symbole "**@**" :

{width=70%}
![Affichage des liens symboliques](images/chap1/compilateur/ls-F.png "Affichage des liens symboliques")



### Obtenir des informations précises sur g++

La commande **file** permet d'obtenir un peu plus d'informations sur ce fichier :

    yannick@debian:/usr/bin$ file x86_64-linux-gnu-g++-6
    x86_64-linux-gnu-g++-6: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=8c9108996de1408c7aa0a2c42a5f4cc6492a0dd8, stripped






