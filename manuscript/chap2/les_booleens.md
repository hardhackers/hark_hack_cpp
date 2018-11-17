## Le type bool�en

Le type bool�en peut avoir deux valeurs : **vrai** ou **faux**. Il est utile pour repr�senter des �l�ments de la vie r�elle ayant deux �tats, par exemple une barri�re de passage � niveau : **ouverte** ou **ferm�e**.

L'initialisation de ce type (nous reviendrons sur la notion d'initialisation apr�s) peut �tre le r�sultat d'une expression logique. Voici un petit programme qui permet de comprendre :

    #include <iostream>
    
    int main ()
    {
      int x = 20;
      int y = 30;
      //on teste si x est �gal � y et on affecte la valeur du test � "mon_bool"
      bool mon_bool = ( x == y );
      std::cout << "Voici la valeur du bool�en : " << mon_bool << std::endl;
      y = 20;
      //on teste � nouveau
      mon_bool = ( x == y);
      std::cout << "Voici la nouvelle valeur : " << mon_bool << std::endl;
      y = 40;
      mon_bool = ( x < y );
      std::cout << "Voici le r�sultat : " << mon_bool << std::endl;
      mon_bool = ( x > y );
      std::cout << "Voici le r�sultat 4 : " << mon_bool << std::endl;
    }

Il est int�ressant de voir comment les entiers sont convertis en boolean. Si un entier est diff�rent de 0, il est converti en "true" (1). Sinon, il est converti en "false" (0). Ce petit programme le montre :

    #include <iostream>
    
    int main ()
    {
      int x = 3;
      int y = -1;
      int z = 0;
      bool mon_bool = x;
      std::cout << "Voici le r�sultat pour un entier positif comme x = 3 : " << mon_bool << std::endl;
      mon_bool = y;
      std::cout << "Voici le r�sultat pour un entier n�gatif comme y = -1 : " << mon_bool << std::endl;
      mon_bool = z;
      std::cout << "Voici le r�sultat pour entier nul comme z = 0 : " << mon_bool << std::endl;
    }

Pour le programme si dessus, on effectue une conversion d'un entier vers un bool�en avec r�duction. Par exemple, le "**3**" devient un "**0**". On appelle ce processus de r�duction le "**narrowing**". Comme on s'en doute, le fait de "r�duire" un nombre peut amener des cons�quences inattendues et des bugs.

Il est bien s�r possible de d�clarer des valeurs bool�ennes directement avec **true** ou **false** :

    #include <iostream>
    
    int main ()
    {
      bool mon_bool_vrai = true;
      std::cout << "Voici le r�sultat pour un bool true : " << mon_bool_vrai << std::endl;
      bool mon_bool_faux = false;
      std::cout << "Voici le r�sultat pour un bool faux : " << mon_bool_faux << std::endl;
      int mon_entier_vrai = true;
      std::cout << "Voici le r�sultat pour un entier vrai : " << mon_entier_vrai << std::endl;
      int mon_entier_faux = false;
      std::cout << "Voici le r�sultat pour un entier faux : " << mon_entier_faux << std::endl;
    }

Comme on peut le constater, ceci fonctionne aussi avec des entiers mis � "**true**" ou "**false**", comme quoi il faut exp�rimenter !!
