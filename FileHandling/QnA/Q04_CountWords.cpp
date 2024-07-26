/*
** Q 4. Write a C++ program to count the number of words in a text file.
*/

#include <iostream> //cout, cin
#include <fstream>  //ofstream, ifstream, fstream 
#include <string>   //string
#include <sstream>  //stringstream


using namespace std;

//count words
int countWords(string str){
    stringstream ss(str);
    string word;
    int count=0;
    while(ss>>word){
        count++;
        cout<<word<<" ";
    }
    return count;
}

//count words
int CountWordsUsingGetline(string str){
    stringstream ss(str);
    int count=0;
    string word;
    while(getline(ss,word,' ')){
        cout<<word<<" ";
        count++;
    }
    return count;
}

int main(){
    ifstream file_in("Q04_CountWords.txt"); //open
    if(!file_in.is_open()){
        cout<<"Error : Failed to open!\n";
        return 0;
    }

    string line;
    int count=0;
    while(getline(file_in,line)){
        //count += countWords(line);
        count += CountWordsUsingGetline(line);
    }
    file_in.close(); //close file

    cout<<"\n\nNumber of Words in file : "<<count<<"\n\n\n";

return 0;
}