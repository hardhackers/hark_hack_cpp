#include <iostream>

int main ()
{
  std::cout << "Salut le c++";
  return 0;
}

--------------------------------

#include <iostream>
int main ()
{
std::cout << "Salut le c++" << std::endl;
return 0;
}

--------------------------------

    #include <iostream>

    int main ()
    {
      std::cout << "Salut le c++" << std::endl << "Une autre ligne" << std::endl;
      std::cout << "Une troisième ligne" << std::endl << "Une quatrième" << std::endl;
      return 0;
    }

--------------------------------

    #include <iostream>

    int main ()
    {
      std::cout << "Salut le c++\n une autre ligne\n" << "Une troisième ligne" << std::endl << "Une quatrième" << std::endl;
      return 0;
    }

--------------------------------

    #include <iostream>

    int main ()
    {
      std::cout << "Salut le c++" << std::endl;
      return 1;
    }

--------------------------------

    #include <iostream>

    char main ()
    {
      std::cout << "Salut le c++" << std::endl;
      return 0;
    }
--------------------------------

    #include <iostream>

    int main ()
    {
      std::cout << "Salut le c++" << std::endl;
      //Un bloc à l'intérieur de main
      {
        std::cout << "le nouveau bloc imbriqué" << std::endl;
        std::cout << "toujours le nouveau bloc" << std::endl;
      }
      return 0;
    }

--------------------------------

    #include <iostream>

    int main ()
    {
      //un essai sans le std pour cout mais aussi pour endl
      cout << "Salut le c++" << endl;
      return 0;
    }

--------------------------------

    #include <iostream>

    //on déclare le namespace std
    using namespace std;

    int main ()
    {
      //un essai sans le std pour cout mais aussi pour endl
      cout << "Salut le c++" << endl;
      return 0;
    }

--------------------------------
    
   // On fait une erreur volontaire ici en enlevant le "a"
    #include <iostrem>

    using namespace std;

    int main ()
    {
      cout << "Salut le c++" << endl;
      return 0;
    }
