## Les types r�serv�s pour les caract�res

### Les caract�res simples de type **char**

La premi�re chose � savoir est qu'un type **char** en C++ est encod� au minimum sur 8 bits.

Les 128 premiers caract�res standard d�crits dans la norme **Ascii** permettent d'�crire les caract�res usuels anglais. Les 128 suivants permettent de d'�tendre cette norme � d'autres caract�res fr�quemment utilis�s dans d'autres langues comme les lettres accentu�es du fran�ais.

Pour ces 256 caract�res, le type utilis� est en principe "**char**" appel� aussi "**plain char**". Par exemple le caract�re '**a**', quand il est d�clar�, est automatiquement un "**char**" par d�faut et c'est ce que nous allons v�rifier par le programme suivant :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {
      // Voici le type de char
      std::cout << "Voici le type id de char : " << typeid(char).name() << std::endl;
      // Voici le type de 'a'
      std::cout << "Voici le type id du caract�re 'a' : " << typeid('a').name() << std::endl;
      std::cout << "Voici la taille de char sur cet ordi : " << sizeof(char) << std::endl;
    }

Dans le programme pr�c�dent, la librairie **<iostream>** permet d'utiliser "**cout**" et "**endl**". La librairie **<typeinfo>** permet de donner des informations sur les types utilis�s.

