/*
** Write a C++ program to append new data to an existing text file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //open exiting file in write append mode
    ofstream file_out("Q07_Append.txt", ios::app);
    if(!file_out.is_open()){
        cout<<"Error : File could not open.\n";
        return 0;
    }
    file_out<<"Append text";

    file_out.close();
return 0;
}