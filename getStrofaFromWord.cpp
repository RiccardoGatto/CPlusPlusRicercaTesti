#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string riga;
    string parola = "";
    string strofa = "";
    int indice;
    while (parola != "exit")
    {
        cout << "Inserisci una parola: ";
        cin >> parola;
        cout << "\n";
        indice = 0;
        
        ifstream fileInput("maggio.txt"); // apertura file in lettura
        strofa = "";
        while (getline(fileInput, riga))
        {
            indice++;
            if (riga != "")
            {
                strofa = strofa + to_string(indice) + " - " + riga + "\n";
            }
            else
            {
                strofa = "";
            }
            // bool flag = false; // SE TROVO LA PAROLA IMPOSTO A TRUE
            for (int i = 0; i < riga.length(); i++) // for tutta riga
            {
                for (int j = 0; j < parola.length(); j++) // for tutta parola
                {
                    if (riga[i] == parola[j]) // se le lettere sono uguali
                    {
                        if (j == parola.length() - 1) // se le lettere sono uguali E sono all'ultima lettera della parola
                        {
                            // flag = true;
                            cout << "La parola si trova nel versetto " << indice << "\n\n";
                            while (getline(fileInput, riga))
                            {
                                indice++;
                                if (riga != "")
                                {
                                    strofa = strofa + to_string(indice) + " - " + riga + "\n";
                                }
                                else
                                {
                                    break;
                                }
                            }
                            cout << strofa << "\n";
                        }
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        fileInput.close();
    }
}