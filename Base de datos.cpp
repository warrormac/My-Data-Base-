#include<iostream>
#include<string>
#include<fstream>
#include <iomanip> 
#include <list>
#include <sstream>
#include <stdlib.h>
#include<stdio.h> 
#include <algorithm>


using namespace std;

string C1 = "CREAR_TABLA";
string C2 = "INSERTAR";
string C4 = "SELECT_*_DESDE";
string C3 = "BORRAR_DESDE_ID";
string C5 = "MODIFICAR";
string C6 = "BORRAR_TABLA";

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
int verificador = 1;

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



void create(int temp)
{

    string prueba;
    list<string> ::iterator it = lista.begin();
    list<string> ::iterator its = type.begin();
    advance(it, 1);

    if(temp==0)
        temp = fileExists(); //verifica si ya existe es nombre

    if (temp == 0)
        cout << "YA EXISTE TABLA " << *it << "\n\n";

    else {

        //********************crea el nombre de .txt***********************************       
        prueba = *it + ".txt";
        ofstream MyReadFile(prueba.c_str());

        cout << "\n\nLA TABLA " << prueba << " SE GENERO EXISTOSAMENTE\n\n";



        //*********************Ingresa las cabezaras de la tabla***********************

        //"count" tiene que ser 2 porque estamos saltando el comando y el nombre
        int count = 2;

        for (its = type.begin(); its != type.end(); its++)
        {
            advance(it, 1);
            MyReadFile << *it + " (" + *its +")"<< "\t";
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
        while (temp < lista.size()-verificador)
        {
            list<string> ::iterator it = lista.begin();
            list<string> ::iterator dat = datos.begin();
            it = lista.begin();
            advance(it, temp);
            advance(dat, temp2);
            temporal.push_back(*it);
            //cout << "lista datos " << *dat << " lista lista " << *it << "\n";
            if (*dat == "(float)" || *dat == "(int)")
            {
                ingresar.push_back(convert<double>(*it));
                


            }
            else {
                ingresar.push_back(*it);
            }

            temp++;
            temp2 += 2;
            list<string>::iterator itrs;
            /*cout << "lista de ingresar\n";
            for (itrs = ingresar.begin(); itrs != ingresar.end(); itrs++)
                cout << *itrs << "\n";*/
        }
        //**************************************ingrese los nuevos valores a la lista ingresar************************
        //cout << "\nvoy a buscar las filas\n";
        filas = rows();

        
        //*************************************ingresar los datos a la tabla******************************************
        list<string> ::iterator it = lista.begin();
        list<string> ::iterator itrs = temporal.begin();
       /* cout << "lista de temporal\n";
        for (itrs = temporal.begin(); itrs != temporal.end(); itrs++)
            cout << *itrs << "\n";
            */

        advance(it, 1);
        prueba = *it + ".txt";
        ofstream MyReadFile;
        MyReadFile.open(prueba, std::ios_base::app); // append instead of overwrite
        int count = 0;
        while (count < ingresar.size())
        {
            list<string> ::iterator it = ingresar.begin();
            advance(it, count);
            if(count==0)
                MyReadFile <<"\n"<< *it << "\t";
            else MyReadFile << *it <<"\t";
            count++;
        }
        //**********************************respeta la lo escrito*****************************************************
        ingresar.clear();

    }
}

void elim()
{
    fstream file;
    string word, t, q, filename,xx;
    int comand = 0;
    list<string> ::iterator it = lista.begin();
    advance(it, 1);

    filename = *it + ".txt";
    q = filename;
    file.open(filename.c_str());

    it = lista.begin();
    advance(it, 2);
    string ID = *it;
    //************************************paso de lista a temporal**************************
    for (it = lista.begin(); it != lista.end(); it++)
        temporal.push_back(*it);
    lista.clear();

    while (file >> word)
        xx += word+" ";
    

    //***************************************recreo el txt****************
    removespaceWord(xx);

    for (it = lista.begin(); it != lista.end(); it++)
        ingresar.push_back(*it);
    lista.clear();

    char c1 = 'int';
    char c2 = 'char';
    char c3 = 'date';
    for (int i = 0; i < xx.length(); i++)
    {
        
        if (xx[i] == c1 || xx[i] == c2 || xx[i] == c3)
            comand++;       
    }
    comand = comand * 2;

    int c = 0;
    while (c < comand)
    {
        it = ingresar.begin();
        advance(it, c);
        lista.push_back(*it);
        c++;
    }
    list<string> ::iterator tempo = temporal.begin();
    advance(tempo, 1);
    lista.push_front(*tempo);
    tempo = temporal.begin();
    lista.push_front(*tempo);
    
    tipos();
    create(1);

    //************************se creo el remplazo   PASO 1 TERMINADO**************
    /*
    //**************************TEST*****************************************
    cout << "\nTEST lista\n";
    for (it = lista.begin(); it != lista.end(); it++)
        cout << *it << "\n";
    list<string> ::iterator tip = type.begin();
    cout << "\nTEST type\n";
    for (tip = type.begin(); tip != type.end(); tip++)
        cout << *tip << "\n";

    tempo = temporal.begin();
    cout << "\nTEST temporl\n";

    for (tempo = temporal.begin(); tempo != temporal.end(); tempo++)
        cout << *tempo << "\n";

    list<string> ::iterator dat = temporal.begin();
    cout << "\nTEST datos\n";
    for (dat = datos.begin(); dat != datos.end(); dat++)
        cout << *dat << "\n";

    list<string> ::iterator ing = ingresar.begin();
    cout << "\nTEST ingresar\n";
    for (ing = ingresar.begin(); ing != ingresar.end(); ing++)
        cout << *ing << "\n";

    cout << "\n\nPaso 1 completo...\n\n";
    //***************************-------------------*****************
    */


    lista.clear();
    
    stringstream geek(ID);
    int x = 0;
    geek >> x;

    list<string> ::iterator ing = ingresar.begin();
    int comand2 = comand;
    int tem = 0;
    ing = ingresar.begin();
    advance(ing, comand-1);
    while (tem < ((comand2 / 2) * x ))
    {
        advance(ing, 1);
        lista.push_back(*ing);
        
        tem++;
    }
    tempo = temporal.begin();
    advance(tempo, 1);
    lista.push_front(*tempo);
    tempo = temporal.begin();
    lista.push_front(*tempo);
    
    for (it = lista.begin(); it != lista.end(); it++)
        cout << *it << "\n";

    datos.clear();
    temporal.clear();
    ingresar.clear();
    type.clear();

    tem = 0;
    int tem2 = 2;
    int counter = 0;
    type = lista;
    it = lista.begin();
    string comando = *it;
    advance(it, 1);
    string name = *it;
    lista.clear();
    
    verificador = 0;
    while (tem2 < type.size())
    {
        list<string> ::iterator t = type.begin();
        if (tem == (comand2 / 2))
        {
            lista.push_front(name);
            lista.push_front(comando);
            insertar();
            lista.clear();
            tem = 0;

        }
        advance(t, tem2);
        lista.push_back(*t);
        tem++;
        tem2++;
    }
   
    verificador = 1;
   
}

void eliminarTab()
{
    int temp = 0;
    list<string>::iterator it = lista.begin();
    advance(it, 1);
    string name = *it+".txt";
    if (remove(name.c_str()) != 0)
        cout << "\nTABLA FUE ELIMINADA CON EXITO\n" << endl;
    else
        cout << name << "\nTABLA NO EXISTE O NO FUE ENCONTRADA\n" << endl;
    
}

void select()
{
    fstream file;
    string word, t, q, filename, xx;
    int comand = 0;
    list<string> ::iterator it = lista.begin();
    advance(it, 1);

    filename = *it + ".txt";
    q = filename;
    file.open(filename.c_str());

    it = lista.begin();
    advance(it, 2);
    string ID = *it;

    stringstream geek(ID);
    int x = 0;
    geek >> x;

    //************************************paso de lista a temporal**************************
    for (it = lista.begin(); it != lista.end(); it++)
        temporal.push_back(*it);
    lista.clear();

    while (file >> word)
        xx += word + " ";


    //***************************************recreo el txt****************
    removespaceWord(xx);

    for (it = lista.begin(); it != lista.end(); it++)
        ingresar.push_back(*it);
    lista.clear();


    size_t pos = xx.find("int", 0);
    while (pos != string::npos)
    {
        comand++;
        pos = xx.find("int", pos + 1);
    }
    pos = xx.find("char", 0);
    while (pos != string::npos)
    {
        comand++;
        pos = xx.find("char", pos + 1);
    }
    pos = xx.find("date", 0);
    while (pos != string::npos)
    {
        comand++;
        pos = xx.find("date", pos + 1);
    }



    cout << comand<<"\n";
    //********************************comand es el tam de la primera fila, tam es de las otras filas 
    comand = comand * 2;
    int tam = comand / 2;
    int salto = (tam * (x -1)) + comand;

        while (salto < ingresar.size())
        {
            list<string>::iterator ing = ingresar.begin();
            advance(ing, salto);
            lista.push_back(*ing);
            salto++;

        }
        list<string>::iterator ing = lista.begin();
        for (ing = lista.begin(), tam = 0; ing != lista.end(); tam++, ing++)
            cout << *ing << "\n";
       ing = lista.begin();
        for (ing = lista.begin(),tam=0; ing != lista.end(); tam++, ing++)
        {
            if (tam == comand / 2)
            {
                cout << endl;
                tam = 0;
            }

            cout << *ing << "\t";
        }
        cout << endl;
    
    
    
    

}


void modificar()
{
    fstream file;
    string word, t, q, filename, xx;
    int comand = 0;
    
    list<string> ::iterator it = lista.begin();
    string command = *it;
    advance(it, 1);
    string name = *it;
    filename = *it + ".txt";
    q = filename;
    file.open(filename.c_str());

    it = lista.begin();
    advance(it, 2);
    string fila = *it;
    it = lista.begin();
    advance(it, 3);
    string dato = *it;
    MOD.push_back(dato);
    it = lista.begin();
    advance(it, 4);
    string ID = *it;

    stringstream geek(ID);
    int x = 0;
    geek >> x;
    //************************************paso de lista a temporal**************************
    for (it = lista.begin(); it != lista.end(); it++)
        temporal.push_back(*it);
    list<string>::iterator itrs=temporal.begin();
    cout << "lista de temporal\n";
    for (itrs = temporal.begin(); itrs != temporal.end(); itrs++)
        cout << *itrs << "\n";

    lista.clear();

    while (file >> word)
        xx += word + " ";

    //***************************************recreo el txt****************
    removespaceWord(xx);

    for (it = lista.begin(); it != lista.end(); it++)
        ingresar.push_back(*it);

    itrs = ingresar.begin();
    lista.clear();

    //******************************************saco el tama;o de la fila************************
    size_t pos = xx.find("int", 0);
    while (pos != string::npos)
    {
        comand++;
        pos = xx.find("int", pos + 1);
    }
    pos = xx.find("char", 0);
    while (pos != string::npos)
    {
        comand++;
        pos = xx.find("char", pos + 1);
    }
    pos = xx.find("date", 0);
    while (pos != string::npos)
    {
        comand++;
        pos = xx.find("date", pos + 1);
    }
    
    //**************************************************************************************************

    int i = 0;
    comand = comand * 2;
    int tam = comand / 2;
    int salto = (tam * (x -1)) + comand;
    
   
    i = salto;
    it = ingresar.begin();
    //******************************identifico que elemnto es y en que fila********************************
    advance(it, salto);
    while (i < ingresar.size())
    {
        

        std::string& s(*it);
        if (s == fila)
        {
            s = dato;
            break;
        }
            
        advance(it, 1);
        i++;
        
    }
    //*************************************************************************************************






    lista.clear();

    it = ingresar.begin();
    i = 0;
    
    while (i < comand) 
    {       
        lista.push_back(*it);
        advance(it, 1);
        i++;
    }
            
    lista.push_front(name);
    lista.push_front(command);

       
    tipos();
    create(1);
    //**********************************************************se creo la tabla de remplazo****************
    datos.clear();
    temporal.clear();
    type.clear();

    int tem = 0;
    int tem2 = 0;
    int counter = 0;
    
    i = comand;
    it = ingresar.begin();
    advance(it, comand);
    while (i < ingresar.size())
    {
        type.push_back(*it);
        advance(it, 1);
        
        i++;
    }
    ingresar.clear();
    lista.clear();


    //***************************************************inserto los elemnto saltando la primera fila************************************
    verificador = 0;
    while (tem2 < type.size())
    {
        list<string> ::iterator t = type.begin();
        if (tem == (comand / 2))
        {
            lista.push_front(name);
            lista.push_front(command);
            insertar();
            lista.clear();
            tem = 0;

        }
        advance(t, tem2);
        lista.push_back(*t);
        tem++;
        tem2++;
    }

    verificador = 1;
    
    //**************************************************************************************************************************************
    
    
    
}

void commands(list<string> x)
{

    if (C1 == (x.front()))
    {
        create(0);
        //cout << "crea\n";
    }
    if (C2 == (x.front()))
    {
        insertar();
        //cout << "insert\n";
    }
    if (C3 == (x.front()))
    {
        elim();
    }
    if (C4.compare(x.front()) == 0)
    {
        list<string>::iterator it = lista.begin();
        for (it = lista.begin(); it != lista.end(); it++)
            temporal.push_back(*it);
        
        lista.clear();
        int counter = 0;
        list<string>::iterator temp = temporal.begin();
        advance(temp, 1);
        string name = *temp;
        advance(temp, 2);
        string id = *temp;
        temp = temporal.begin();
        lista.push_back(*temp);
        lista.push_back(name);
        lista.push_back(id);
     
        temporal.clear();
        select();
    }

    if (C5 == (x.front()))
    {
        list<string>::iterator it = lista.begin();
        string comand = *it;
        advance(it, 1);
        string name = *it;
        advance(it, 2);
        string fila = *it;
        advance(it, 2);
        string dato = *it;
        advance(it,4);
        string id = *it;
        lista.clear();
        lista.push_back(comand);
        lista.push_back(name);
        lista.push_back(fila);
        lista.push_back(dato);
        lista.push_back(id);


        modificar();
        cout << "mod\n";
    }
    if (C6 == (x.front()))
    {
        eliminarTab();
    }
    //else { cout << "SYNTAX_ERROR: COMAND NOT FOUND"; }


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


        //**********************************************limpio memoria******************************
        lista.clear();
        type.clear();
        temporal.clear();
        ingresar.clear();
        datos.clear();
        //system("cls");

    }

}


