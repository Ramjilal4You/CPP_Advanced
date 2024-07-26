/*
** Q 1. Write a C++ program to create a new text file and write some text into it.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream out_file;  //1. create file pointer
    out_file.open("Q01.txt");   //2. create\open file
    if(!out_file.is_open()){
        cout<<"Failed to open the file.\n";
        return 1;
    }

    //3. take input from console & write into file
    while(out_file){
        string line;
        cout<<"Enter input : ";
        cin>>line;  //take input from console

        if(line=="1")
            break;
        out_file<<line<<"\n";   // write into file
    }

    out_file.close();

    return 0;
}