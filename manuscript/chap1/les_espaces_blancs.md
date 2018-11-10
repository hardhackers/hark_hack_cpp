## Gestion des espaces blancs

La rédaction des fichiers sources en **C++** est relativement libre. On peut insérer des espaces blancs (espaces, tabulations, retours charriots, sauts de ligne etc) sans trop de conséquences.

Cependant, il y a des insertions à ne pas faire en particulier des sauts de ligne (appui de la touche "entrée").

### Dans les commentaires simple ligne

Le programme suivant fonctionne :

    //une directive include
    #include <iostream>
    
    int main () 
    {
      std::cout << "hello" << std::endl;
    }

Le programme suivant ne compile pas :

    //une directive
    include
    #include <iostream>

    int main ()
    { 
      std::cout << "hello" << std::endl;
    }

En effet, il n'est pas autorisé d'insérer un espace blanc de type "saut de ligne" dans un commentaire simple ligne.

### Dans la directive include

Le programme suivant ne compile pas :

    //une directive include

    #include 
    <iostream>

    int main ()
    { 
      std::cout << "hello" << std::endl;
    }

Il renvoie l'erreur :

    ex.cpp:3:14: error: #include expects "FILENAME" or <FILENAME>

Le programme suivant ne fonctionne pas non plus :

    //une directive include

    #include <
    iostream>

    int main ()
    { 
      std::cout << "hello" << std::endl;
    }

et génère l'erreur suivant :

    ex.cpp:3:15: error: missing terminating > character

En effet, le compilateur attend un caractères "**>**" en fin de ligne !


### Dans une chaine de caractère entourée de double quotes *" la chaine "*

Le programme suivant ne compile pas :

    #include <iostream>

    int main ()
    { 
      std::cout << "hello 
      John" << std::endl;
    }

    ex.cpp:5:20: warning: missing terminating " character

En effet, le programme à besoin de trouver les guillemets fermants la chaîne.

Par contre le programme suivant compile en rajoutant un "**\\**"

    #include <iostream>

    int main ()
    { 
      std::cout << "hello \
      John" << std::endl;
    }

mais le souci est que les espaces permettant l'indentation de la ligne devant "John" sont comptés et rajoutés.

Le programme suivant permet d'éviter le problème :

    #include <iostream>

    int main ()
    { 
      std::cout << "hello" \
      "John" << std::endl;
    }

La différence avec le programme précédent est que l'on a inséré des délimiteurs de type "**"**".
Voici donc une solution pour scinder une chaîne de caractères longue en plusieurs lignes dans le code source.

Mais en voici une plus élégante mieux orientée dans la philosophie du "C++" :

    #include <iostream>

    int main ()
    { 
      std::cout << "hello "
      << "John" 
      << std::endl;
    }

Cette précédente solution est de mon point de vue préférable pour faire du code "propre".
