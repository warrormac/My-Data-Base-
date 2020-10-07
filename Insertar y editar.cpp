#include<iostream>
#include<string>
#include<fstream>
#include <iomanip> 
#include <list>
#include <sstream>
#include <stdlib.h>

using namespace std;

string C1 = "CREAR_TABLA";
string C2 = "INSERTAR";
string C4 = "SELECT_*_DESDE";
string C3 = "BORRAR DESDE";
string C5 = "MODIFICAR";

string tipo1 = "int";
string tipo2 = "char";
string tipo3 = "date";

string dataInt = "int";
string dataFloat = "float";
string dataChar = "char";
string dataDate = "date";

list<string> lista;
list<string> type;
list<string> datos;
list<string> ingresar;
list<string> temporal;

void removespaceWord(string str)
{
    //elimina la ", ) (" y lo convierte en " "
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',' || str[i] == '(' || str[i] == ')' || str[i] == '-')
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
    list<string> ::iterator its = type.begin();
    advance(it, 1);


    temp = fileExists(); //verifica si ya existe es nombre

    if (temp == 0)
        cout << "YA EXISTE TABLA " << *it << "\n\n";

    else {

        //********************crea el nombre de .txt***********************************       
        prueba = *it + ".txt";
        ofstream MyReadFile(prueba.c_str());

        cout << "\n\nLA TABLA " << prueba << " SE CREO EXISTOSAMENTE\n\n";



        //*********************Ingresa las cabezaras de la tabla***********************

        //"count" tiene que ser 2 porque estamos saltando el comando y el nombre
        int count = 2;

        for (its = type.begin(); its != type.end(); its++)
        {
            advance(it, 1);
            MyReadFile << *it +" "+ *its << "\t";
        }

        // Close the file
        MyReadFile.close();
        //system("cls");
    }
}

void tipos()
{
    int flag = 0;
    list<string> temp;
    list<string>::iterator itrr;
    for (itrr = lista.begin(); itrr != lista.end(); itrr++)
    {
        if (*itrr == tipo1)
        {
            type.push_back(tipo1);
            flag++;
            temp.push_back(tipo1);
        }
        else if (*itrr == tipo2)
        {
            type.push_back(tipo2);
            flag++;
            temp.push_back(tipo2);
        }
        else if (*itrr == tipo3)
        {
            type.push_back(tipo3);
            flag++;
            temp.push_back(tipo3);
        }

    }
    if (flag == 0)
        cout << "SYNTAX_ERROR: COMAND NOT FOUND";
    for (itrr = temp.begin(); itrr != temp.end(); itrr++)
        lista.remove(*itrr);
    temp.clear();

}


void pull_data()
{
    cout << "\mim in\n";
    int count = 0;
    string prueba, temp;
    list<string> ::iterator it = lista.begin();
    advance(it, 1);
    prueba = *it + ".txt";
    fstream MyReadFile(prueba.c_str());

    while (MyReadFile >> temp)
    {
        datos.push_back(temp);
        
    }
        

   
    /*
    list<string> ::iterator itrs;
    for (itrs = datos.begin(); itrs != datos.end(); itrs++)
        cout << *itrs << "\n";
      */  
    
    
}

template <typename T>
string convert(string l)
{
    stringstream geek(l);
    T x = 0;
    geek >> x;
    
    ostringstream str1;
    str1 << x;
    return str1.str();
    

}

int rows()
{
    string prueba;
    list<string> ::iterator it = lista.begin();
    advance(it, 1);
    prueba = *it + ".txt";

    int number_of_lines = 0;
    string line;
    ifstream myfile(prueba);

    while (getline(myfile, line))
        ++number_of_lines;
    return number_of_lines;
    
}

void insertar()
{
    bool temp = 0;
    int filas = 0;
    string prueba;

    list<string> ::iterator it = lista.begin();


    temp = fileExists(); //verifica si ya existe es nombre
    list<string> ::iterator dat = datos.begin();
    if (temp == 0)
    {
        pull_data(); //saco los tipo delcarados al crear una tabla



        //**********************************casteo los numero sino solo ingreso los string a una nueva lista*******************
        int temp = 2;
        int temp2 = 1;
        while (temp < lista.size() - 1)
        {
            list<string> ::iterator it = lista.begin();
            list<string> ::iterator dat = datos.begin();
            it = lista.begin();
            advance(it, temp);
            advance(dat, temp2);
            temporal.push_back(*it);
            //cout << "lista datos " << *dat << " lista lista " << *it << "\n";
            if (*dat == "float" || *dat == "int")
            {
                ingresar.push_back(convert<double>(*it));
               
            }
            else {
                ingresar.push_back(*it);
            }
            
            temp++;
            temp2 += 2;
            list<string>::iterator itrs;
            cout << "lista de ingresar\n";
            for (itrs = ingresar.begin(); itrs != ingresar.end(); itrs++)
                cout << *itrs << "\n";
        }
        //**************************************ingrese los nuevos valores a la lista ingresar************************
        //cout << "\nvoy a buscar las filas\n";
        filas=rows();

        list<string> ::iterator it = lista.begin(); 
        list<string> ::iterator itrs = temporal.begin();
        cout << "lista de temporal\n";
        for (itrs = temporal.begin(); itrs != temporal.end(); itrs++)
            cout << *itrs << "\n";


        advance(it, 1);
        prueba = *it + ".txt";
        ofstream MyReadFile;
        MyReadFile.open(prueba, std::ios_base::app); // append instead of overwrite
        MyReadFile << "Data";


    }
}

void commands(list<string> x)
{

    if (C1 == (x.front()))
    {
        create();
        //cout << "crea\n";
    }
    if (C2 == (x.front()))
    {
        insertar();
        cout << "insert\n";
    }
    if (C3.compare(x.front()) == 0)
    {
        //create();
        cout << "del\n";
    }
    if (C4.compare(x.front()) == 0)
    {
        //create();
        cout << "select\n";
    }
    if (C5.compare(x.front()) == 0)
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
        tipos();
        //cout << temp.front();
        commands(lista);


        //creo un iterador para poder imprimir la pablabra   **solo para probar (tester)**

       /* list<string>::iterator itr;
        list<string>::iterator itrs;
        cout << "lista de lista\n";
        for (itr = lista.begin(); itr != lista.end(); itr++)
            cout << *itr << "\n";
        cout << "lista de type\n";
        for (itrs = datos.begin(); itrs != datos.end(); itrs++)
            cout << *itrs << "\n";
        */
        lista.clear();
        type.clear();
        //system("cls");



    }

}
