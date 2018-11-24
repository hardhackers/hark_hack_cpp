    #include <iostream>
    #include <climits>
    #include <cmath>

    int main ()
    {
      std::cout << "Taille d'un short int (signé ou non) : " << sizeof(short int) << std::endl;
      std::cout << "Nombre de bits dans un short : " << CHAR_BIT << std::endl;

      // on multiplie la taille par le nombre de bits d'un char sur ce système
      int nombre_bit_total = CHAR_BIT*sizeof(short int);
      // on calcule la puissance de 2 sur le nombre de bits total -1 pour les signés
      int nombre_max = pow(2,nombre_bit_total-1); 

      std::cout << "Un short int signé ira de (calcul) -"<< nombre_max << " jusqu'à " << nombre_max -1 << std::endl;
      std::cout << "Un short int signé ira de (avec climits) " << SHRT_MIN << " jusqu'à " << SHRT_MAX << std::endl; 

      // on calcule la puissance de 2 sur le nombre de bits total pour les non signés
      nombre_max = pow(2, nombre_bit_total);
      std::cout << "Un short int non signé ira de (calcul) 0 jusqu'à " << nombre_max -1 << std::endl;


      std::cout << "Taille d'un int (signé ou non) : " << sizeof(int) << std::endl;
      std::cout << "Taille d'un long int (signé ou non) : " << sizeof(long int) << std::endl;
      std::cout << "Taille d'un long long int (signé ou non) : "<< sizeof(long long int) << std::endl;
    }
