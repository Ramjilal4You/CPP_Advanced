/*
** Q05. Write a C++ program to copy the contents of one text file to another.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream file_in("Q04_CountWords.txt");
    if(!file_in.is_open()){
        cout<<"Error : Failed to open input file - Q04_CountWords.txt\n"; return 0;
    }
    ofstream file_out("Q05_CountWords.txt");
    if(!file_out.is_open()){
        cout<<"Error : Failed to open output file - Q05_CountWords.txt\n"; return 0;
    }

    string line;
    while(getline(file_in,line))    //read from src
    {
        file_out<<line<<endl; //write to dst
    }

    file_in.close();
    file_out.close();

    cout<<"\n\nCopying data from Q04_CountWords.txt to Q05_CountWords.txt is done.\n\n";

return 0;
}

/*
1. open src file
2. open dst file
3. read from src
4. write to dst
5. close src
6. close dst
*/