## Afficher une s�quence d'�chappement

### Programme test

Le programme suivant permet d'afficher des lignes de texte dans la console avec quelques caract�res d'�chappement courants :

    # include <iostream>
    
    using namespace std;
    
    int main ()
    {
        //exemple 1
        cout << "Un caract�re de tabulation :\t:" << endl;
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
        cout << "Insertion d'un passage � la ligne\n";
        //exemple 8
        cout << "Affichage d'un slash /" << endl;
        //exemple 9
        cout << "Affichage de deux points d'interrogation et d'un slash ?\?/" << endl;
        //exemple 10
        cout << "Affichage de retour arri�re (backspace)\bx" << endl;
        //exemple 11
        cout << "Affichage d'une nouvelle page :\fUne autre page" << endl;
        //exemple 12
        cout << "Affichage d'une tabulation verticale :\fUne ligne\fEncore une autre" << endl;
    }

* Exemple 1 : on voit que la tabulation s'est bien ins�r�e entre les ":".
* Exemple 2 : apr�s le "r" de "return", le curseur de la console retourne sur le "C" de "Carriage". Ensuite ":" efface le "C" et ":" � nouveau efface le "a" ! Amusant, non ?
* Exemple 3 : le caract�re "alert" est sens� faire un bip mais ceci ne fonctionne pas vraiment pas partout !
* Exemple 4 : Si on veut afficher un "\\" �tant donn� que c'est le caract�re utilis� dans les s�quences d'�chappement, on est oblig� de le doubler pour qu'il apparaisse comme un simple caract�re.
* Exemple 5 : affichage de apostrophe qui est normalement r�serv� pour encadrer un caract�re en C/C++.
* Exemple 6 : affichage de guillemet qui est r�serv� pour encadrer un cha�ne de caract�res.
* Exemple 7 : insertion du passage � la ligne, "n" voulant dire "new line".
* Exemple 8 : affichage d'un slash, pas besoin d'une s�quence d'�chappement.
* Exemple 9 : affichage d'un slash pr�c�d� de deux point d'interrogation. Si on oublie le "\\" devant le deuxi�me "?", on d�clenche un avertissement de compilation : "**warning: trigraph ??/ ignored, use -trigraphs to enable [-Wtrigraphs]**". En effet, la cha�ne "??/" se nomme un trigramme (mot compos� de trois lettres = "trigraph" en anglais).
* Exemple 10 : affiche une chaine de caract�re puis revient en arri�re en l'effa�ant et avance en �crivant un x. On remplace donc la parenth�se fermante par x.
* Exemple 11 : affiche une nouvelle page. En r�alit�, passe � la ligne recopie le nombre de caract�res vides de la cha�ne pr�c�dente et affiche le texte.
* Exemple 12 : les r�sultats sur la ligne de commande parlent d'eux m�me.

### R�sum� des s�quences d'�chappement (tableau)

On peut donc r�sumer les s�quences d'�chappement courantes dans le tableau ci-dessous :

{title="Les s�quences d'�chappement en C/C++", width="narrow"}
|S�quence|       Signification                       |
|--------|-------------------------------------------|
|  \n    |Passage � la ligne (n = new line)          |
|  \t    |Tabulation (t = tabulation)                |
|  \a    |Beep (a = alert)                           |
|  \b    |Retour arri�re (b = backspace)             |
|  \p    |Nouvelle page (p = page)                   |
|  \v    |Tabulation verticale (v = verticale)       |
|  \\\\  |Antislash (backslash)                      |
|  \\"   |Guillemet (Double quote)                   |
|  \\'   |Apostrophe (Single quote)                  |
|  \r    |Retour chariot (r = return)                |
|  \\?   |Point d'interrogation (pour les trigraphes)|
|--------|-------------------------------------------|

A> ## Remarque
A>
A> Comme on peut le deviner, les s�quences d'�chappement sont un r�sidu du langage C, mais il y a moyen de faire autrement en utilisant la syntaxe du C++. Par exemple **\n** � la fin d'une chaine de caract�res peut �tre remplac� par **<< endl** .
A> En dehors de cela, les s�quences de caract�res de type **octal** (\nnn), **hexad�cimal** (\xnn) ou **Unicode** (\unnn) seront �voqu�es dans une partie diff�rente de ce livre.

