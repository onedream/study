#include<bits/stdc++.h>
using namespace std;
int main()
{
    // int x,y,i=0,j=0,a[500001];
    // cin>>x>>y;
    // while (i++<x){
    //     cin>>a[j++];
    // }
    // sort(a,a+x,greater<int>());
    // cout<<a[j-y-1];
    // 最优解
    int x[50000],a,b,i=0,j=0;
    cin>>b>>a;
    while(i++<b){
        // cin>>x[j++];cin速度较慢
        scanf("%d",&x[j++]);
    }
    nth_element(x,x+a,x+b);
    cout<<x[a];
    return 0;
}