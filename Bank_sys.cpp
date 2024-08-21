#include<iostream>
using namespace std;

int n;

class MyBank
{
    int Account_no,Bal_amount;
   string name;

    public:
    void accept();
    void display();
    void withdraw();
    void deposit();

    MyBank()
 {
    Account_no= 0;
    Bal_amount= 0;
    name="no_data";

}

    
} B[100];
 
void MyBank :: accept()
{
    cout<<"\nEnter the Account No.:";
    cin>>Account_no;
    cout<<"Enter the Name of Account Holder:";
    cin>>name;
    cout<<"Enter the balance amount:";
    cin>>Bal_amount;
}

void MyBank :: withdraw()
{
    int w_amount, Acc, flag = 0;
    cout<<"Enter the Account No.:";
    cin>>Acc;

    for(int i = 0; i < n; i++)
    {
        if(B[i].Account_no == Acc)
        {
            flag = 1;
            cout<<"Enter the amount to Withdraw:";
            cin>>w_amount;
            if(w_amount <= B[i].Bal_amount)
            {
                B[i].Bal_amount = B[i].Bal_amount - w_amount;
                cout<<"\nCurrent Balance amount After withdraw is : "<<B[i].Bal_amount<<endl;  
            }
            else
            {
                cout<<"Your Current Balance is Insufficient!\n";
            }
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"Account Does not Exist!"<<endl;
    }
}

void MyBank :: deposit()
{
    int d_amount, Acc, flag = 0;
    cout<<"Enter the Account No.:";
    cin>>Acc;

    for(int i = 0; i < n; i++)
    {
        if(B[i].Account_no == Acc)
        {
            flag = 1;
            cout<<"Enter the amount to Deposit:";
            cin>>d_amount;
            B[i].Bal_amount = B[i].Bal_amount + d_amount;
            cout<<"\nCurrent Balance amount After deposit is : "<<B[i].Bal_amount<<endl;  
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"Account Does not Exist!"<<endl;
    }
}

void MyBank :: display()
{
    cout<<Account_no<<"\t\t"<<name<<"\t\t"<<Bal_amount<<endl;
}

int main()
{
    int choice;
    cout<<"Enter the Number of records: ";
    cin>>n;
    cout<<endl;
    do{
        cout<<"1. Accept\n2. Display\n3. Withdraw\n4. Deposit\n0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                for(int i = 0; i < n; i++)
                {
                    B[i].accept();
                }
                break;

            case 2:
                cout<<"\t*** RECORDS ***\t\n";
                cout<<"ACCOUNT NO.\tNAME\tBALANCE AMOUNT\n";
                for(int i = 0; i < n; i++)
                {
                    B[i].display();
                }
                break;

            case 3:
                B[0].withdraw();  
                break;

            case 4:
                B[0].deposit();  
                break;

            default:
                cout<<"Invalid choice\nExiting....\n";
                break;
        }
    } while(choice != 0);

    return 0;
}
