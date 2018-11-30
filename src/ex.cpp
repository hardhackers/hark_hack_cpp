    #include <iostream>

    int mon_int1{5};
    
    int main()
    {
      int mon_int1{4};
      // les doubles "deux points" sont là pour identifier une variable globale
      std::cout << "Voici l'entier 1 qui est une variable globale : " << ::mon_int1 << std::endl;
      // la variable locale à la fonction
      std::cout << "Voici l'entier 1 à l'intérieur de main : " << mon_int1 << std::endl;
    }
