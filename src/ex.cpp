    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      // test avec signed char
      std::cout << "Voici le type id d'un signed char : " << typeid(signed char).name() << std::endl;
      // test avec int8_t
      std::cout << "Voici le type id d'un int8_t : " << typeid(int8_t).name() << std::endl;
      // test avec short
      std::cout << "Voici le type id d'un short int : " << typeid(short int).name() << std::endl;
      // test avec int16_t
      std::cout << "Voici le type id d'un int16_t : " << typeid(int16_t).name() << std::endl;
      // test avec int
      std::cout << "Voici le type id d'un int : " << typeid(int).name() << std::endl;
      // test avec int32_t
      std::cout << "Voici le type id d'un int32_t : " << typeid(int32_t).name() << std::endl;
      // test avec long int
      std::cout << "Voici le type id long int : " << typeid(long int).name() << std::endl;
      // test avec int64_t
      std::cout << "Voici le type id d'un int64_t : " << typeid(int64_t).name() << std::endl;

    }
