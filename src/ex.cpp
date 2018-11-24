    #include <iostream>
    
    int main ()
    {
      int premier_int = 2147483647;
      int deuxieme_int = 0;
      int somme = premier_int + deuxieme_int;
      std::cout << "Premier entier : " << premier_int << std::endl;
      std::cout << "Deuxième entier : " << deuxieme_int << std::endl;
      std::cout << "Somme : " << somme << std::endl;
      deuxieme_int = 1;
      somme = premier_int + deuxieme_int;
      std::cout << "Somme déborde : " << somme << std::endl;
    }


