#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


list<string> temp;


void removespaceWord(string str)
{
    //elimina los "()" al ingresarlos 
    str.erase(remove(str.begin(), str.end(), '('), str.end());
    str.erase(remove(str.begin(), str.end(), ')'), str.end());

    //elimina la "," y lo convierte en " "
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',')
            str[i] = ' ';
    }



    istringstream ss(str);

    //ingreso el comando a la lista
    while (ss)
    {
        string word;
        ss >> word;
        temp.push_back(word);
    }
}



int main()
{
    string x;

        cout << "ingrese comando: ";

        //creo ingreso el texto *COMANDO*. se hace de esta forma para poder 
        //usar espacios
        getline(cin, x);

        //funcion que saca los espacios
        removespaceWord(x);
        //cout << temp.front();
        //commands(temp);

        //creo un iterador para poder imprimir la pablabra   **solo para probar (tester)** 
        
        list<string>::iterator itr;
        for (itr = temp.begin(); itr != temp.end(); itr++)
            cout << *itr << "\n";

}
