/*
** Write a C++ program to decrypt the contents of a text file encrypted using the above algorithm.
** Just decrease the ascii value by 1 for all characters
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void DecryptFileContent(string srcFile, string dstFile){
    //opne files
    ifstream file_in(srcFile);
    ofstream file_out(dstFile);
    if(!file_in.is_open() || !file_out.is_open()){
        cout<<"ERROR : Failed to open file.\n";
        return;
    }

    //read, decrypt and write to file
    char ch;
    while (file_in.get(ch)){    //read from file
        ch--;                   //decrypt
        file_out.put(ch);       //write to file
    }

    file_in.close();
    file_out.close();
}

int main(){
    
    DecryptFileContent("Q12_EncryptContent.txt", "Q13_DecryptContent.txt");

return 0;
}