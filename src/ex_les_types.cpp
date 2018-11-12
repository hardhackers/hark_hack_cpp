----------------------------------------
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
----------------------------------------

    #include <iostream>
    #include <typeinfo>

    int main ()
    {
      //Je déclare un entier
      int mon_entier = 255;
      std::cout << "Voici la valeur de l'entier au départ : " << mon_entier << std::endl;
      
      //Je transforme en char
      char mon_char = mon_entier;
      //Je retransforme en entier
      mon_entier = mon_char;
      std::cout << "Voici l'entier maintenant : " << mon_entier << std::endl;
    }


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

----------------------------------------

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

----------------------------------------

    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de wchar_t : " << sizeof(wchar_t) << std::endl;
      std::cout << "Voici le type id de wide char (wchar_t) : " << typeid(wchar_t).name() << std::endl;

    }

