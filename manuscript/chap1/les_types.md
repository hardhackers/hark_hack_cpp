## Les types

Il existe en C++ deux cat�gories de donn�e, les types **fondamentaux** ou "**built-in**" ou "**core**" qui appartiennent au coeur du langage et les types qui sont en dehors et qui sont d�clar�s dans des biblioth�ques comme la biblioth�que standard ou une biblioth�que tierce.

Par exemple, le type d'un caract�re "**char**" est "**core**" alors que le type d'un flux "**cout**" ne l'est pas.

{title="Les types fondamentaux du C++"}

|Nom du type|                         Description                               |
|-----------|-------------------------------------------------------------------|
|   bool    | Utilis� pour repr�senter des entit�s � deux �tats                 |
|   char    | Surtout utilis� pour repr�senter les caract�res de la norme ASCII |
|   wchar_t | Utilis� pour �tendre le jeu des caract�res de type char           |
|   char16_t| Jeu de caract�res sur 16 bits                                     |
|   char32_t| Jeu de caract�res sur 32 bits                                     |



### Obtenir les infos sur un type donn�

La librairie <typeinfo> permet d'obtenir des informations sur les types de donn�es utilis�es dans un programme. L'utilisation est d�crite dans le paragraphe suivant.

### Le type bool�en

Le type bool�en peut avoir deux valeurs : vrai ou faux. Il est utile pour repr�senter des �l�ments de la vie r�elle ayant deux �tats, par exemple une barri�re de passage � niveau : ouverte ou ferm�e.

L'initialisation de ce type (nous reviendrons sur la notion d'initialisation apr�s) peut �tre le r�sultat d'une expression logique. Voici un petit programme qui permet de comprendre :

    #include <iostream>
    
    int main ()
    {
      int x = 20;
      int y = 30;
      //on teste si x est �gal � y et on affecte la valeur du test � "mon_bool"
      bool mon_bool = ( x == y );
      std::cout << "Voici la valeur du bool�en : " << mon_bool << std::endl;
      y = 20;
      //on teste � nouveau
      mon_bool = ( x == y);
      std::cout << "Voici la nouvelle valeur : " << mon_bool << std::endl;
      y = 40;
      mon_bool = ( x < y );
      std::cout << "Voici le r�sultat : " << mon_bool << std::endl;
      mon_bool = ( x > y );
      std::cout << "Voici le r�sultat 4 : " << mon_bool << std::endl;
    }

Il est int�ressant de voir comment les entiers sont convertis en boolean. Si un entier est diff�rent de 0, il est converti en "true" (1). Sinon, il est converti en "false" (0). Ce petit programme le montre :

    #include <iostream>
    
    int main ()
    {
      int x = 3;
      int y = -1;
      int z = 0;
      bool mon_bool = x;
      std::cout << "Voici le r�sultat pour un entier positif comme x = 3 : " << mon_bool << std::endl;
      mon_bool = y;
      std::cout << "Voici le r�sultat pour un entier n�gatif comme y = -1 : " << mon_bool << std::endl;
      mon_bool = z;
      std::cout << "Voici le r�sultat pour entier nul comme z = 0 : " << mon_bool << std::endl;
    }

Pour le programme si dessus, on effectue une conversion d'un entier vers un bool�en avec r�duction. Par exemple, le "**3**" devient un "**0**". On appelle ce processus de r�duction du "narrowing" (r�duction). Comme on s'en doute le fait de "r�duire" un nombre peut amener des cons�quences inattendues et des bugs.

Il est bien s�r possible de d�clarer des valeurs bool�ennes directement avec **true** ou **false** :

    #include <iostream>
    
    int main ()
    {
      bool mon_bool_vrai = true;
      std::cout << "Voici le r�sultat pour un bool true : " << mon_bool_vrai << std::endl;
      bool mon_bool_faux = false;
      std::cout << "Voici le r�sultat pour un bool faux : " << mon_bool_faux << std::endl;
      int mon_entier_vrai = true;
      std::cout << "Voici le r�sultat pour un entier vrai : " << mon_entier_vrai << std::endl;
      int mon_entier_faux = false;
      std::cout << "Voici le r�sultat pour un entier faux : " << mon_entier_faux << std::endl;
    }

