/*
** Write a C++ program to encrypt the contents of a text file using a simple encryption algorithm.
** Just increase the ascii value by 1 of each character
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void EncryptFileContent(string srcFilename, string encryptFile){
    //open files
    ifstream file_in(srcFilename);
    ofstream file_out(encryptFile);

    if(!file_in.is_open() || !file_out.is_open()){
        cout<<"ERROR : Failed to open file.\n";
        return;
    }

    //read, encrypt & write to file 
    char ch;
    while(file_in.get(ch)){ //read from src file
        ch++;               // encrypt
        file_out.put(ch);   //write to dst file
    }

    file_in.close();
    file_out.close();
}

int main(){
    
    EncryptFileContent("Q11_SearchString.txt","Q12_EncryptContent.txt");

return 0;
}