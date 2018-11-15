## Les types

Il existe en C++ deux catégories de donnée, les types **fondamentaux** ou "**built-in**" ou "**core**" qui appartiennent au coeur du langage et les types qui sont en dehors et qui sont déclarés dans des bibliothèques comme la bibliothèque standard ou une bibliothèque tierce.

Par exemple, le type d'un caractère "**char**" est "**core**" alors que le type d'un flux "**cout**" ne l'est pas.

{title="Les types fondamentaux du C++"}

|Nom du type|                         Description                               |
|-----------|-------------------------------------------------------------------|
|   bool    | Utilisé pour représenter des entités à deux états                 |
|   char    | Surtout utilisé pour représenter les caractères de la norme ASCII |
|   wchar_t | Utilisé pour étendre le jeu des caractères de type char           |
|   char16_t| Jeu de caractères sur 16 bits                                     |
|   char32_t| Jeu de caractères sur 32 bits                                     |



### Obtenir les infos sur un type donné

La librairie <typeinfo> permet d'obtenir des informations sur les types de données utilisées dans un programme. L'utilisation est décrite dans le paragraphe suivant.

### Le type booléen

Le type booléen peut avoir deux valeurs : vrai ou faux. Il est utile pour représenter des éléments de la vie réelle ayant deux états, par exemple une barrière de passage à niveau : ouverte ou fermée.

L'initialisation de ce type (nous reviendrons sur la notion d'initialisation après) peut être le résultat d'une expression logique. Voici un petit programme qui permet de comprendre :

    #include <iostream>
    
    int main ()
    {
      int x = 20;
      int y = 30;
      //on teste si x est égal à y et on affecte la valeur du test à "mon_bool"
      bool mon_bool = ( x == y );
      std::cout << "Voici la valeur du booléen : " << mon_bool << std::endl;
      y = 20;
      //on teste à nouveau
      mon_bool = ( x == y);
      std::cout << "Voici la nouvelle valeur : " << mon_bool << std::endl;
      y = 40;
      mon_bool = ( x < y );
      std::cout << "Voici le résultat : " << mon_bool << std::endl;
      mon_bool = ( x > y );
      std::cout << "Voici le résultat 4 : " << mon_bool << std::endl;
    }

Il est intéressant de voir comment les entiers sont convertis en boolean. Si un entier est différent de 0, il est converti en "true" (1). Sinon, il est converti en "false" (0). Ce petit programme le montre :

    #include <iostream>
    
    int main ()
    {
      int x = 3;
      int y = -1;
      int z = 0;
      bool mon_bool = x;
      std::cout << "Voici le résultat pour un entier positif comme x = 3 : " << mon_bool << std::endl;
      mon_bool = y;
      std::cout << "Voici le résultat pour un entier négatif comme y = -1 : " << mon_bool << std::endl;
      mon_bool = z;
      std::cout << "Voici le résultat pour entier nul comme z = 0 : " << mon_bool << std::endl;
    }

Pour le programme si dessus, on effectue une conversion d'un entier vers un booléen avec réduction. Par exemple, le "**3**" devient un "**0**". On appelle ce processus de réduction du "narrowing" (réduction). Comme on s'en doute le fait de "réduire" un nombre peut amener des conséquences inattendues et des bugs.

Il est bien sûr possible de déclarer des valeurs booléennes directement avec **true** ou **false** :

    #include <iostream>
    
    int main ()
    {
      bool mon_bool_vrai = true;
      std::cout << "Voici le résultat pour un bool true : " << mon_bool_vrai << std::endl;
      bool mon_bool_faux = false;
      std::cout << "Voici le résultat pour un bool faux : " << mon_bool_faux << std::endl;
      int mon_entier_vrai = true;
      std::cout << "Voici le résultat pour un entier vrai : " << mon_entier_vrai << std::endl;
      int mon_entier_faux = false;
      std::cout << "Voici le résultat pour un entier faux : " << mon_entier_faux << std::endl;
    }

