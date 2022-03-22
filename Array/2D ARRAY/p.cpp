#include<iostream>
using namespace std;
int main()
{   int a[100];
    int i;
    int j;
    int temp;
    int s;
     int ct=0;
    cout<<"Enter the array size";
    cin>>s;
    cout<<"Enter the array elements";
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<s-1;i++)
    {
        for(j=0;j<s-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            //break;

        }

    }
    cout<<"The elements are";
    for(i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"enter k";
    int k;
    cin>>k;
    for(i=0;i<s;i++)
    {  if(i==k-1)
        {cout<<"the small value is ";
         cout<<a[i];
        }
    }
    for(i=s-1;i>=0;i--)
    {
       // cout<<"The elements are";
        cout<<a[i]<<endl;
    }

    for(i=s-1;i>=0;i--)
    {
        ct++;
        if(k==ct)
        {
            cout<<a[k];
            cout<<"largest element"<<endl;
        }

    }
}
