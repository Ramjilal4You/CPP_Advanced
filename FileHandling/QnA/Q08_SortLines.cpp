/*
** Write a C++ program to sort the lines of a text file in alphabetical order.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //open file
    ifstream file_in("Q08_SortLines.txt");
    if(!file_in.is_open()){
        cout<<"ERROR : Failed to open file.\n";
        return 0;
    }

    vector<string> vStr;
    string line;
    //read
    while(getline(file_in,line)){
        vStr.push_back(line);
    }

    //close
    file_in.close();

    sort(vStr.begin(),vStr.end());

    //open sorted file
    ofstream file_out("Q08_SortLines_sorted.txt");
    if(!file_out.is_open()){
        cout<<"ERROR : Failed to open file.\n";
        return 0;
    }
    //write
    for_each(vStr.begin(),vStr.end(),[&](string &line){ file_out<<line<<"\n"; });

    //close
    file_out.close();

return 0;
}