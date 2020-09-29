#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

string C1 = "CREAR_TABLA";
string C2 = "INSERTAR";
string C4 = "SELECT_*_DESDE";
string C3 = "BORRAR DESDE";
string C5 = "MODIFICAR";





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
    temp=fileExists("STAT"); //verifica si ya existe es nombre

    if (temp == 0);
    else {
        string prueba;

        ofstream MyReadFile("prueba.csv");

        MyReadFile << "pruebas";
        // Close the file
        MyReadFile.close();
    }
}

//falta el comando insertar

//falta el comando select

//falta el comando borrar

//falta el comando modificar



void comads(string x)
{

    if (C1.compare(x) == 0)
    {
        create();
        cout << "crea\n";
    }
    else if (C2.compare(x) == 0)
    {
        //create();
        cout << "insert\n";
    }
    else if (C3.compare(x) == 0)
    {
        //create();
        cout << "del\n";
    }
    else if (C4.compare(x) == 0)
    {
        //create();
        cout << "select\n";
    }
    else if (C5.compare(x) == 0)
    {
        //create();
        cout << "mod\n";
    }
    else { cout << "SYNTAX_ERROR: COMAND NOT FOUND"; }
    

}


int main()
{
    string myText;
    
    
     //este es el IDLE
    while (true)
    {
        string x;
        cin >> x;
        comads(x);
    }

    

    




}
