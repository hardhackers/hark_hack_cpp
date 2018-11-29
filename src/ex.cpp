    #include <iostream>
    #include <typeinfo>
 
    int main ()
    {
      std::cout << "Voici un float : " << 2.3f << std::endl;
      std::cout << "Voici le type id de 2.3f : " << typeid(2.3f).name() << std::endl;
      std::cout << "Voici un double : " << -2.23568 << std::endl;
      std::cout << "Voici le type id de -2.23568 : " << typeid(-2.23568).name() << std::endl;
      std::cout << "Voici un long double : " << 1.45e+12l << std::endl;
      std::cout << "Voici le type id de 1.45e-12l : " << typeid(1.45e-12l).name() << std::endl;
    }
