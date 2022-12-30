#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0,sum=0;
    string s1,s2;
    s2="sk";
    cin>>s1;
    while(1){
        n=s1.find(s2,n+s2.length());
        if(n==string::npos)break;
        sum++;
    }
    cout<<sum;
    return  0;
}