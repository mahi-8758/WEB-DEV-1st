#include<iostream>
#include<cstring>
using namespace std;
 
class Person{
   int id;
   char name[100];
   public:
   Person(){
      cout<<"Person Constructor Called"<<endl;
      id=0;
      strcpy(name,"");
   }

   ~Person(){
      cout<<"Person Destructor Called"<<endl;
   }
   void setp(){
      cout<<"Enter ID: ";
      cin>>id;
      cout<<"Enter Name: ";
      cin>>name;
   }
   void display(){
      cout<<"ID: "<<id<<endl;
      cout<<"Name: "<<name<<endl;
   }
   


};

int main(){
   Person s1;
   s1.setp();
   s1.display();

   return 0;
}