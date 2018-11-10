## Les commentaires

### Utilité des commentaires dans un programme

Il est important de documenter vos fichiers sources. Le fait de documenter un programme peut vous permettre de vous rappeler dans un futur lointain ce que font vos instructions de programmation. 

Un fait non connu par les développeurs débutants est que certains types de commentaires permettent de créer des documentations de façon automatique grace à des générateurs automatiques. De cette façon, vous générez la documentation des objets (librairies, classes, etc) que vous créez et vous autodocumentez votre projet.

### Les différents types de commentaires

Voici un programme simple dans lequel on a commenté certaines instructions :

    // Un commentaire simple
    
    /* Un commentaire multiligne
    Une deuxième ligne
    Une troisième */
    
    int main () //un commentaire simple en bout de ligne
    { 
      /* On enlève de la compilation l'instruction suivante :
      std::cout << "hello" << endl;
      */
    }

Le programme précédent, une fois les commentaires enlevés par le préprocesseur, se résume au programme suivant :

    int main ()
    { 
    }

Il s'agit du programme minimum en C++ !

I> ## Information
I>Il est important de comprendre que les commentaires vont d'abord être enlevés par le préprocesseur. Le programme débarrassé de ses commentaires sera ensuite transmis au compilateur.

#### Les commentaires simple ligne

En **C++**, le commentaire sur une ligne s'écrit : **//**. Voici un exemple :

    // Voici un commentaire sur une seule ligne

W> ## Avertissement
W> Le fait d'écrire un commentaire simple de type "**//**" sur plusieurs lignes produit une erreur de compilation.
W>
W> La solution consiste bien sûr à mettre "**//**" pour chaque ligne commentée comme ceci :
W>
W> //Une première ligne commentée.
W>
W> //Une deuxième ligne commentée.

On peut aussi mettre un commentaire simple ligne comme ci-dessous :

    #include <iostream> //une directive include

#### Les commentaires multilignes

Une solution plus commode pour écrire des commentaires sur plusieurs lignes consiste à les déclarer avec **/*** au début du texte et ***/** à la fin.

    /* Voici un commentaire
    sur deux lignes
    ou même trois */

T> ##Astuce
T> Cette solution permet d'enlever des morceaux de codes entier de la compilation si par exemple un gros morceau de code ne compile pas.

Voici un exemple de programme qui ne compile pas :

    /* Voici un commentaire
    multiligne /* avec un 
    commentaire imbriqué*/
    Une autre ligne
    */
    int main ()
    { 
      return 0;
    }

Voici l'erreur retournée :

    ex.cpp:2:16: warning: "/*" within comment [-Wcomment]
         multiligne /* avec un
                     
    ex.cpp:4:5: error: ‘Une’ does not name a type
         Une autre ligne
         ^~~

Cette erreur est logique car pour le préprocesseur, le commentaire multiligne se finit après le le "**é**" de "**imbriqué**". Donc quand le compilateur trouve ensuite l'instruction "**Une autre ligne**", il ne comprend pas ("**'Une' does not name a type !**").

W> ##Attention !
W> Les commentaires multilignes imbriqués peuvent provoquer des erreurs.

Voilà pourquoi j'utilise d'abord les commentaires *simple ligne* pour commenter mon code et pourquoi je réserve (sauf exception) les commentaires *multilignes* pour enlever des morceaux entiers de code à des fins de tests.