Comme on peut le constater, ça fonctionne aussi avec des entiers mis à "**true**" ou "**false**"!! (Je n'ai lu ça dans aucun livre mais ce petit hack a fonctionné pour moi sans erreur de compilation, comme quoi il faut expérimenter).

### Les types réservés pour les caractères

#### Les caractères simples de type **char**

La première chose à savoir est qu'un char en C++ est encodé au minimum, sur 8 bits.

Les 128 premiers caractères standard décrits dans la norme **Ascii** permettent d'écrire les caractères usuels anglais. Les 128 suivants permettent de d'étendre cette norme à d'autres caractères fréquemment utilisés dans d'autres langues comme les lettres accentuées du français.

Pour ces 256 caractères, le type utilisé est en principe "**char**" appelé aussi "**plain char**". Par exemple le caractère '**a**', quand il est déclaré, est automatiquement un "**char**" par défaut et c'est ce que nous allons vérifier par le programme suivant :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {
      // Voici le type de char
      std::cout << "Voici le type id de char : " << typeid(char).name() << std::endl;
      // Voici le type de 'a'
      std::cout << "Voici le type id du caractère 'a' : " << typeid('a').name() << std::endl;
      std::cout << "Voici la taille de char sur cet ordi : " << sizeof(char) << std::endl;
    }

Dans le programme précédent, la librairie **<iostream>** permet d'utiliser "**cout**" et "**endl**". La librairie **<typeinfo>** permet de donner des informations sur les types utilisés.