L'op�rateur "**typeid(le_type)**" de la classe "**type_info**" permet de retourner le nom d'un type (quelqu'il soit) avec la fonction "**name()**". La classe "**type_info**" se trouve dans la librairie **<typeinfo>**.

Le type **char** est consid�r� de taille **1**. C'est la raison pour laquelle "**sizeof(char)**" renvoie la valeur **1**. La taille **1** correspond habituellement � un octet (8 bits) autrement dit un **byte**. Sur certains syst�mes, et ceci d�pend du compilateur et de la machine, la taille **1** d'un char correspond � 32 bits ou **1** groupe de 4 octets. On doit donc comprendre que **taille 1** ne veut pas toujours dire **1 octet** selon les syst�mes.

**Attention**, comme la valeur enti�re d'un **char** change selon le syst�me, la transformation d'un **char** en **int** (entier) peut conduire � des bugs ou des r�sultats inattendus. Par exemple si on transforme un entier de valeur **254** en **char**, il est possible que ce 255 se transforme en nombre n�gatif. Sur les syst�mes x86 par exemple, les **char** sont sign�s (ex : -128 � +127) alors que sur processeurs **arm**, les **char** sont non sign�s (ex : 0 � 255).

**Int** �tant un entier, voici un programme int�ressant sur processeur **x_86** ou **x_64** :

    #include <iostream>

    int main ()
    {
      //Je d�clare un entier
      int mon_entier = 254;
      std::cout << "Voici la valeur de l'entier au d�part : " << mon_entier << std::endl;
      
      //Je transforme en char
      char mon_char = mon_entier;

      //Je retransforme en entier
      mon_entier = mon_char;
      std::cout << "Voici l'entier maintenant : " << mon_entier << std::endl;
    }

Comme on peut le voir dans ce programme la transformation d'un **int** converti en **char** donne parfois un **char** n�gatif. Essayer avec diff�rentes valeurs comme 128, 256, 257 pour comprendre ce qui se passe.

D'une fa�on g�n�rale, il n'y a pas de probl�me quand on reste dans l'intervalle 0..127 (essayer). Ceci correspond � l'intervalle des caract�res **Ascii**. Il est donc recommand� de se cantonner � cet intervalle pour �viter des incompatibilit�s.

### Les caract�res char sign�s ou "signed char"

Les caract�res de type **signed char** sont garantis "**sign�s**" et ne sont pas des types fondamentaux. Sur 8 bits, on garantit donc qu'un entier de comme **128** sera converti en nombre n�gatif (ce qui n'est pas garanti pour le cas d'un **char** sur un syst�me arm par exemple).

Essayer le programme suivant :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {
      //Je d�clare un entier
      int mon_entier = 128;
      std::cout << "Voici la valeur de l'entier au d�part : " << mon_entier << std::endl;
      
      //Je transforme en char
      signed char mon_char = mon_entier;

      //Je retransforme en entier
      mon_entier = mon_char;
      std::cout << "Voici l'entier maintenant : " << mon_entier << std::endl;
      std::cout << "Essayer d'autres valeurs dans votre programme : " << mon_entier << std::endl;
      std::cout << "Voici le nom renvoy� par typeinfo : " << typeid( signed char ).name() << std::endl;
    }

**Note** : le **typeinfo** renvoie la lettre "**a**" pour les "**signed char**".

### Les caract�res char non sign�s ou "unsigned char"

Les caract�res de type **unsigned char** sont garantis "**non sign�s**" et ne sont pas des types fondamentaux. Sur 8 bits, on garantit donc qu'un entier de type 128 sera converti en nombre positif (ce qui n'est pas garanti pour le cas d'un **char** sur un syst�me **Arm** par exemple).

Essayer le programme suivant :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {
      //Je d�clare un entier
      int mon_entier = 128;
      std::cout << "Voici la valeur de l'entier au d�part : " << mon_entier << std::endl;
      
      //Je transforme en char
      unsigned char mon_char = mon_entier;

      //Je retransforme en entier
      mon_entier = mon_char;
      std::cout << "Voici l'entier maintenant : " << mon_entier << std::endl;
      std::cout << "Essayer d'autres valeurs dans votre programme : " << mon_entier << std::endl;
      std::cout << "Voici le nom renvoy� par typeinfo : " << typeid( unsigned char ).name() << std::endl;
    }

**Note** : le **typeinfo** renvoie la lettre "**h**" pour les "**unsigned char**".

Que se passe-t-il si on monte l'entier jusqu'� 256, 257 etc ? Eh bien on repart de 0 car le **unsigned char** ne peut pas d�passer 255 et doit rester positif (ceci peut faire penser � une roue qui tourne � l'infini et qui repasse par le point de d�part (0)) !

Le terme anglais pour d�signer une conversion avec "**reduction**" s'appelle le "**narrowing**" et nous en avons d�j� parl� dans la partie sur les types bool�ens.

### Les caract�res �tendus du type "**wchar_t**"

Se limiter aux premiers 127 caract�res est, on le con�oit, tr�s ennuyeux. Si on veut repr�senter des caract�res particuliers comme ceux d'**Unicode**, ou par exemple les caract�res Japonais, il faut donc plus d'espace de stockage. Le type **wchar_t** a donc �t� cr�� pour cela (**wchar** voulant dire **wide char** ou **caract�res �tendus**).

Voici un programme qui utilise les wchar_t :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de wchar_t : " << sizeof(wchar_t) << std::endl;
      std::cout << "Voici le type id de wide char (wchar_t) : " << typeid(wchar_t).name() << std::endl;

    }

Sur mon syst�me x_64, j'obtiens la sortie console suivante :

    Voici la taille de wchar_t : 4
    Voici le type id de wide char (wchar_t) : w

**Note** : le **typeinfo** renvoie la lettre "**h**" pour les **wchar_t**.

### Le type pr�vu pour les caract�res sur 16 bits : char16_t (C++11)

**char16_t** est un type r�serv� pour les caract�res sur 16 bits et permet en particulier de repr�senter le jeux de caract�res **UTF-16** ( un jeu de caract�res �tendus par rapport **ASCII**).

Si char repr�sente la valeur **1** retourn�e par **sizeof**, alors **char16_t** devrait retourner "**2**" (2x8bits = 16). C'est ce que nous allons v�rifier :

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


### Le type pr�vu pour les caract�res sur 32 bits : char32_t (C++11)

**char32_t** est un type r�serv� pour les caract�res sur 32 bits et permet en particulier de repr�senter le jeux de caract�res **UTF-32** (un jeu de caract�res �tendus par rapport **ASCII**).

Si char repr�sente la valeur **1** retourn�e par **sizeof**, alors **char32_t** devrait retourner "**4**" (4x8bits = 32). C'est ce que nous allons v�rifier :

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
I> Ce n'est pas le cas pour **wchar_t**, **char16_t** et **char32_t** qui sont bien des types fondamentaux par eux-m�me et font donc partie des mot-cl�s du C++.

### Les caract�res litt�raux

Un caract�re litt�ral est un simple caract�re entour� de simples apostrophes comme 'z' ou '1'. Comme nous l'avons vu pr�c�demment dans la partie consacr� aux caract�res de type "**char**", les caract�res litt�raux sont automatiquement convertis dans ce type l�.

Dans la table des caract�res ASCII, il est pr�f�rable de d�clarer les caract�res litt�raux sous leur forme entre simple quote comme 'a' plut�t que sous leur forme enti�re ('a' correspond � l'entier 97) et ceci pour des raisons de portabilit� du programme.

Nous avons d�j� vu les caract�res d'�chappements pr�c�d�s par le caract�re **\\**. Il nous reste n�anmoins deux types de caract�res d'�chappement que nous n'avons pas vu : les s�quences d'�chappement de type "Nombre octal" et "Nombre hexad�cimal"

#### Rappel sur les bases de num�ration

Nous utilisons habituellement la base 10. Les unit�s vont de 0 � 9 et on passe forme une dizaine d�s 10 unit�s. C'est une simple fa�on de regrouper des nombres et de les repr�senter. On peut g�n�raliser en disant que si on utilise une base x, les unit�s vont de 0 � x-1 et on commence � faire un groupe � partir de x.

Par exemple en binaire (base 2), les unit�s sont **0** et **1** et on commence � faire un groupe � partir de 2, ce que l'on pourrait appeler une "deuzaine" (ce terme n'est pas usit�). Donc en base deux par exemple, on a **0**, **1** pour les unit�s puis on passe ensuite � **10** (une deuzaine et 0 unit�s) correspondant � **2** en base dix, puis on a **11** (une deuzaine et 1 unit�) et ainsi de suite.

#### Les s�quences de type "Nombre octal"

Un nombre octal se r�pr�sente sous la forme **\\o** ou **\\oo** ou **\\ooo** ou **o** est un chiffre en base 8 (de 0 � 7). Les unit�s en octal vont de 0 � 7 et ensuite on passe � la "huitaine". Par exemple **\\11** nous donne une huitaine et une unit� soit **9** en base 10. **\\100** nous donne huit huitaines soit le nombre 64 en base 10 (8x8).

Donc \\777 correspond � 7x64 + 7x8 + 7 soit \\1000 moins 1 soit 511.

Donc pour notre caract�re **'a'**, il peut s'�crire **97** en base 10 ou \\141 (1x64 + 4x8 + 1)

Voici donc un programme pour �crire un 'a' :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici le char \'\141\' ou 97 en base 10 ou \\141 en octal !" << std::endl;
    }

