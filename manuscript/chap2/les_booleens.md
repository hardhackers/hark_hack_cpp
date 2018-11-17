## Le type booléen

Le type booléen peut avoir deux valeurs : **vrai** ou **faux**. Il est utile pour représenter des éléments de la vie réelle ayant deux états, par exemple une barrière de passage à niveau : **ouverte** ou **fermée**.

L'initialisation de ce type (nous reviendrons sur la notion d'initialisation après) peut être le résultat d'une expression logique. Voici un petit programme qui permet de comprendre :

    #include <iostream>
    
    int main ()
    {
      int x = 20;
      int y = 30;
      //on teste si x est égal à y et on affecte la valeur du test à "mon_bool"
      bool mon_bool = ( x == y );
      std::cout << "Voici la valeur du booléen : " << mon_bool << std::endl;
      y = 20;
      //on teste à nouveau
      mon_bool = ( x == y);
      std::cout << "Voici la nouvelle valeur : " << mon_bool << std::endl;
      y = 40;
      mon_bool = ( x < y );
      std::cout << "Voici le résultat : " << mon_bool << std::endl;
      mon_bool = ( x > y );
      std::cout << "Voici le résultat 4 : " << mon_bool << std::endl;
    }

Il est intéressant de voir comment les entiers sont convertis en boolean. Si un entier est différent de 0, il est converti en "true" (1). Sinon, il est converti en "false" (0). Ce petit programme le montre :

    #include <iostream>
    
    int main ()
    {
      int x = 3;
      int y = -1;
      int z = 0;
      bool mon_bool = x;
      std::cout << "Voici le résultat pour un entier positif comme x = 3 : " << mon_bool << std::endl;
      mon_bool = y;
      std::cout << "Voici le résultat pour un entier négatif comme y = -1 : " << mon_bool << std::endl;
      mon_bool = z;
      std::cout << "Voici le résultat pour entier nul comme z = 0 : " << mon_bool << std::endl;
    }

Pour le programme si dessus, on effectue une conversion d'un entier vers un booléen avec réduction. Par exemple, le "**3**" devient un "**0**". On appelle ce processus de réduction le "**narrowing**". Comme on s'en doute, le fait de "réduire" un nombre peut amener des conséquences inattendues et des bugs.

Il est bien sûr possible de déclarer des valeurs booléennes directement avec **true** ou **false** :

    #include <iostream>
    
    int main ()
    {
      bool mon_bool_vrai = true;
      std::cout << "Voici le résultat pour un bool true : " << mon_bool_vrai << std::endl;
      bool mon_bool_faux = false;
      std::cout << "Voici le résultat pour un bool faux : " << mon_bool_faux << std::endl;
      int mon_entier_vrai = true;
      std::cout << "Voici le résultat pour un entier vrai : " << mon_entier_vrai << std::endl;
      int mon_entier_faux = false;
      std::cout << "Voici le résultat pour un entier faux : " << mon_entier_faux << std::endl;
    }

Comme on peut le constater, ceci fonctionne aussi avec des entiers mis à "**true**" ou "**false**", comme quoi il faut expérimenter !!