L'opérateur "**typeid(le_type)**" de la classe "**type_info**" permet de retourner le nom d'un type (quelqu'il soit) avec la fonction "**name()**". La classe "**type_info**" se trouve dans la librairie <typeinfo>.

Le type **char** est considéré de taille **1**. C'est la raison pour laquelle "**sizeof(char)**" renvoie la valeur **1**. La taille **1** correspond habituellement à un octet (8 bits) autrement dit un **byte**. Sur certains systèmes, et ceci dépend du compilateur et de la machine, la taille **1** d'un char correspond à 32 bits ou **1** groupe de 4 octets. On doit donc comprendre que **taille 1** ne veut pas toujours dire **1 octet** selon les systèmes.

**Attention**, comme la valeur entière d'un **char** change selon le système, la transformation d'un **char** en **int** (entier) peut conduire à des bugs ou des résultats inattendus. Par exemple si on transforme un entier de valeur **254** en **char**, il est possible que ce 255 se transforme en nombre négatif. Sur les systèmes x86 par exemple, les **char** sont signés (ex : -128 à +127) alors que sur processeurs **arm**, les **char** sont non signés (ex : 0 à 255).

Int étant un entier, voici un programme intéressant sur processeur x_86 ou x_64 :

    #include <iostream>

    int main ()
    {
      //Je déclare un entier
      int mon_entier = 254;
      std::cout << "Voici la valeur de l'entier au départ : " << mon_entier << std::endl;
      
      //Je transforme en char
      char mon_char = mon_entier;

      //Je retransforme en entier
      mon_entier = mon_char;
      std::cout << "Voici l'entier maintenant : " << mon_entier << std::endl;
    }

Comme on peut le voir dans ce programme la transformation d'un **int** converti en **char** donne parfois un **char** négatif. Essayer avec différentes valeurs comme 128, 256, 257 pour comprendre ce qui se passe.

D'une façon générale, il n'y a pas de problème quand on reste dans l'intervalle 0..127 (essayer). Ceci correspond à l'intervalle des caractères **Ascii**. Il est donc recommandé de se cantonner à cet intervalle pour éviter des incompatibilités.

#### Les caractères char signés ou **signed char**

Les caractères de type **signed char** sont garantis "**signés**". Sur 8bit, on garantit donc qu'un entier de comme **128* sera converti en nombre négatif (ce qui n'est pas garanti pour le cas d'un **char** sur un système arm par exemple).

Essayer le programme suivant :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {
      //Je déclare un entier
      int mon_entier = 128;
      std::cout << "Voici la valeur de l'entier au départ : " << mon_entier << std::endl;
      
      //Je transforme en char
      signed char mon_char = mon_entier;

      //Je retransforme en entier
      mon_entier = mon_char;
      std::cout << "Voici l'entier maintenant : " << mon_entier << std::endl;
      std::cout << "Essayer d'autres valeurs dans votre programme : " << mon_entier << std::endl;
      std::cout << "Voici le nom renvoyé par typeinfo : " << typeid( signed char ).name() << std::endl;
    }

**Note** : le **typeinfo** renvoie la lettre "**a**" pour les "**signed char**".

#### Les caractères char non signés ou "unsigned char"

Les caractères de type **unsigned char** sont garantis "**non signés**". Sur 8bit, on garantit donc qu'un entier de type 128 sera converti en nombre positif (ce qui n'est pas garanti pour le cas d'un **char** sur un système **Arm** par exemple).

Essayer le programme suivant :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {
      //Je déclare un entier
      int mon_entier = 128;
      std::cout << "Voici la valeur de l'entier au départ : " << mon_entier << std::endl;
      
      //Je transforme en char
      unsigned char mon_char = mon_entier;

      //Je retransforme en entier
      mon_entier = mon_char;
      std::cout << "Voici l'entier maintenant : " << mon_entier << std::endl;
      std::cout << "Essayer d'autres valeurs dans votre programme : " << mon_entier << std::endl;
      std::cout << "Voici le nom renvoyé par typeinfo : " << typeid( unsigned char ).name() << std::endl;
    }

**Note** : le **typeinfo** renvoie la lettre "**h**" pour les "**unsigned char**".

Que se passe-t-il si on monte l'entier jusqu'à 256, 257 etc ? Eh bien on repart de 0 car le **unsigned char** ne peut pas dépasser 255 et doit rester positif (ceci peut faire penser à une roue qui tourne à l'infini et qui repasse par le point de départ (0)) !

Le terme anglais pour désigner une conversion avec "**reduction**" s'appelle le "**narrowing**" et peut comme on l'a montré produire des résultats inattendus ou difficiles à comprendre.

#### Les caractères étendus du type "**wchar_t**"

Se limiter aux premiers 127 caractères est, on le conçoit, très ennuyeux. Si on veut représenter des caractères particuliers comme ceux d'**Unicode**, ou par exemple les caractères Japonais, il faut donc plus d'espace de stockage. Le type **wchar_t** a donc été créé pour cela (**wchar** voulant dire **wide char** ou **caractères étendus**).

Voici un programme qui utilise les wchar_t :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de wchar_t : " << sizeof(wchar_t) << std::endl;
      std::cout << "Voici le type id de wide char (wchar_t) : " << typeid(wchar_t).name() << std::endl;

    }

Sur mon système x_64, j'obtiens la sortie console suivante :

    Voici la taille de wchar_t : 4
    Voici le type id de wide char (wchar_t) : w

**Note** : le **typeinfo** renvoie la lettre "**h**" pour les **wchar_t**.

#### Le type prévu pour les caractères sur 16 bits : char16_t (C++11)

char16_t est un type réservé pour les caractères sur 16 bits et permet en particulier de représenter le jeux de caractères UTF-16 qui est un jeu de caractères étendus par rapport ASCII.

Si char représente la valeur 1 retournée par **sizeof**, alors **char16_t** devrait retourner "**2**" (2x8bits = 16). C'est ce que nous allons vérifier :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de char16_t : " << sizeof(char16_t) << std::endl;
      std::cout << "Voici le type id de char16_t : " << typeid(char16_t).name() << std::endl;

    }

**Note** : le **typeinfo** renvoie les lettres "**Ds**" pour les **char16_t**.


#### Le type prévu pour les caractères sur 32 bits : char32_t (C++11)

char32_t est un type réservé pour les caractères sur 32 bits et permet en particulier de représenter le jeux de caractères UTF-32 qui est un jeu de caractères étendus par rapport ASCII.

Si char représente la valeur 1 retournée par **sizeof**, alors **char32_t** devrait retourner "**4**" (4x8bits = 32). C'est ce que nous allons vérifier :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de char32_t : " << sizeof(char32_t) << std::endl;
      std::cout << "Voici le type id de char32_t : " << typeid(char32_t).name() << std::endl;

    }

**Note** : le **typeinfo** renvoie les lettres "**Di**" pour les **char32_t**.

I> Remarque inportante
I> On peut remarque que les types du style **xxxx_t** sont souvent des alias de types fondamentaux. 
I> Ce n'est pas le cas pour **wchar_t**, **char16_t** et **char32_t** qui sont bien des types fondamentaux par eux-même et font donc partie des mot-clés du C++.

#### Résumé des types caractères (tableau)

A faire

#### L
