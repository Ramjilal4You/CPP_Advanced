/*
** Write a C++ program to read a CSV file and display its contents in tabular form.
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

void RemoveCommaFromString(string &line, vector<string> &Tokens){
    stringstream ss(line);
    string token;
    while (getline(ss,token,','))   //split string by comma seperated
    {
        Tokens.push_back(token);
    }
    return;
}

int main(){
    //open file
    ifstream file_in("Q14_CSVFile.csv");
    ofstream file_out("Q14_CSVFile.txt");
    if(!file_in.is_open() || !file_out.is_open()){
        cout<<"ERROR : Failed to open file.\n";
        return 0;
    }

    //read & write to file
    string line;
    while (getline(file_in,line)){  //read from csv file, line comes with comma
        vector<string> tokens;
        RemoveCommaFromString(line,tokens);
        for(string token:tokens){
            file_out<<token<<"\t\t";
            cout<<token<<"\t\t";
        }
        file_out<<"\n";
        cout<<"\n";
    }

    file_in.close();
    file_out.close();
    
return 0;
}