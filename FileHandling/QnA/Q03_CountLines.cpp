/*
** 3. Write a C++ program to count the number of lines in a text file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream file_in("Q01.txt");
    if(!file_in.is_open()){
        cout<<"Failed to open file\n";
        return 0;
    }

    int line_count=0;
    string line;
    while(getline(file_in,line)){
        line_count++;
        cout<<line<<"\n";
    }

    file_in.close();
    
    cout<<"Number of lines : "<<line_count<<endl;

    return 0;
}