//Programm to understand the file handling

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write_file1(string file){
    // by default ios::out mode, automatically deletes the content of file.
    // To append the content, open in ios:app
    ofstream file_out(file, ios::app); //1. open/create file
    if(!file_out){
        cout<<"Error : File could not open."<<endl;
        return;
    }  

    //2. write into file
    while(1){
        string line;
        cout<<"Enter input line: ";
        getline(cin, line);    //take input from console

        if(line=="1")    //stop taking input
            break;

        file_out<<line<<endl;    //write into file
    }

    file_out.close();   //3. close file
}

void read_file1(string file){
    ifstream file_in;
    file_in.open(file); //1. open file
    if(!file_in){
        cout<<"Error : Could not open the file.";
        return;
    }


    //2. read into file
    string line;
    while(getline(file_in, line)){  //read file
        cout<<line<<endl;
    }

    file_in.close();   //3. close file
}

void read_write_file1(string file){
    cout<<"+INFO : read_write_file1()\n";

    fstream fio;    // Creation of fstream class object

    // by default openmode = ios::in|ios::out mode, Automatically overwrites the content of file
    // To append the content, open in ios:app
    // ios::trunc mode delete all content before open
    fio.open(file,ios::in|ios::out|ios::ate);
    if(!fio){
        cout<<"Error : File could not open."<<endl;
        return;
    }

    //fio.seekp(0,ios::beg);  //take write pointer to starting
    while(1){
        string line;
        cout<<"Enter Input line: ";
        getline(cin,line);
        if(line=="1")
            break;

        fio<<line<<endl;
    }

    cout<<"\nOutput from file\n";
    // point read pointer at beginning of file
    fio.seekg(0,ios::beg);
    while(fio){ // Execute a loop until EOF (End of File)
        string line;
        getline(fio,line);
        cout<<line<<endl;
    }

    fio.close();
}

//Q: write a single file handling program in c++ to reading and writing data on a doc file.
void example1(){
	int rno,fee;
	char name[50];

	cout<<"Enter the Roll Number:";
	cin>>rno;
	
	cout<<"\nEnter the Name:";
	cin>>name;
	
	cout<<"\nEnter the Fee:";
	cin>>fee;

	ofstream fout("student.doc",ios::app);
    if(!fout){
        cout<<"Error : Could not open the file in write mode.\n";
        return;
    }

	fout<<rno<<"\t"<<name<<"\t"<<fee<<endl; //write data to the file student

	fout.close();

	ifstream fin("student.doc");
    if(!fin){
        cout<<"Error : Could not open the file in read mode.\n";
        return;
    }

    while(fin){
	    fin>>rno>>name>>fee; //read data from the file student
        cout<<"\nrno : "<<rno<<"\tname : "<<name<<"\tfee : "<<fee;
    }
	fin.close();
}

void writeDataIntoFile(fstream &out){
    cout<<"INFO : writeDataIntoFile()\n";
    cout<<"Current Position (Write pointer) : "<<out.tellp()<<endl;
    while(!out.eof()){
        string line;
        cout<<"Enter input data : ";
        cin>>line;  //take input from console

        if(line=="1")   //stop taking input from console
            break;

        out<<line<<endl;  //write into file
    }
}
void readDataFromFile(fstream &in){
    cout<<"INFO : readDataFromFile()\n";
    string line;
    cout<<"Current Position (Read pointer) : "<<in.tellg()<<endl;
    in.seekg(0,ios::beg);   //take read cursor/pointer to starting
    while(getline(in,line)){    //read from file
        cout<<line<<endl;  //write onto console
    }
}

void readDataFromFile(ifstream &in){
    cout<<"INFO : readDataFromFile(ifstream &in)\n";
    string line;
    cout<<"Current Position (Read pointer) : "<<in.tellg()<<endl;
    in.seekg(0,ios::beg);   //take read cursor/pointer to starting
    while(getline(in,line)){    //read from file
        cout<<line<<endl;  //write onto console
    }
}

//  File operations
void read_write_file2(string file){
    fstream fio;    //create fstream object
    fio.open(file,ios::in|ios::out|ios::app);   //open/create file
    if(!fio){
        cout<<"ERROR : File could opened.\n";
        return;
    }
    writeDataIntoFile(fio); //write into file
    readDataFromFile(fio);  //read from file

    cout<<"\npeek()\n";
    fio.seekg(0,ios::beg);
    int c = fio.peek();
    while(c!=EOF){
        if(isdigit(c)){
            int x;
            fio>>x;
            cout<<"digit : "<<x<<endl;
        }else{
            string line;
            fio>>line;
            cout<<"string : "<<line<<endl;
        }
    }
    fio.close();
}

//reads the character/word from the input stream without extracting it.
//does not increase the position
void peek_example(string file){
    cout<<"INFO : peek_example()\n";
    ifstream fin(file);
    cout<<"Current Position (Read pointer) : "<<fin.tellg()<<endl;
    int c = fin.peek();
    if (c==EOF){
        cout<<"EOF\n";
        return; 
    }
    if(isdigit(c)){
        int x;
        fin>>x;
        cout<<"Digit : "<<x<<endl;
    }
    else{
        string str;
        fin>>str;
        cout<<"String : "<<str<<endl;
    }

    fin.close();
}

void seekp1 (string file)  
{ 
    //create a text file named file before running. 
    cout<<"\nseekp1() : Opening file : "<<file<<endl;
    ofstream ofile; 
    ofile.open (file); 
      
    ofile<< "geeksforgeeks\n"; 
    ofile.seekp (8); //move write pointer
    ofile<< " NewString\n"; 
      
    ofile.close(); 

    ifstream ifile(file);
    readDataFromFile(ifile);
    ifile.close();

} 

void ignore1 (string file)  
{ 
    ifstream ifile; 
    ifile.open (file); 
      
    //content of file: geeksfor geeks 
    char last; 
    ifile.ignore (256, ' ');  //extract/ignore 1st 256 chars or till the space
    last = ifile.get();      //extracts single character
      
    cout << "New First Char is " << last << '\n';
    string str;
    getline(ifile,str); //extracts single line
    cout<<str; 
    ifile.close(); 
} 

//check existane, file size, file rename, file remove file
void FileHandlingHacks(string file){
    //1. check existane
    ifstream fi(file);  //open in write mode will create new file, if not existed
    if(!fi){
        cout<<"File does not exist.\n";
    }
    else{
        cout<<"file is exist & opened.\n";
    }

    //2. file size
    fi.seekg(0, ios::end);  //set read ptr to end
    long n = fi.tellg();
    cout<<"File size : "<<n<<" Bytes\n";

    //rename(file.c_str(), "NewName.txt");

}

int main(){
    string file_name = "testfile1.txt";

    //write_file1(file_name);

    //read_file1(file_name);

    string file2 = "testfile2.txt";
    //read_write_file1(file2);
    //read_write_file2("testfile3.txt");

    //example1(); //read/write into docs file

    //peek_example("testfile3.txt");
    
    //seekp1("seekp1.txt");
    //ignore1("seekp1.txt");

    FileHandlingHacks("testfile3.txt");

    return 0;
}
