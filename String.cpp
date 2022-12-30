#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s1,s2;
    cin>>n>>s1;
    s2=s1.substr(s1.length()-n,n);
    s1.erase(s1.length()-n,n);
    cout<<s2<<s1;
    return 0;
}

