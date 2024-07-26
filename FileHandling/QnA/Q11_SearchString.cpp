/*
** Write a C++ program to search for a specific string in a text file and display its line number(s)
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    //open file
    ifstream file_in("Q11_SearchString.txt");
    if(!file_in.is_open()){
        cout<<"ERROR : Failed to open file\n";
        return 0;
    }

    //read file line by line
    string searchKey = "Ram";
    string line;
    int lineNumber=0;
    while(getline(file_in,line)){
        lineNumber++;
        if(line.find(searchKey)!=string::npos){
            cout<<"\nFound the search string in file at line number "<<lineNumber<<endl;
        }
    }

    //close file
    file_in.close();

return 0;
}