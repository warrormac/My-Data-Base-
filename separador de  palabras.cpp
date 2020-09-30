#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;


void removespaceWord(string str, list<string> &temp)
{
    istringstream ss(str);

    while (ss)
    {
        string word;
        ss >> word;
       temp.push_back( word) ;

    } 
}

int main()
{
    string x;

    //declaro la lista
    list<string> temp; 
    cout << "ingrese comando: ";

    //creo ingreso el texto *COMANDO*. se hace de esta forma para poder 
    //usar espacios
    getline(cin,x);

    //funcion que saca los espacios
    removespaceWord(x,temp);


    //creo un iterador para poder imprimir la pablabra   **solo para probar** 
    list<string>::iterator itr;
    for (itr = temp.begin(); itr != temp.end(); itr++)
        cout << *itr << "\n";

}
