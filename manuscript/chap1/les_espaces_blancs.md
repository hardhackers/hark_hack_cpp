## Gestion des espaces blancs

La r�daction des fichiers sources en **C++** est relativement libre. On peut ins�rer des espaces blancs (espaces, tabulations, retours charriots, sauts de ligne etc) sans trop de cons�quences.

Cependant, il y a des insertions � ne pas faire en particulier des sauts de ligne (appui de la touche "entr�e").

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

En effet, il n'est pas autoris� d'ins�rer un espace blanc de type "saut de ligne" dans un commentaire simple ligne.

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

et g�n�re l'erreur suivant :

    ex.cpp:3:15: error: missing terminating > character

En effet, le compilateur attend un caract�res "**>**" en fin de ligne !


### Dans une chaine de caract�re entour�e de double quotes *" la chaine "*

Le programme suivant ne compile pas :

    #include <iostream>

    int main ()
    { 
      std::cout << "hello 
      John" << std::endl;
    }

    ex.cpp:5:20: warning: missing terminating " character

En effet, le programme � besoin de trouver les guillemets fermants la cha�ne.

Par contre le programme suivant compile en rajoutant un "**\\**"

    #include <iostream>

    int main ()
    { 
      std::cout << "hello \
      John" << std::endl;
    }

mais le souci est que les espaces permettant l'indentation de la ligne devant "John" sont compt�s et rajout�s.

Le programme suivant permet d'�viter le probl�me :

    #include <iostream>

    int main ()
    { 
      std::cout << "hello" \
      "John" << std::endl;
    }

La diff�rence avec le programme pr�c�dent est que l'on a ins�r� des d�limiteurs de type "**"**".
Voici donc une solution pour scinder une cha�ne de caract�res longue en plusieurs lignes dans le code source.

Mais en voici une plus �l�gante mieux orient�e dans la philosophie du "C++" :

    #include <iostream>

    int main ()
    { 
      std::cout << "hello "
      << "John" 
      << std::endl;
    }

Cette pr�c�dente solution est de mon point de vue pr�f�rable pour faire du code "propre".
