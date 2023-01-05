#include<bits/stdc++.h>
using namespace std;
typedef struct 
{
    int x ;
    char y [30];
    /* data */
}toy;
int main()
{
    int m,n,i=1,j=0,k=1,sum=0,b,c;
    cin>>n>>m;
    toy a[n+1];
    while(i<=n){
        cin>>a[i].x>>a[i].y;
        i++;
    }
    // 规定逆时针为正，顺时针为负，向里右为正，左为负，向外右为负，左为正；
    while(j<m){
        cin>>b>>c;
        if(a[k].x==0){
            if(b==0){
                k-=c;
            }
            else{
                k+c;
            }
            k%=n;
            if(k<=0){
                k+=9;
            }
        }
        else{
            if(b==1){
                k-=c;
            }
            else{
                k+=c;
            }
            k%=n;
            if(k<=0){
                k+=9;
            }
        }
        j++;
    }
    printf("%s",a[k].y);
    return 0;
}