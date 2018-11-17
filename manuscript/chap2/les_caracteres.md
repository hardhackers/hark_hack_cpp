## Les types réservés pour les caractères

### Les caractères simples de type **char**

La première chose à savoir est qu'un type **char** en C++ est encodé au minimum sur 8 bits.

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

L'opérateur "**typeid(le_type)**" de la classe "**type_info**" permet de retourner le nom d'un type (quelqu'il soit) avec la fonction "**name()**". La classe "**type_info**" se trouve dans la librairie **<typeinfo>**.

Le type **char** est considéré de taille **1**. C'est la raison pour laquelle "**sizeof(char)**" renvoie la valeur **1**. La taille **1** correspond habituellement à un octet (8 bits) autrement dit un **byte**. Sur certains systèmes, et ceci dépend du compilateur et de la machine, la taille **1** d'un char correspond à 32 bits ou **1** groupe de 4 octets. On doit donc comprendre que **taille 1** ne veut pas toujours dire **1 octet** selon les systèmes.

**Attention**, comme la valeur entière d'un **char** change selon le système, la transformation d'un **char** en **int** (entier) peut conduire à des bugs ou des résultats inattendus. Par exemple si on transforme un entier de valeur **254** en **char**, il est possible que ce 255 se transforme en nombre négatif. Sur les systèmes x86 par exemple, les **char** sont signés (ex : -128 à +127) alors que sur processeurs **arm**, les **char** sont non signés (ex : 0 à 255).

**Int** étant un entier, voici un programme intéressant sur processeur **x_86** ou **x_64** :

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

### Les caractères char signés ou "signed char"

Les caractères de type **signed char** sont garantis "**signés**" et ne sont pas des types fondamentaux. Sur 8 bits, on garantit donc qu'un entier de comme **128** sera converti en nombre négatif (ce qui n'est pas garanti pour le cas d'un **char** sur un système arm par exemple).

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

### Les caractères char non signés ou "unsigned char"

Les caractères de type **unsigned char** sont garantis "**non signés**" et ne sont pas des types fondamentaux. Sur 8 bits, on garantit donc qu'un entier de type 128 sera converti en nombre positif (ce qui n'est pas garanti pour le cas d'un **char** sur un système **Arm** par exemple).

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

Le terme anglais pour désigner une conversion avec "**reduction**" s'appelle le "**narrowing**" et nous en avons déjà parlé dans la partie sur les types booléens.

### Les caractères étendus du type "**wchar_t**"

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

### Le type prévu pour les caractères sur 16 bits : char16_t (C++11)

**char16_t** est un type réservé pour les caractères sur 16 bits et permet en particulier de représenter le jeux de caractères **UTF-16** ( un jeu de caractères étendus par rapport **ASCII**).

Si char représente la valeur **1** retournée par **sizeof**, alors **char16_t** devrait retourner "**2**" (2x8bits = 16). C'est ce que nous allons vérifier :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de char16_t : " << sizeof(char16_t) << std::endl;
      std::cout << "Voici le type id de char16_t : " << typeid(char16_t).name() << std::endl;

    }

Voici la sortie console de ce programme :

    Voici la taille de char16_t : 2
    Voici le type id de char16_t : Ds

**Note** : le **typeinfo** renvoie les lettres "**Ds**" pour les **char16_t**.


### Le type prévu pour les caractères sur 32 bits : char32_t (C++11)

**char32_t** est un type réservé pour les caractères sur 32 bits et permet en particulier de représenter le jeux de caractères **UTF-32** (un jeu de caractères étendus par rapport **ASCII**).

Si char représente la valeur **1** retournée par **sizeof**, alors **char32_t** devrait retourner "**4**" (4x8bits = 32). C'est ce que nous allons vérifier :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de char32_t : " << sizeof(char32_t) << std::endl;
      std::cout << "Voici le type id de char32_t : " << typeid(char32_t).name() << std::endl;

    }

Voici la sortie console de ce programme :

    Voici la taille de char32_t : 4
    Voici le type id de char32_t : Di


**Note** : le **typeinfo** renvoie les lettres "**Di**" pour les **char32_t**.

I> ## Remarque inportante
I>
I> On peut remarque que les types du style **xxxx_t** sont souvent des alias de types fondamentaux. 
I> Ce n'est pas le cas pour **wchar_t**, **char16_t** et **char32_t** qui sont bien des types fondamentaux par eux-même et font donc partie des mot-clés du C++.

### Les caractères littéraux

Un caractère littéral est un simple caractère entouré de simples apostrophes comme 'z' ou '1'. Comme nous l'avons vu précédemment dans la partie consacré aux caractères de type "**char**", les caractères littéraux sont automatiquement convertis dans ce type là.

Dans la table des caractères ASCII, il est préférable de déclarer les caractères littéraux sous leur forme entre simple quote comme 'a' plutôt que sous leur forme entière ('a' correspond à l'entier 97) et ceci pour des raisons de portabilité du programme.

Nous avons déjà vu les caractères d'échappements précédés par le caractère **\\**. Il nous reste néanmoins deux types de caractères d'échappement que nous n'avons pas vu : les séquences d'échappement de type "Nombre octal" et "Nombre hexadécimal"

#### Rappel sur les bases de numération

Nous utilisons habituellement la base 10. Les unités vont de 0 à 9 et on passe forme une dizaine dès 10 unités. C'est une simple façon de regrouper des nombres et de les représenter. On peut généraliser en disant que si on utilise une base x, les unités vont de 0 à x-1 et on commence à faire un groupe à partir de x.

Par exemple en binaire (base 2), les unités sont **0** et **1** et on commence à faire un groupe à partir de 2, ce que l'on pourrait appeler une "deuzaine" (ce terme n'est pas usité). Donc en base deux par exemple, on a **0**, **1** pour les unités puis on passe ensuite à **10** (une deuzaine et 0 unités) correspondant à **2** en base dix, puis on a **11** (une deuzaine et 1 unité) et ainsi de suite.

