    #include <iostream>

    int mon_int1{5};
    
    int main()
    {
   
      std::cout << "Voici l'entier 1 qui est une variable globale : " << mon_int1 << std::endl;
      int mon_int1{4};
      std::cout << "Voici l'entier 1 à l'intérieur de main : " << mon_int1 << std::endl;
      //pas ok
      int mon_int1{3};
        {
          //ok
          int mon_int1{2};
          std::cout << "Voici un autre entier 1 à l'intérieur d'un espace de nom inclus dans main : " << mon_int1 << std::endl;
         }
    }
