/*
** Q 2. Write a C++ program to open an existing text file and display its contents on the console.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream file_in;   //1. create file stream variable
    file_in.open("Q01.txt");    //2. open file (if not in open state)
    if(!file_in.is_open()){
        cout<<"Failed to open the file.\n";
        return 0;
    }

    //3. read file
    string str;
    while(getline(file_in,str)){
        cout<<str<<"\n";
    }

    file_in.close();

    return 0;
}