#include<iostream>
#include<algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() 
{
    string my_str; ;

    getline(cin, my_str);
    cout << "string ingresado: " << my_str << endl;

    my_str.erase(remove(my_str.begin(), my_str.end(), '('), my_str.end()); 
    my_str.erase(remove(my_str.begin(), my_str.end(), ','), my_str.end()); 
    my_str.erase(remove(my_str.begin(), my_str.end(), ')'), my_str.end()); 

    cout << "string despues de eliminar: " << my_str;
}