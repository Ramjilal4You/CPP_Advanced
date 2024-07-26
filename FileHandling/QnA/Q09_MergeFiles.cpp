/*
** Write a C++ program to merge multiple text files into a single file.
* Q08_SortLines.txt + Q08_SortLines_sorted.txt = Q09_MergeFiles.txt
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //open src files
    ifstream ifile1("Q08_SortLines.txt"), ifile2("Q08_SortLines_sorted.txt");
    if(!ifile1.is_open() && !ifile2.is_open()){
        cout<<"ERROR : Failed to open src file.\n";
        return 0;
    }

    //open dst files
    ofstream ofile("Q09_MergeFiles.txt");
    if(!ofile.is_open()){
        cout<<"ERROR : Failed to open dst file.\n";
        return 0;
    }

    //merge

    string line1, line2;
    while(getline(ifile1,line1)||getline(ifile2,line2)){
        if(!line1.empty())
            ofile<<line1<<"\n";
        if(!line2.empty())
            ofile<<line2<<"\n";
    }

    //close all files
    ifile1.close();
    ifile2.close();
    ofile.close();

return 0;
}