Comme on peut le constater, �a fonctionne aussi avec des entiers mis � "**true**" ou "**false**"!! (Je n'ai lu �a dans aucun livre mais ce petit hack a fonctionn� pour moi sans erreur de compilation, comme quoi il faut exp�rimenter).

### Les types r�serv�s pour les caract�res

#### Les caract�res simples de type **char**

La premi�re chose � savoir est qu'un char en C++ est encod� au minimum, sur 8 bits.

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

L'op�rateur "**typeid(le_type)**" de la classe "**type_info**" permet de retourner le nom d'un type (quelqu'il soit) avec la fonction "**name()**". La classe "**type_info**" se trouve dans la librairie <typeinfo>.

Le type **char** est consid�r� de taille **1**. C'est la raison pour laquelle "**sizeof(char)**" renvoie la valeur **1**. La taille **1** correspond habituellement � un octet (8 bits) autrement dit un **byte**. Sur certains syst�mes, et ceci d�pend du compilateur et de la machine, la taille **1** d'un char correspond � 32 bits ou **1** groupe de 4 octets. On doit donc comprendre que **taille 1** ne veut pas toujours dire **1 octet** selon les syst�mes.

**Attention**, comme la valeur enti�re d'un **char** change selon le syst�me, la transformation d'un **char** en **int** (entier) peut conduire � des bugs ou des r�sultats inattendus. Par exemple si on transforme un entier de valeur **254** en **char**, il est possible que ce 255 se transforme en nombre n�gatif. Sur les syst�mes x86 par exemple, les **char** sont sign�s (ex : -128 � +127) alors que sur processeurs **arm**, les **char** sont non sign�s (ex : 0 � 255).

Int �tant un entier, voici un programme int�ressant sur processeur x_86 ou x_64 :

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

#### Les caract�res char sign�s ou **signed char**

Les caract�res de type **signed char** sont garantis "**sign�s**". Sur 8bit, on garantit donc qu'un entier de comme **128* sera converti en nombre n�gatif (ce qui n'est pas garanti pour le cas d'un **char** sur un syst�me arm par exemple).

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

#### Les caract�res char non sign�s ou "unsigned char"

Les caract�res de type **unsigned char** sont garantis "**non sign�s**". Sur 8bit, on garantit donc qu'un entier de type 128 sera converti en nombre positif (ce qui n'est pas garanti pour le cas d'un **char** sur un syst�me **Arm** par exemple).

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

Le terme anglais pour d�signer une conversion avec "**reduction**" s'appelle le "**narrowing**" et peut comme on l'a montr� produire des r�sultats inattendus ou difficiles � comprendre.

#### Les caract�res �tendus du type "**wchar_t**"

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

#### Le type pr�vu pour les caract�res sur 16 bits : char16_t (C++11)

char16_t est un type r�serv� pour les caract�res sur 16 bits et permet en particulier de repr�senter le jeux de caract�res UTF-16 qui est un jeu de caract�res �tendus par rapport ASCII.

Si char repr�sente la valeur 1 retourn�e par **sizeof**, alors **char16_t** devrait retourner "**2**" (2x8bits = 16). C'est ce que nous allons v�rifier :

    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de char16_t : " << sizeof(char16_t) << std::endl;
      std::cout << "Voici le type id de char16_t : " << typeid(char16_t).name() << std::endl;

    }

**Note** : le **typeinfo** renvoie les lettres "**Ds**" pour les **char16_t**.


#### Le type pr�vu pour les caract�res sur 32 bits : char32_t (C++11)

char32_t est un type r�serv� pour les caract�res sur 32 bits et permet en particulier de repr�senter le jeux de caract�res UTF-32 qui est un jeu de caract�res �tendus par rapport ASCII.

Si char repr�sente la valeur 1 retourn�e par **sizeof**, alors **char32_t** devrait retourner "**4**" (4x8bits = 32). C'est ce que nous allons v�rifier :

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
I> Ce n'est pas le cas pour **wchar_t**, **char16_t** et **char32_t** qui sont bien des types fondamentaux par eux-m�me et font donc partie des mot-cl�s du C++.

#### R�sum� des types caract�res (tableau)

A faire

#### L
