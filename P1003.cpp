#include<bits/stdc++.h>
using namespace std;
#define N 210
int main()
{
    int F[N][N]={-1},x,i,j,q,a,b,g,k;
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    {
        scanf("%d %d %d %d",&a,&b,&g,&k);
        for(j=a;j<b+g;j++)
            for(q=b;q<a+k;q++)
                F[j][q]=i;
    }
    scanf("%d %d",&i,&j);
    printf("%d",F[i][j]);
    return 0;
}