#include<iostream>
using namespace std;

int main(){
    
    int a[1000], n, i, j;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"\nEnter elements: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }

    cout<<"\nThe array after sorting: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
