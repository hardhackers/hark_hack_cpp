    #include <iostream>
    #include <typeinfo>
    int main ()
    {

      auto mon_int_unsigned{13U};
      auto mon_int_long{13L};
      auto mon_int_unsigned_long_long{13ULL};
      // Ok
      auto mon_int_unsigned_long_long2{13LLU};
      // Pas ok
      //auto mon_int_unsigned_long_long2{13LUL};
      auto mon_hexa{0xAAULL};

      std::cout << "Mon entier entier non signé : " << mon_int_unsigned << std::endl;
      std::cout << "Type id : " << typeid(mon_int_unsigned).name() << std::endl;
      std::cout << "Mon entier entier long : " << mon_int_long << std::endl;
      std::cout << "Type id : " << typeid(mon_int_long).name() << std::endl;
      std::cout << "Mon entier entier non signé long long : " << mon_int_unsigned_long_long << std::endl;
      std::cout << "Type id : " << typeid(mon_int_unsigned_long_long).name() << std::endl;
      std::cout << "Mon entier entier non signé long long 2 : " << mon_int_unsigned_long_long2 << std::endl;
      std::cout << "Type id : " << typeid(mon_int_unsigned_long_long2).name() << std::endl;
      std::cout << "Mon entier hexa non signé long long : " << mon_hexa << std::endl;
      std::cout << "Type id : " << typeid(mon_hexa).name() << std::endl;
      std::cout << "Un dernier essai sans initialisation avec auto : " << 178LL << std::endl;
    }
