## L'utilitaire d'automatisation de compilation make

### Sous Linux Debian Strech

**Make** est un utilitaire assez ancien du projet Gnu dont la vocation est d'automatiser le processus de compilation. Il examine en particulier les fichiers déjà à jour au niveau de la compilation pour éviter une recompilation et donc permet un gain de performances substantiel lors de ce processus.

#### Paquet "make" dans Debian Stretch

En principe, cet utilitaire est tellement courant dans le processus d'automatisation de compilation sur les systèmes basés sur Linux qu'il devrait déjà être installé.

Si ce n'est pas le cas, il suffit de lancer la commande :

    sudo apt-get install make

#### Version de "make"

Comme habituellement, vous pouvez obtenir la version de make avec l'option --version

    make --version

Me concernant, il s'agit de la version "**GNU Make 4.1**"

#### Premier makefile

Le "**makefile**" est un fichier de configuration lu par l'utilitaire **make**. Il suffit de placer le fichier dans un dossier et de lancer **make** dans ce même dossier avec certaines options.

**Make** reconnaît pour son fichier de configuration les noms de fichier suivants : "**makefile**", ou "**Makefile**".

Pour saisir votre premier **makefile**, vous devez bien sûr utiliser votre éditeur de texte préféré (on ne parle pas ici d'un logiciel de traitement de texte "**wysiwyg**" du genre Libreoffice Writer).

J'utilise pour ma part pour le moment le logiciel **Gedit**. Les habitués des systèmes basés sur Linux préféreront **Vim** ou **Emacs**. **Gedit** reconnait habituellement la plupart des syntaxes courantes en les colorant (coloration syntaxique), en particulier les syntaxes du langage **C,** **C++** et bien sur la syntaxe spéciale de **make**.

Voici le contenu de notre premier **makefile** :

    all:
        g++ -Wall ex.cpp -o ex
    clean:
        rm -f ex

**all:** et "**clean:**" s'appellent des "cibles" (targets). On peut donner le nom que l'on souhaite aux cibles (comme "**toto:**") mais certaines conventions et habitudes existent ("**all:**" compile tout et "**clean**" nettoie).

**Note :** pour décaler les instructions "**g++ etc**" et "**rm etc**", il faut les indenter avec une **tabulation** et pas des espaces. Les cibles "**all:**" et "**clean:**" sont contre la marge (pas d'indentation).

#### Ordre d'exécution du makefile simplifié

Sur le makefile précédent, si vous entrez la commande demandant à make d'aller vers la cible "**all**",

    make all

vous allez compiler le fichier **ex1.cpp** avec l'utilitaire **g++**, avec l'option **-Wall** (Warning all) pour produire un fichier exécutable nommé **ex** :

    g++ -Wall ex.cpp -o ex

Si vous entrez la commande demandant à **make** d'aller sur la cible "**clean**",

    make clean

vous allez exécuter la commande de suppression du fichier ex à l'aide de l'utilitaire **rm**, avec l'option **-f** :

    rm -f ex

Si vous ne spécifiez pas de cible avec simplement la commande,

    make

alors **make** lancera le contenu de la première cible ("**all:**" dans notre cas).

Une fois le **makefile** saisi et enregistré, il faut maintenant saisir notre premier fichier d'exercice (le **ex.cpp** qui figure dans le makefile)

#### Premier exercice pour vérification

Votre système doit être maintenant fonctionnel et nous allons le vérifier par le premier exercice (**ex1.cpp**).

Commencer par créer et se placer dans le dossier de votre choix. Pour moi, ce sera **/home/yannick/Documents/cpp** ou **~/Documents/cpp** ce qui est équivalent pour moi.

    mkdir ~/Documents/cpp
    cd ~/Documents/cpp

Ensuite, il faudra lancer **Gedit** avec le fichier ex1.cpp à l'intérieur ainsi que le fichier Makefile

    gedit ex1.cpp Makefile

**Note :** la présence du **Makefile** dans **Gedit** n'est pas obligatoire mais permettra de contrôler son contenu..

Le code à saisir dans **ex1.cpp** permet d'afficher le message : **Salut le c++** dans la ligne de commande (application du type **"console"**) et est juste un exercice de vérification de la configuration. Le code sera expliqué en détail plus tard.

    #include <iostream>

    int main (){
      std::cout << "Salut le c++\n";
      return 0;
    }

Une fois le fichier **ex1.cpp** enregistré, vous pouvez quitter **Gedit** avec le raccourci "**CTRL-q**" pour revenir à la ligne de commande.

Pour plus de faciliter et pour éviter de modifier le makefile à chaque exercice, nous allons copier *ex1.cpp* dans *ex.cpp**.

    cp ex1.cpp ex.cpp

Vous pourrez pour les différentes exercices les nommer comme vous le souhaitez à conditions que vous fassiez toujours une copie dans **ex.cpp*.

Pour compiler **ex.cpp**, il suffit maintenant de lancer la commande :

    make all

ou tout simplement ( **all:** étant la première cible) :

    make

Il ne devrait pas y avoir de message d'avertissement du compilateur même si l'option "**Wall**" ("Warning all") est activée.

Il suffit maintenant d'exécuter le fichier fraîchement produit **ex1** dans le dossier courant (**./**) :

    ./ex

La bonne nouvelle, c'est que vous pouvez saisir cette instruction dans votre makefile pour ne pas lancer votre programme à chaque fois. Attention à bien mettre une **tabulation** devant le **./ex** et pas des espaces. Votre makefile sera donc le suivant :

    all:
        g++ -Wall ex.cpp -o ex
        ./ex
    clean:
        rm -f ex



Si tout est ok le message suivant s'affiche dans la console :

    Salut le c++

Hourra, vous avez compilé votre premier programme en **C++** !! Si malheureusement, ce n'est pas le cas, il faudra revoir les différentes étapes de configuration.

