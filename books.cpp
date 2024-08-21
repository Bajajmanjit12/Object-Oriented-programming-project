#include<iostream>
#include<string.h>
using namespace std;
int n,i;
class book
{
    int cost,stockp;
    char *title,*pub,*author;

public:
    void accept();
    void display();
    void search();
    book()
{
    title=new char;
    author= new char;
    pub=new char;

    cost= 100;
    stockp= 1;
    strcpy(title,"No_data");
    strcpy(author,"No_data");
    strcpy(pub,"No_data");

}

~book()
{
    cout<<"\nDestructor is called!!!";

}
 
}b[10];


void book :: accept()
{
    cout<<"Enter the title :";
    cin>>title;
    cout<<"Enter the name of Author :";
    cin>>author;
    cout<<"Enter the name of publisher :";
    cin>>pub;
    cout<<"Enter the cost :";
    cin>>cost;
    cout<<"Enter the stock available :";
    cin>>stockp;
}

void book :: display()
{
    cout<<"\n"<<title<<"\t"<<author<<"\t"<<pub<<"\t"<<cost<<"\t"<<stockp<<"\n";
}
void book :: search()
{
    int cost,cp,flag=0,flag1=0;
    char *t,*a;
    
    t=new char;
    a= new char;
    cout<<"Enter the Title and Nmae of Author of book you want:";
    cin>>t>>a;

    for( i=0;i<n;i++)
    {
        if(strcmp(t,b[i].title)==0 && strcmp(a,b[i].author)==0)
        {
            flag=1;
            cout<<"Book is found!"<<endl;
            b[i].display();

            cout<<"Enter the number of copies you want:";
            cin>>cp;

            if(cp <=b[i].stockp)
            {
                flag1 =1;
                cost=b[i].cost*cp;
                cout<<"\nTotal cost of all books is:"<<cost<<endl;
                break;
            }
        }
    }

    if(flag==1 && flag1==0)
    {
        cout<<"\n Book is available but number of copies are not available.";

    }

    if(flag==0)
    {
        cout<<"Book is not found.";
    }

}
int main()
{
    int choice;
    cout<<"Enter the Total Number of Copies:";
    cin>>n;
    do{
    cout<<"Menu"<<endl;
    cout<<"\n1.Accept\n2.Display\n3.Search\n0.Exit\n"<<endl;
    cout<<"Enter Your Choice";
    cin>>choice;

    switch(choice)
    {
        case 1:for( i=0;i<n;i++)
                {
                    b[i].accept();
                }
                break;

        case 2: cout<<"\n"<<"Title"<<"\t"<<"Author"<<"\t"<<"Publisher"<<"\t"<<"Cost"<<"\t"<<"Stock\n"<<endl;
                for( i=0;i<n;i++)
                {
                    b[i].display();
                }
                break;
        case 3: b[i].search();break;
        default :cout<<"Invalid Choice!";break;
    }
    }while(choice !=0);
return 0;
}