Il faut tout de m�me constater que **\'** permet de faire sortir les apostrophes **'** autour du **'a'** et que \\\\ permet d'�crire le double antislash.

Comme je l'ai pr�cis�, on ne peut �crire que qu'un nombre de type **\\ooo**, ce qui veut dire que le caract�re suivant (un **1**) dans l'exemple ci-dessous est �crit normalement :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici la cha�ne \'\1411\' ou \'a1\'!" << std::endl;
    }

On obtient donc "a1" avec \\1411. Il faut bien ma�triser les r�gles donc !

D'autre part, si on rencontre un caract�re non octal (comme **8**), la cha�ne octale est interrompue :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici la cha�ne \'\778\' ou \'?8\'!" << std::endl;
    }

On voit donc que l'on retrouve une cha�ne "normale" apr�s le **77** car **8** n'est pas un caract�re octal (il ne fait pas partie de l'intervalle **0** � **7**).

Un petit amusement consiste � repr�senter un caract�re ASCII non visible comme espace (\\040 en octal et 32 en d�cimal) :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici deux espaces : \'\040\040\' ou \'  \' ! Amusant, non \77" << std::endl;
    }

Contrairement aux apparences des s�quences telles que \\77 ne r�pr�sente qu'un caract�re litt�ral (ici un espace).

