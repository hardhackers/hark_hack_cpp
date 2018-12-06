    #include<iostream>

    int main()
    {
      int mon_entier{654444};
      std::cout << "Affichage de l'entier : " << mon_entier << std::endl;
      int* mon_pointeur = &mon_entier;
      int mon_entier2 = *mon_pointeur;
      std::cout << "Affichage de l'entier mis dans un entier : " << mon_entier2 << std::endl; 
      char mon_char = *mon_pointeur;
      int mon_entier3 = mon_char;
      std::cout << "Affichage de l'entier mis dans un char : " << mon_entier3 << std::endl; 
    }
