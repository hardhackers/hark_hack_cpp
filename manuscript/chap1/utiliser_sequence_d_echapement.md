## Afficher une séquence d'échappement

### Programme test

Le programme suivant permet d'afficher des lignes de texte dans la console avec quelques caractères d'échappement courants :

    # include <iostream>
    
    using namespace std;
    
    int main ()
    {
        //exemple 1
        cout << "Un caractère de tabulation :\t:" << endl;
        //exemple 2        
	cout << "Carriage return\r::" << endl;
        //exemple 3
        cout << "Alerte !\a" << endl;
        //exemple 4
        cout << "Affichage d'un backslash \\" << endl;
        //exemple 5
        cout << "Affichage d'une apostrophe \'" << endl;
        //exemple 6
        cout << "Affichage d'un guillemet \"" << endl;
        //exemple 7
        cout << "Insertion d'un passage à la ligne\n";
        //exemple 8
        cout << "Affichage d'un slash /" << endl;
        //exemple 9
        cout << "Affichage de deux points d'interrogation et d'un slash ?\?/" << endl;
    }

* Exemple 1 : on voit que la tabulation s'est bien insérée entre les ":".
* Exemple 2 : après le "r" de "return", le curseur de la console retourne sur le "C" de "Carriage". Ensuite ":" efface le "C" et ":" à nouveau efface le "a" ! Amusant, non ?
* Exemple 3 : le caractère "alert" est sensé faire un bip mais ceci ne fonctionne pas vraiment pas partout !
* Exemple 4 : Si on veut afficher un "\\" étant donné que c'est le caractère utilisé dans les séquences d'échappement, on est obligé de le doubler pour qu'il apparaisse comme un simple caractère.
* Exemple 5 : affichage de apostrophe qui est normalement réservé pour encadrer un caractère en C/C++.
* Exemple 6 : affichage de guillemet qui est réservé pour encadrer un chaîne de caractères.
* Exemple 7 : insertion du passage à la ligne, "n" voulant dire "new line".
* Exemple 8 : affichage d'un slash, pas besoin d'une séquence d'échappement.
* Exemple 9 : affichage d'un slash précédé de deux point d'interrogation. Si on oublie le "\" devant le deuxième ?, on déclenche un avertissement de compilation : "**warning: trigraph ??/ ignored, use -trigraphs to enable [-Wtrigraphs]**". En effet, la chaîne "??/" se nomme un trigraphe.

### Résumé des séquences d'échappement (tableau)

On peut donc résumer les séquences d'échappement courantes dans le tableau ci-dessous :

{title="Les séquences d'échappement en C/C++", width="narrow"}
|Séquence|       Signification                       |
|--------|-------------------------------------------|
|  \n    |Passage à la ligne (n = new line)          |
|  \t    |Tabulation (t = tabulation)                |
|  \a    |Beep (a = alert)                           |
|  \\\\  |Antislash (backslash)                      |
|  \\"   |Guillemet (Double quote)                   |
|  \\'   |Apostrophe (Single quote)                  |
|  \r    |Retour chariot (r = return)                |
|  \\?   |Point d'interrogation (pour les trigraphes)|

A> ## Remarque
A>
A> Comme on peut le deviner, les séquences d'échappement sont un résidu du langage C, mais il y a moyen de faire autrement en utilisant la syntaxe du C++. Par exemple **\n** à la fin d'une chaine de caractères peut être remplacé par **<< endl** .

