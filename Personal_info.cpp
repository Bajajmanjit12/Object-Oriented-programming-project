#include<iostream>
#include<string.h>
using namespace std;
int i,n;
//data encapsulation
class info                   //class 
{
    static int count;     //static variable
    int dob,ht,wt,pn;
    long int cn;
    char *name,*bg,*add,*dln;  //ptr var

    public:
    info()            //constructor default
    {
        name=new char;
        add=new char;
        bg=new char;
        strcpy(name,"No_data");
        strcpy(add,"No_data");
        dob=111111;
        ht=10;
        wt=10;
        pn=100;
        cn=1111111111;
        strpcy(dln,"dl000");
        strcpy(bg,"O+ve");
    }

    static void displaycnt()       //static memeber function
    {
        cout<<"Total Number of Records:"<<count;
    }

    void accept();
    void display()           //inline function
    {
        cout<<name<<"\t"<<add<<"\t"<<dob<<"\t"<<ht<<"\t"<<wt<<"\t"<<pn<<"\t"<<cn<<"\t"<<dln<<"\t"<<bg<<endl;

    }
    
}p[100];      //object

void info ::accept()
{
    count++;
    cin>>name>>add>>dob>>ht>>wt>>pn>>cn>>dln>>bg;
    
}

int main()
{
    int choice;

    cout<<"\nEnter the Number of records:";
    cin>>n;

    cout<<"\n1.Accept\n2.Display\n3.Displaycount\n4.Search\n0.Exit\n";
    cout<<"Enter your choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:cout<<"Name\t"<<"Address\t"<<"DOB\t"<<"Height\t"<<"Weight\t"<<"Policy\t"<<"Con_no\t"<<"DLN\t"<<"Blood group\n";
                for( i=0;i<n;i++)
                {
                    p[i].accept();
                }
                break;
        case 2:cout<<"Name\t"<<"Address\t"<<"DOB\t"<<"Height\t"<<"Weight\t"<<"Policy\t"<<"Con_no\t"<<"DLN\t"<<"Blood group\n";
                for( i=0;i<n;i++)
                {
                    p[i].display();
                }
                break;
        case 3: p[i].displaycnt();break;
        
        default:cout<<"\nInvalid choice\n";

    }
}