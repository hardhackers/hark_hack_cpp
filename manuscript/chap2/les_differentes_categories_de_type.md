## Les diff�rentes cat�gories de types de donn�es

Il existe en C++ deux cat�gories de donn�e, les types **fondamentaux** ou "**built-in**" ou "**core**" qui appartiennent au coeur du langage et les types qui sont en dehors et qui sont d�clar�s dans des biblioth�ques comme la biblioth�que standard ou une biblioth�que tierce.

Par exemple, le type d'un caract�re "**char**" est "**core**" alors que le type d'un flux "**cout**" ne l'est pas.

{title="Les types fondamentaux du C++"}
| Nom du type   |                         Description                               |
|---------------|-------------------------------------------------------------------|
|   bool        | Utilis� pour repr�senter des entit�s � deux �tats                 |
|   char        | Surtout utilis� pour repr�senter les caract�res de la norme ASCII |
|   wchar_t     | Utilis� pour �tendre le jeu des caract�res de type char           |
|   char16_t    | Jeu de caract�res sur 16 bits                                     |
|   char32_t    | Jeu de caract�res sur 32 bits                                     |

Les types **int�graux** regroupent les types **bool�ens**, **caract�res** et **entiers**.

Les types arithm�tiques regroupent les types **int�graux** et les types � **virgules flottantes**.