#### Les séquences de type "Nombre octal"

Un nombre octal se réprésente sous la forme **\\o** ou **\\oo** ou **\\ooo** ou **o** est un chiffre en base 8 (de 0 à 7). Les unités en octal vont de 0 à 7 et ensuite on passe à la "huitaine". Par exemple **\\11** nous donne une huitaine et une unité soit **9** en base 10. **\\100** nous donne huit huitaines soit le nombre 64 en base 10 (8x8).

Donc \\777 correspond à 7x64 + 7x8 + 7 soit \\1000 moins 1 soit 511.

Donc pour notre caractère **'a'**, il peut s'écrire **97** en base 10 ou \\141 (1x64 + 4x8 + 1)

Voici donc un programme pour écrire un 'a' :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici le char \'\141\' ou 97 en base 10 ou \\141 en octal !" << std::endl;
    }

Il faut tout de même constater que **\'** permet de faire sortir les apostrophes **'** autour du **'a'** et que \\\\ permet d'écrire le double antislash.

Comme je l'ai précisé, on ne peut écrire que qu'un nombre de type **\\ooo**, ce qui veut dire que le caractère suivant (un **1**) dans l'exemple ci-dessous est écrit normalement :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici la chaîne \'\1411\' ou \'a1\'!" << std::endl;
    }

On obtient donc "a1" avec \\1411. Il faut bien maîtriser les règles donc !

D'autre part, si on rencontre un caractère non octal (comme **8**), la chaîne octale est interrompue :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici la chaîne \'\778\' ou \'?8\'!" << std::endl;
    }

On voit donc que l'on retrouve une chaîne "normale" après le **77** car **8** n'est pas un caractère octal (il ne fait pas partie de l'intervalle **0** à **7**).

Un petit amusement consiste à représenter un caractère ASCII non visible comme espace (\\040 en octal et 32 en décimal) :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici deux espaces : \'\040\040\' ou \'  \' ! Amusant, non \77" << std::endl;
    }

Contrairement aux apparences des séquences telles que \\77 ne réprésente qu'un caractère littéral (ici un espace).

I> ## Note importante
I> 
I> Si on veut rester dans l'intervalle des caractères ASCII pour des raisons de portabilité du programme, il faudra ne pas dépasser le caractère \\177 (127 en décimal).

#### Les séquences de type "Nombre hexadécimal"

Un nombre octal se réprésente sous la forme **\\xh** ou **\\xhh** ou **\\uhhhh** ou **\\U0000hhhh** ou **h"" est un chiffre en base 16 (de 0 à f). Les unités en hexadécimal vont de 0 à 7 et de a à f. Après le **f** on passe à la "seizaine" (16 en base 10). Par exemple **\\xf2** nous donne une 15 seizaines et deux unités (15*16 + 2) soit **242** en base 10. **\\x100** nous donne 16x16 (16 puissance 2) soit le nombre 256 en base 10.

Un convertisseur en ligne : <https://www.rapidtables.com/convert/number/base-converter.html> permet de faire le travail plus rapidement mais le cerveau, une fois habitué à ces conversions peut aussi faire rapidement le travail. Ce nécéssite de l'entraînement bien sûr.

Les caractères hexadécimaux permettent d'étendre les caractères ASCII pour représenter des caractères UNICODE par exemple. 

Quand on réprésente des caractères ASCII, on peut les représenter sous la forme \\xh ou \\xhh

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici un caractère de ASCII de tabulation : \'\x9\' ou \'\x09\'" << std::endl;
    } 

Pour représenter un caractère Unicode, on peut le représenter sous la forme courte \\uhhhh ou longue \\U0000hhhh :

    #include <iostream>
    
    int main()
    {
      // Voici des caractères Japonais
      std::cout << "Voici deux caractères unicode : \'\u8888\' ou \'\U00008889\' " << std::endl;
      // Voic des caractères inaffichables sur ma console
      std::cout << "En voici deux autres : \'\uabcd\' ou \'\U0000ffff\' "<< std::endl;
    } 

Pour les caractères que votre console n'arrive pas à représenter, il y a en général affichage d'un carré avec les lettres de votre caractère unicode dedans. On peut indifféremment écrire des majuscules ou des minuscules \'uabcd\' ou \'uABCD\'.

Certains intervalles de caractères produisent des erreurs :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici un caractère qui ne passe pas : \'\udead\' " << std::endl;
    } 

Voici la sortie d'erreur qui en résulte :

    ex.cpp:5:20: error: \udead is not a valid universal character


### Résumé des types caractères (tableau)

Voici donc le tableau résumant les types de caractères :

{title="Les types caractères"}
| Nom du type   |                         Description                               | Fondamentaux |
|---------------|-------------------------------------------------------------------|--------------|
|   char        | Surtout utilisé pour représenter les caractères de la norme ASCII |     Oui      |
|   wchar_t     | Utilisé pour étendre le jeu des caractères de type char           |     Oui      |
|   char16_t    | Jeu de caractères sur 16 bits                                     |     Oui      |
|   char32_t    | Jeu de caractères sur 32 bits                                     |     Oui      |
| unsigned char | char non signé (correspond à un entier positif)                   |     Non      |
|  signed char  | char signé (correspond à un entier positif ou négatif)            |     Non      |
