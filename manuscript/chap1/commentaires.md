## Les commentaires

### Utilité des commentaires dans un programme

Il est important de documenter vos fichiers sources. Le fait de documenter un programme peut vous permettre de vous rappeler dans un futur lointain ce que font vos instructions de programmation. 

Un fait non connu par les développeurs débutants est que certains types de commentaires permettent de créer des documentations de façon automatique grace à des générateurs automatiques. De cette façon vous générez la documentation des objets (librairies, classes, etc) que vous créez et vous autodocumentez votre projet.

### Les différents types de commentaires

En **C++**, le commentaire sur une ligne s'écrit : **//**. Voici un exemple :

    // Voici un commentaire sur une seule ligne

Les commentaires sur plusieurs lignes sont déclarés avec **/*** au début du texte à commenter et ***/** à la fin.

    /* Voici un commentaire
    sur deux lignes
    ou même trois */

Il est important de comprendre que les commentaires vont d'abord être enlevés par le préprocesseur. Le programme débarrassé de ses commentaires sera ensuite transmis au compilateur.

### Programme de base avec des commentaires

Voici un programme simple dans lequel on a commenté certaines instructions qui donc ne seront plus exécutées :
    
    // C'est un commentaire d'une ligne
    /* C'est un commentaire de plusieurs lignes,
    par exemple la ligne 1,
    puis la ligne 2 */
    
    //La ligne suivante a été mise en commentaire
    //#include <iostream>

    int main(){
    //Celle-ci aussi
    //std::cout << "Hello, world!" << std::endl;
    return 0;
    }

Le programme au dessus peut finalement être résumé au programme minimum en C++ suivant

    int main(){
      return 0;
    }



