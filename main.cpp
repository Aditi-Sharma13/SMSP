1#include<iostream>
#include<fstream>
using namespace std;
class student{
    int roll;
    float marks;
    string name;
    string course;

    public:

    void input(){
        cout<<"ENTER ROLL NO :";
        cin>>roll;
        cin.ignore();
        cout<<"ENTER YOUR NAME :";
        getline(cin,name);
        cout<<"ENTER MARKS :";
        cin >>marks;
        cin.ignore();
        cout<<"ENTER COURSE NAME :";
        getline(cin,course);
        
    }
    void display(){
        cout<<"\nROLL NO."<<roll;
        cout<<"\nNAME"<<name;
        cout<<"\nMARKS"<<marks;
        cout<<"\nCOURSE"<<course;
    }
    void add(){
        ofstream fout("data.txt",ios::app);
        if(!fout){
            cout<<"ERROR IN OPENING A FILE";
        }
        fout<<roll<<","<<name<<","<<marks<<","<<course<<endl;
        fout.close();
        cout<<"\nSUCCESSFULLY ADDED";
    }
    void displayall(){
        ifstream fin("data.txt");
        if(!fin){
            cout<<"ERROR FILE NOT FOUND" ;       }
            cout<<"ALL STUDENTS RECORDS ARE HERE";
            string line;
            while(getline(fin,line)){
                cout<<line<<endl;
            }
            fin.close();
    }

    void search(){
        ifstream fin("data.txt");
        if(!fin){
            cout<<"ERROR FILE NOT FOUND";
        }
        int sroll;
        cout<<"ENTER ROLL NO. TO BE SEARCHED";
        cin>>sroll;
        string line;
        bool found=false;
        while(getline(fin,line)){
            int froll=stoi(line.substr(0,line.find(',')));
            if(froll==sroll){
                cout<<"\nSTUDENT FOUND"<<line<<endl;
                found=true;
                break;
            }
        }
if(!found){
    cout<<"\nSTUDENT NOT FOUND"<<endl;

}
fin.close();
    }
    
};
int main()
{ int choice;
    do{

cout<<"\nSTUDENT MANAGEMENT SYSTEM";
cout<<"\n1. ADD NEW STUDENT ";
cout<<"\n2. DISPLAY ALL STUDENT ";
cout<<"\n3. DELETE RECORD OF A STUDENT  ";
cout<<"\n4. SEARCH A STUDENT ";
cout<<"\n5. UPDATE RECORD OF A STUDENT";
cout<<"\nENTER HERE:";
cin>>choice;
switch(choice){
    case 1 :{
        student s;
        s.input();
        s.display();
        s.add();
        break;
    }
    case 2 :{
        student s;
        s.displayall();
        break;

    }
    case 3 :
    case 4 :{
        student s;
        s.search();
        break;
    }
    case 5 :
    default : cout<<"INVALID CHOICE";

}
    }
    while(choice!=0);





}