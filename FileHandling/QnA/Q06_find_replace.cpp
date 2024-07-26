/*
** Write a C++ program to find and replace a specific word in a text file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void DisplayFileContent(string fileName){
    ifstream file_in(fileName); //open file
    if(!file_in.is_open()){
        cout<<"Error : Failed to open file.\n";
        return;
    }

    //read & print content from file to console
    string line;
    while(getline(file_in,line)){
        cout<<line<<" ";
    }

    //close file
    file_in.close();
}

/*
* fileName, oldWord, newWord : IN
*/
void ReplaceWordInFile(string &fileName, string &searchWord, string &replaceWord, string &fileName_updated){
    cout<<"\n\nINFO : ReplaceWordInFile();\n";
    //open file in read mode
    ifstream file_in(fileName);
    if(!file_in.is_open()){
        cout<<"Error : File could not open.\n";
        return;
    }

    //open file in out mode
    ofstream file_out(fileName_updated);
    if(!file_out.is_open()){
        cout<<"Error : File could not open.\n";
        return;
    }

    //find word to replace
    string line;
    while(getline(file_in,line)){
        size_t pos = line.find(searchWord);    //find searchWord
        while(pos!=string::npos){
            line.replace(pos, searchWord.length(), replaceWord);   //replace
            pos = line.find(searchWord, pos+replaceWord.length());    //find searchWord again in same line
        }
        file_out<<line<<"\n";    //write back to file after replacing word
    }

    file_in.close();
    file_out.close();
    return;
}

int main(){
    string fileName = "Q06_find_replace.txt";
    string fileName_updated = "Q06_find_replace_updated.txt";
    string searchWord = "123";
    string replaceWord = "12345";

    cout<<"\n\nINFO : Content Before Replace\n\n";
    DisplayFileContent(fileName);

    ReplaceWordInFile(fileName, searchWord, replaceWord, fileName_updated);

    cout<<"\n\nINFO : Content After Replace\n\n";
    DisplayFileContent(fileName_updated);

    cout<<"\n\n\n\n";
return 0;
}