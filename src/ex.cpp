    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de char32_t : " << sizeof(char32_t) << std::endl;
      std::cout << "Voici le type id de char32_t : " << typeid(char32_t).name() << std::endl;

    }
