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


list<string> lista;


void removespaceWord(string str)
{
    //elimina la ", ) (" y lo convierte en " "
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',' || str[i] == '(' || str[i] == ')')
            str[i] = ' ';
    }

    istringstream ss(str);
    //ingreso el comando a la lista
    while (ss)
    {
        string word;
        ss >> word;
        lista.push_back(word);
    }
}


bool fileExists()
{
    string temp;
    list<string> ::iterator it = lista.begin();
    advance(it, 1);
    temp = *it + ".txt";

    ifstream file(temp.c_str(), ios_base::out | ios_base::in);
    if (!file)
        return 1;
    return 0;
    
}



void create()
{

    bool temp = 0;
    string prueba;
    list<string> ::iterator it = lista.begin();
    advance(it, 1);


    temp = fileExists(); //verifica si ya existe es nombre

    if (temp == 0)
        cout<<"YA EXISTE TABLA "<< *it<<"\n\n";

    else {

        //********************crea el nombre de .txt***********************************       
        prueba = *it + ".txt";
        ofstream MyReadFile(prueba.c_str());

        cout << "\n\nLA TABLA "<< prueba<<" SE CREO EXISTOSAMENTE\n\n";



        //*********************Ingresa las cabezaras de la tabla***********************
        
        //"count" tiene que ser 2 porque estamos saltando el comando y el nombre
        int count = 2;
        while (count != lista.size()-1)
        {
            advance(it, 1);
            //cout << *it << "\n";
            MyReadFile << *it <<"\t";
            count++;
        }        
        // Close the file
        MyReadFile.close();
        system("cls");
    }
}


void commands(list<string> x)
{

    if (C1 == (x.front()))
    {
        create();
        //cout << "crea\n";
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
        commands(lista);

        
        lista.clear();
        //system("cls");
        
        
        //creo un iterador para poder imprimir la pablabra   **solo para probar (tester)** 
        /*
        list<string>::iterator itr;
        for (itr = lista.begin(); itr != lista.end(); itr++)
            cout << *itr << "\n";
        */

    }

}
