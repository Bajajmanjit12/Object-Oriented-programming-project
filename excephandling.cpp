#include<iostream>
using namespace std;

class television
{
    int mno,price,size;

    public:
    friend ostream& operator <<(ostream &dout , television &t);
    friend istream& operator >>(istream &din , television &t);

};

istream& operator >>(istream &din , television &t)
{
    cout<<"\nEnter the model no. , price ,size of television :";
    din>> t.mno >>t.price >> t.size;

    try
    {
        if( t.mno > 9999 || t.price < 0 || t.price > 5000 || t.size <12 || t.size > 70 )
        {
            throw "Invalid";
        }
    }
    catch(const char *e)
    {
        cout<< "\nException Occurred !" <<e;
        t.mno =0;
        t.price=0;
        t.size=0;
    }
    
    return din;
}

ostream& operator <<(ostream &dout , television &t)
{
    dout <<"Model No:" <<t.mno <<endl;
    dout <<"Price :"<<t.price << " $"<<endl;
    dout <<"Size :"<<t.size <<" inches"<<endl;

return dout;
}

int main()
{
    television tv;
    cin >> tv;
    cout << tv;
    return 0;
}
