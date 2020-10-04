#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


string C1 = "CREAR_TABLA";
string C2 = "INSERTAR";
string C4 = "SELECT_*_DESDE";
string C3 = "BORRAR DESDE";
string C5 = "MODIFICAR";

//declaro la lista
list<string> temp;


void removespaceWord(string str)
{
    istringstream ss(str);

    while (ss)
    {
        string word;
        ss >> word;
        temp.push_back(word);
    }
}

bool fileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}


void create()
{

    //falta ingresar los valores a las tablas osea 
    //los CREAR_TABLA "nombre"(...)

    bool temp = 0;
    temp = fileExists("prueba1"); //verifica si ya existe es nombre

    if (temp == 0);
    else {
        string prueba;

        ofstream MyReadFile("prueba1.csv");

        MyReadFile << "probando 1 ";
        // Close the file
        MyReadFile.close();
    }
}


void commands(list<string> x)
{

    if (C1 == (x.front()))
    {
        create();
        cout << "crea\n";
    }
    else if (C2.compare(x.front()) == 0)
    {
        //create();
        cout << "insert\n";
    }
    else if (C3.compare(x.front()) == 0)
    {
        //create();
        cout << "del\n";
    }
    else if (C4.compare(x.front()) == 0)
    {
        //create();
        cout << "select\n";
    }
    else if (C5.compare(x.front()) == 0)
    {
        //create();
        cout << "mod\n";
    }
    else { cout << "SYNTAX_ERROR: COMAND NOT FOUND"; }


}


int main()
{
    string x;

    

    while (true)
    {
        cout << "ingrese comando: ";

        //creo ingreso el texto *COMANDO*. se hace de esta forma para poder 
        //usar espacios
        getline(cin, x);

        //funcion que saca los espacios
        removespaceWord(x);
        //cout << temp.front();
        commands(temp);
        
        //creo un iterador para poder imprimir la pablabra   **solo para probar (tester)** 
        /*
        list<string>::iterator itr;
        for (itr = temp.begin(); itr != temp.end(); itr++)
            cout << *itr << "\n";
        */

    }
    
}



