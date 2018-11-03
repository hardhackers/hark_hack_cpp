# L'utilitaire d'automatisation de compilation make

## Sous Linux Debian Strech

**Make** est un utilitaire assez ancien du projet Gnu dont la vocation est d'automatiser le processus de compilation. Il examine en particulier les fichiers déjà à jour au niveau de la compilation pour éviter une recompilation et donc permet un gain de performances substantiel lors de ce processus.

### Paquet "make" dans Debian Stretch

En principe, cet utilitaire est tellement courant dans le processus d'automatisation de compilation sur les systèmes basés sur Linux qu'il devrait déjà être installé.

Si ce n'est pas le cas, il suffit de lancer la commande :

    sudo apt-get install make

### Version de "make"

Comme habituellement, vous pouvez obtenir la version de make avec l'option --version

    make --version

Me concernant, il s'agit de la version "**GNU Make 4.1**"

### Premier makefile

Le "**makefile**" est un fichier de configuration lu par l'utilitaire **make**. Il suffit de placer le fichier dans un dossier et de lancer **make** avec certaines options.

Le **makefile** a habituellement les noms de fichier suivants : "**makefile**", ou "**Makefile**".

Pour saisir votre premier **makefile**, vous devez bien sûr utiliser votre éditeur de texte préféré (on ne parle pas ici d'un logiciel de traitement de texte "**wysiwyg**" du genre Libreoffice Writer).

J'utilise pour ma part pour le moment le logiciel **Gedit**. Les habitués des systèmes basés sur Linux préféreront **Vim** ou **Emacs**. Gedit reconnait habituellement la plupart des syntaxes courantes en les colorant (coloration syntaxique), en particulier les syntaxes du langage C, C++ et bien sur la syntaxe spéciale de **make**.

Voici le contenu de notre premier **makefile** :

    all:
        g++ -Wall ex1.cpp -o ex1
    clean:
        rm -f ex1

**all:** et "**clean:**" s'appellent des "cibles" (targets). On peut donner le nom que l'on souhaite aux cibles (comme "**toto:**") mais certaines conventions et habitudes existent ("**all:**" compile tout et "**clean**" nettoie).

**Note :** pour décaler les instructions "**g++ etc**" et "**rm etc**", il faut les indenter avec une tabulation et pas des espaces. "**all:**" et "**clean:**" sont contre la marge (pas d'indentation).

### Ordre d'exécution du makefile simplifié

Sur le makefile précédent si vous entrez la commande demandant à make d'aller vers la cible "**all**",

    make all

vous allez compiler le fichier **ex1.cpp** avec l'utilitaire **g++**, avec l'option **Wall** pour produire un fichier exécutable nommé **ex1** :

    g++ -Wall ex1.cpp -o ex1

Si vous entrez la commande demandant à **make** d'aller sur la cible "**clean**",

    make clean

vous allez exécuter la commande de suppression du fichier ex1 à l'aide de l'utilitaire **rm**, avec l'option **-f** :

    rm -f ex1

Si vous ne spécifiez pas de cible avec simplement la commande,

    make

alors **make** lancera le contenu de la première cible ("**all:**" dans notre cas).

Une fois le **makefile** saisi et enregistré, il faut maintenant saisir notre premier fichier d'exercice (le **ex1.cpp** qui figure dans le makefile)

### Premier exercice pour vérification

Votre système doit être maintenant fonctionnel et nous allons le vérifier par le premier exercice (**ex1.cpp**).

Commencer par créer et se placer dans le dossier de votre choix. Pour moi, ce sera **/home/yannick/Documents/cpp** ou **~/Documents/cpp** ce qui est équivalent pour moi.

    mkdir ~/Documents/cpp
    cd ~/Documents/cpp

Ensuite, il faudra lancer **Gedit** avec le fichier ex1.cpp à l'intérieur ainsi que le fichier Makefile

    gedit ex1.cpp Makefile

**Note :** la présence du **Makefile** dans **Gedit** n'est pas obligatoire mais permettra de contrôler les fichiers à compiler, les options de compilation et le fichiers à nettoyer le cas échéant.

Le code à saisir dans **ex1.cpp** est juste un exercice de vérification de la configuration, le code sera expliqué plus tard.

    #include <iostream>

    int main (){
      std::cout << "Salut le c++\n";
      return 0;
    }

Une fois le fichier **ex1.cpp** enregistré, vous pouvez quitter **Gedit** avec le raccourci "**CTRL-q**" pour revenir à la ligne de commande.

Pour compiler **ex1.cpp**, il suffit maintenant de lancer la commande :

    make all

ou tout simplement ( **all:** étant la première cible) :

    make

Il ne devrait pas y avoir de message d'avertissement du compilateur même si l'option "**Wall**" ("Warning all") est activée.

Il suffit maintenant d'exécuter le fichier fraîchement produit **ex1** dans le dossier courant (**/.**) :

    ./ex1

Si tout est ok le message suivant s'affiche dans la console :

    Salut le c++

Hourra, vous avez compilé votre premier programme en **C++** !!