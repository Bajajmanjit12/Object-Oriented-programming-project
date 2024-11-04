#include<iostream>
using namespace std;

class person
{

public:
    int id,sal;
    string name,ds;
    
    //pure virtual function
    virtual void accept()=0;
    virtual void display()=0;
};

class doctor : public person
{
    public:
    void accept();
    void display();
};

class staff : public person
{
    public:
    void accept();
    void display();
};
class patient : public person
{
    int bill;
    public:
    void accept();
    void display();
};

void doctor :: accept()
{
    cout<<"\nEnter the name,id,salary,designation [DOCTOR]";
    cin>>name>>id>>sal>>ds;
}

void staff :: accept()
{
    cout<<"\nEnter the name,id,salary,designation [ASTAFF]";
    cin>>name>>id>>sal>>ds;
}

void patient :: accept()
{
    cout<<"\nEnter the name,id,bill,designation [PATIENT]";
    cin>>name>>id>>bill>>ds;
}

void doctor :: display()
{
    cout<<name<<"\t"<<id<<"\t"<<sal<<"\t"<<ds<<"\n";
}

void staff :: display()
{
    cout<<name<<"\t"<<id<<"\t"<<sal<<"\t"<<ds<<"\n";
}

void patient :: display()
{
    cout<<name<<"\t"<<id<<"\t"<<bill<<"\t"<<ds<<"\n";
}

int main()
{
    doctor d;
    staff s;
    patient p;

    d.accept();
    d.display();
    s.accept();
    s.display();
    p.accept();
    p.display();
}