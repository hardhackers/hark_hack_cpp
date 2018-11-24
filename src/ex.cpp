    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de signed int : " << sizeof(signed) << std::endl;
      std::cout << "Voici le type id de signed int : " << typeid(signed int).name() << std::endl;

    }


