/*
** Write a C++ program to split a large text file into smaller files of equal size.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void SplitFile(string &srcFileName, string &dstPrefix, int outputFileCount){
    ifstream file_in(srcFileName, ios::binary);    //open src file in binary mode
    if(!file_in.is_open()){
        cout<<"ERROR : Failed to open "+srcFileName+" file.\n";
        return;
    }
    else{
        cout<<"INFO : "+srcFileName+" file opened.\n";
    }

    //calculate src file size
    file_in.seekg(0,ios::end); //move file pointer to end
    streamsize srcFileSize = file_in.tellg();   //tell the current file pointer position
    file_in.seekg(0,ios::beg); //move file pointer to begining

    cout<<"INFO : "+srcFileName+" file size is : "<<srcFileSize<<" bytes.\n";
    
    //calculate output file size
    streamsize outPutFileSize = srcFileSize/outputFileCount;

    cout<<"INFO : Output file size will be : "<<outPutFileSize<<" bytes each.\n";

    for(int i=1;i<=outputFileCount;i++){
        string dstFileName = dstPrefix + to_string(i) +".txt";
        ofstream file_out(dstFileName, ios::binary);    //open dst file in binary mode
        if(!file_out.is_open()){
            cout<<"ERROR : Failed to open "+dstFileName+" file.\n";
            continue;   //check for next file
        }
        else{
            cout<<"INFO : "+dstFileName+" file created/opened.\n";
        }

        //read data from input file & write it to output file
        vector<char> buffer(outPutFileSize);    //buffer size should be given at creation only
        file_in.read(buffer.data(), outPutFileSize); //read from src file 

        file_out.write(buffer.data(),file_in.gcount());    //write from buffer, gcount:number of read character

        file_out.close();   //close output file
    }

    file_in.close();    //close src file
    cout<<"\nSplit is done into "+to_string(outputFileCount)+" files of size "+to_string(outPutFileSize)+" bytes.\n\n\n";
}

int main(){
    string srcFileName("Q10_SplitFile.txt");
    string outFile_Prefix("Q10_Splitted_");
    int outPutFileCount=3;
    SplitFile(srcFileName,outFile_Prefix,outPutFileCount);

return 0;
}