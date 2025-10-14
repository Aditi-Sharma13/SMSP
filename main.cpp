#include<iostream>
#include<fstream>
using namespace std;
class student{
    int roll;
    float marks;
    string name;
    string course;

    public:

    void input(){
        cout<<"ENTER ROLL NO : ";
        cin>>roll;
        cin.ignore();
        cout<<"ENTER YOUR NAME : ";
        getline(cin,name);
        cout<<"ENTER MARKS : ";
        cin >>marks;
        cin.ignore();
        cout<<"ENTER COURSE NAME : ";
        getline(cin,course);
        //TAKES DETAILS OF ASTUDENT AS INPUT 
    }
    void display(){ 
        cout<<" CONFIRM YOUR DETAILS :";
        cout<<"\nROLL NO. : "<<roll;
        cout<<"\nNAME : "<<name;
        cout<<"\nMARKS : "<<marks;
        cout<<"\nCOURSE : "<<course;
        //DISPLAY DETAILS
    }
    void add(){
        ofstream fout("data.txt",ios::app);
        if(!fout){
            cout<<"ERROR IN OPENING A FILE";
        }
        //WRITE 
        fout<<roll<<","<<name<<","<<marks<<","<<course<<endl;
        fout.close();
        cout<<"\nSUCCESSFULLY ADDED";
    }
    void displayall(){
        ifstream fin("data.txt");
        if(!fin){
            cout<<"ERROR FILE NOT FOUND" ;    
        return;   }
            cout<<"ALL STUDENTS RECORDS ARE HERE : \n";
            string line;
            while(getline(fin,line)){
                cout<<line<<endl;//DISPLAYS ALL THE RECORDS OF FILE DATA
            }
            fin.close();
    }

    void search(){
        ifstream fin("data.txt");
        if(!fin){
            cout<<"ERROR FILE NOT FOUND";
            return;
        }
        //SEARCH FOR A STUDENT RECORD VIA ROLL NO.

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
    return;

}
fin.close();
    }
    
    void update(){
        ifstream fin("data.txt");
        ofstream fout("new.txt");
        if(!fin || !fout){
            cout<<"ERROR FILE NOT FOUND";
            return;
        }
        int updates;
        cout<<"ENTER ROLL NO. OF A STUDENT WHOSE RECORD YOU WANT TO UPDATE";
        cin>>updates;

        string line;
        bool  found=false;
        while(getline(fin,line)){
            int fileroll=stoi(line.substr(0,line.find(',')));
            if (fileroll==updates){
                cout<<"ENTER UPDATED DETAILS ";
                input();//TAKES ALL DETAILS AGAIN 
                fout<<roll<<","<<name<<","<<marks<<","<<course<<endl;
                found=true;

            }
            else{
                fout<<line<<endl;

            }
        }
        fin.close();
        fout.close();
        remove("data.txt");// REMOVES THE FILE
        rename("new.txt","data.txt");//RENAMES "NEW" FILE TO "DATA FILE"
        if (found){
            cout<<"RECORD HAS BEEN UPDATED SUCCESSFULLY";
            return;
        }
        else{
            cout<<"RECORD NOT FOUND";
        }

    }



    void deleterec(){
        ifstream fin("data.txt");
        ofstream fout("new.txt");
        if(!fin || !fout){
            cout<<"ERROR FILE NOT FOUND";
            return;
        }
        //DELETE THE RECORD OF A STUDENT VIA ROLL NO.
        int searchroll;
        cout<<"ENTER ROLL NO. OF THE STUDENT WHOSE RECORD YOU WANT TO DELETE";
        cin>>searchroll;
         string line ;
         bool found=false;

         while(getline(fin,line)){
            int fileroll=stoi(line.substr(0,line.find(',')));
            if(searchroll != fileroll){
                fout<<line<<endl;
            }
            else{
                cout<<"RECORD DELETED SUCCESSFULLY";
                found=true;
                continue;
            }
            

         }
         fin.close();
         fout.close();
         remove("data.txt");
         rename("new.txt","data.txt");
         if (!found){
            cout<<"RECORD NOT FOUND";
            return;
         }


     }
};
int main()
{ int choice,again;
    do{
        //DISPLAYS A MENU OF ACTIONS

cout<<"--------------------------------";
cout<<"\nSTUDENT MANAGEMENT SYSTEM";
cout<<"--------------------------------";
cout<<"\n1. ADD NEW STUDENT ";
cout<<"\n2. DISPLAY ALL STUDENT ";
cout<<"\n3. DELETE RECORD OF A STUDENT  ";
cout<<"\n4. SEARCH A STUDENT ";
cout<<"\n5. UPDATE RECORD OF A STUDENT";
cout<<"\n----------------------------------------";
cout<<"\nENTER HERE: ";
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
    case 3 :{
        student s;
        s.deleterec();
        break;
    }
    case 4 :{
        student s;
        s.search();
        break;
    }
    case 5 :{student s ;
           s.update();
           break;}
    default : cout<<"INVALID CHOICE";

}cout<<"\n\nENTER 1 TO USE AGAIN OR 0 TO EXIT : ";
    cin>>again;
    
        }
    
    
    while(again ==1);
}