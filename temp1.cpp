#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int x,y,z;
    cout<<"请输入三个整数";
    cin>>x>>y>>z;
    cout<<max(max(x,y),z);
    return 0;
}