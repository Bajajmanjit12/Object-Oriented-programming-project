#include<iostream>
using namespace std;
class Complex
{
    float real,img;
    public:
    Complex()
    {
        real=0.0;
        img=0.0;
    }

    Complex(float rr,float ii)
    {
        real=rr;
        img=ii;
    }
    
    Complex operator+(Complex);
    Complex operator-(Complex);
    friend Complex operator*(Complex, Complex);
    Complex operator/(Complex);

    void display()
    {
        if(img>=0)
        {
            cout<<real<<"+"<<img<<"i"<<endl;
        }
        else{
            cout<<real<<img<<"i"<<endl;
        }
    }

}c1,c2,c3;

Complex Complex :: operator +(Complex c2)
{
    c3.real=real + c2.real;
    c3.img=img + c2.img;

    return c3;
} 
Complex Complex :: operator -(Complex c2)
{
    c3.real=real - c2.real;
    c3.img=img - c2.img;

    return c3;
} 

Complex operator*(Complex c1, Complex c2)
{
    c3.real=c1.real * c2.real - c1.img * c2.img;
    c3.img = c1.real * c2.img + c2.real * c1.img;
    return c3;

}

Complex Complex :: operator/(Complex c2)
{
    c3.real=(real * c2.real + img *c2.img)/(c2.real*c2.real + c2.img*c2.img);
    c3.img=(-real * c2.img + img  * c2.real)/(c2.real*c2.real + c2.img*c2.img);
    return c3;
} 

int main()
{
    int choice;
    float r,i;
    cout<<"\nEnter the first complex number:";
    cin>>r>>i;
    Complex c1(r,i);
    cout<<"\nEnter the second complex number:";
    cin>>r>>i;
    Complex c2(r,i);

    c1.display();
    c2.display();
    do{
    cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n0.exit\n";
    cout<<"\nEnter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1: c3=c1+c2;
                c3.display();break;
        case 2: c3=c1-c2;
                c3.display();break;
        case 3: c3=c1*c2;
                c3.display();break;
        case 4: c3=c1/c2;
                c3.display();break;
        case 5: cout<<"\nInvalid Choice.";break;
    }
    }while(choice!=0);
}