I> ## Note importante
I> 
I> Si on veut rester dans l'intervalle des caract�res ASCII pour des raisons de portabilit� du programme, il faudra ne pas d�passer le caract�re \\177 (127 en d�cimal).

#### Les s�quences de type "Nombre hexad�cimal"

Un nombre octal se r�pr�sente sous la forme **\\xh** ou **\\xhh** ou **\\uhhhh** ou **\\U0000hhhh** ou **h"" est un chiffre en base 16 (de 0 � f). Les unit�s en hexad�cimal vont de 0 � 7 et de a � f. Apr�s le **f** on passe � la "seizaine" (16 en base 10). Par exemple **\\xf2** nous donne une 15 seizaines et deux unit�s (15*16 + 2) soit **242** en base 10. **\\x100** nous donne 16x16 (16 puissance 2) soit le nombre 256 en base 10.

Un convertisseur en ligne : <https://www.rapidtables.com/convert/number/base-converter.html> permet de faire le travail plus rapidement mais le cerveau, une fois habitu� � ces conversions peut aussi faire rapidement le travail. Ce n�c�ssite de l'entra�nement bien s�r.

Les caract�res hexad�cimaux permettent d'�tendre les caract�res ASCII pour repr�senter des caract�res UNICODE par exemple. 

Quand on r�pr�sente des caract�res ASCII, on peut les repr�senter sous la forme \\xh ou \\xhh

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici un caract�re de ASCII de tabulation : \'\x9\' ou \'\x09\'" << std::endl;
    } 

Pour repr�senter un caract�re Unicode, on peut le repr�senter sous la forme courte \\uhhhh ou longue \\U0000hhhh :

    #include <iostream>
    
    int main()
    {
      // Voici des caract�res Japonais
      std::cout << "Voici deux caract�res unicode : \'\u8888\' ou \'\U00008889\' " << std::endl;
      // Voic des caract�res inaffichables sur ma console
      std::cout << "En voici deux autres : \'\uabcd\' ou \'\U0000ffff\' "<< std::endl;
    } 

Pour les caract�res que votre console n'arrive pas � repr�senter, il y a en g�n�ral affichage d'un carr� avec les lettres de votre caract�re unicode dedans. On peut indiff�remment �crire des majuscules ou des minuscules \'uabcd\' ou \'uABCD\'.

Certains intervalles de caract�res produisent des erreurs :

    #include <iostream>
    
    int main()
    {
      std::cout << "Voici un caract�re qui ne passe pas : \'\udead\' " << std::endl;
    } 

Voici la sortie d'erreur qui en r�sulte :

    ex.cpp:5:20: error: \udead is not a valid universal character


### R�sum� des types caract�res (tableau)

Voici donc le tableau r�sumant les types de caract�res :

{title="Les types caract�res"}
| Nom du type   |                         Description                               | Fondamentaux |
|---------------|-------------------------------------------------------------------|--------------|
|   char        | Surtout utilis� pour repr�senter les caract�res de la norme ASCII |     Oui      |
|   wchar_t     | Utilis� pour �tendre le jeu des caract�res de type char           |     Oui      |
|   char16_t    | Jeu de caract�res sur 16 bits                                     |     Oui      |
|   char32_t    | Jeu de caract�res sur 32 bits                                     |     Oui      |
| unsigned char | char non sign� (correspond � un entier positif)                   |     Non      |
|  signed char  | char sign� (correspond � un entier positif ou n�gatif)            |     Non      |
