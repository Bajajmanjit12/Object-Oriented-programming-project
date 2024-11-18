//create a function template that can sort array of various type such as int,float,char
#include<iostream>
using namespace std;
int n;
template<class T>

void sel_sort(T arr[])
{
    T temp;
    cout<<"\nEnter the array size:";
    cin>>n;
    cout<<"\nEnter array elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"\nSorted array elements are:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }

}

int main()
{
    int a[10];
    float b[10];
    char c[10];

    int choice;
    do{
    cout<<"\n1.Integer\n2.Float\n3.Character\n";
    cout<<"\nEnter your Choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:
        sel_sort(a);
        break;

        case 2:
        sel_sort(b);
        break;

        case 3:
        sel_sort(c);
        break;

        default: cout<<"\nInvalid choice!"; break;
    }
    }while(choice != 0);

    return 0;
}
