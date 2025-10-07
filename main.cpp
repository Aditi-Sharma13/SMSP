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
        cout<<"ENTER ROLL NO :";
        cin>>roll;
        cout<<"ENTER YOUR NAME :";
        cin>>name;
        cout<<"ENTER MARKS :";
        cin >>marks;
        cout<<"ENTER COURSE NAME :";
        cin>>course;
        
    }
    void display(){
        cout<<"\nROLL NO."<<roll;
        cout<<"\nNAME"<<name;
        cout<<"\nMARKS"<<marks;
        cout<<"\nCOURSE"<<course;
    }
};
int main()
{
    cout<<"hii";
}