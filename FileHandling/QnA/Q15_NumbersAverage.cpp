/*
** Write a C++ program to calculate the average of numbers stored in a file.
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){
    //open file
    ifstream file_in("Q15_NumbersAverage.txt");

    //read file & store numbers in vector
    double num;
    double avg=0.0;
    int count=0;
    while (file_in >> num){  //read from file
        avg = (avg*count+num)/(count+1);
        count++;
    }

    cout<<"\nAverage : "<<avg<<"\n\n";
    
return 0;
}