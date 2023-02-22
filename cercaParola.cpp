#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    // trovare le righe contenenti la parola data
    // int trova(string parola)
    ifstream fileInput("maggio.txt"); // apertura file in lettura
    // ofstream fileOutput("output.txt"); // apertura file in scrittura
    // variabili
    string riga;
    string parola = "percossa";
    int numeroRigaParolaTrovata = 0;
    // cout << "INIZIO" << endl;
    while (getline(fileInput, riga))
    {
        // cout << "RIGA: " << riga << endl;
        numeroRigaParolaTrovata++;
        bool flag = false;                      // SE TROVO LA PAROLA IMPOSTO A TRUE
        for (int i = 0; i < riga.length(); i++) // for tutta riga
        {
            // cout << "i: " << i << endl;
            for (int j = 0; j < parola.length(); j++) // for tutta parola
            {
                // cout << "j: " << j << endl;
                // cout << "riga[i]: " << riga[i] <<" == "<< "parola[j]:" << parola[j] << endl;
                if (riga[i] == parola[j]) // se le lettere sono uguali
                {
                    if (j == parola.length() - 1) // se le lettere sono uguali E sono all'ultima lettera della parola
                    {
                        flag = true; // PAROLA TROVATA
                        cout << "TROVATA" << endl;
                    }
                    i++;
                }
                else
                {
                    break;
                }
            }
        }
        if (flag == true)
        {
            cout << "PAROLA TROVATA IN RIGA: " << numeroRigaParolaTrovata << endl;
        }
    }
    fileInput.close();
    // fileOutput.close();
}