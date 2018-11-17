## Les différentes catégories de types de données

Il existe en C++ deux catégories de donnée, les types **fondamentaux** ou "**built-in**" ou "**core**" qui appartiennent au coeur du langage et les types qui sont en dehors et qui sont déclarés dans des bibliothèques comme la bibliothèque standard ou une bibliothèque tierce.

Par exemple, le type d'un caractère "**char**" est "**core**" alors que le type d'un flux "**cout**" ne l'est pas.

{title="Les types fondamentaux du C++"}
| Nom du type   |                         Description                               |
|---------------|-------------------------------------------------------------------|
|   bool        | Utilisé pour représenter des entités à deux états                 |
|   char        | Surtout utilisé pour représenter les caractères de la norme ASCII |
|   wchar_t     | Utilisé pour étendre le jeu des caractères de type char           |
|   char16_t    | Jeu de caractères sur 16 bits                                     |
|   char32_t    | Jeu de caractères sur 32 bits                                     |

Les types **intégraux** regroupent les types **booléens**, **caractères** et **entiers**.

Les types arithmétiques regroupent les types **intégraux** et les types à **virgules flottantes**.
