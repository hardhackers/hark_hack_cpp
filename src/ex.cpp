    #include <iostream>
    #include <typeinfo>

    int main ()
    {

      std::cout << "Voici la taille de wchar_t : " << sizeof(wchar_t) << std::endl;
      std::cout << "Voici la taille de wchar_t : " << sizeof(char16_t) << std::endl;
      std::cout << "Voici la taille de wchar_t : " << sizeof(char32_t) << std::endl;
      std::cout << "Voici le type id de wide char (wchar_t) : " << typeid(wchar_t).name() << std::endl;


    }
