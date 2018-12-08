    #include <iostream>
    
    int main()
    {
      int entier1{4};
      int* mon_pointeur = &entier1;
      int** mon_pointeur_de_pointeur = &mon_pointeur;

      std::cout << "Voici l'adresse dans mon_pointeur_de_pointeur : " << mon_pointeur_de_pointeur << std::endl;

      long int entier2{5};
      long int* mon_pointeur2 = &entier2;
      long int** mon_pointeur_de_pointeur2 = &mon_pointeur2;

      std::cout << "Voici l'adresse dans mon_pointeur_de_pointeur2 : " << mon_pointeur_de_pointeur2 << std::endl;
      
      // On pointe vers un long int** (pointeur vers un pointeur qui pointe vers un long int)
      using Pdp = long int**;

      Pdp mon_pdp = mon_pointeur_de_pointeur2;
      std::cout << "Voici l'adresse dans le pointeur de pointeur : " << mon_pdp << std::endl;
     }
