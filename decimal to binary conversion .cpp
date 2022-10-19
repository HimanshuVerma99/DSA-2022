#include<iostream>
#include<math.h>
using namespace std;
int dtubconvertor(int n){
int ans = 0, count = 0;
    while(n!=0)
    {
        int rem = n%2;[edd  ]
        ans += pow(10,count)*rem;
        count++;
        n/=2;
    }
    return ans;
}
int main(){

cout<< dtubconvertor(100);
return 0;
}
