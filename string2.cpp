#include<bits/stdc++.h>
using namespace std;
#define T 10000
int main()
{
    char s1[T],*p=s1;
    int sum=0;
    cin>>s1;
    while(strstr(p,"a")){
        p++;
        sum++;
    }
    cout<<sum;
    return 0;
}