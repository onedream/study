#include<stdio.h>
int main()
{
    int n,n1,n2,i=0,j=0,k=0,score1=0,score2=0;
    scanf("%d %d %d",&n,&n1,&n2);
    int N1[n1],N2[n2];
    while(i<n1){
        scanf("%d",&N1[i]);
        i++;
    };
    while(j<n2){
        scanf("%d",&N2[j]);
        j++;
    };
    i=0,j=0;
    while(k<n){
        if(i==n1)i=0;
        if(j==n2)j=0;
        if(N1[i]==0){
            if(N2[j]==0)continue;
            if(N2[j]==1||N2[j]==4){
            score1--;
            score2++;
            }
            else{
                score1++;
                score2--;
            }
        }
        if(N1[i]==1){
            if(N2[j]==1)continue;
            if(N2[j]==2||N2[j]==4){
            score1--;
            score2++;
            }
            else{
                score1++;
                score2--;
            }
        }if(N1[i]==2){
            if(N2[j]==2)continue;
            if(N2[j]==0||N2[j]==3){
            score1++;
            score2--;
            }
            else{
                score1++;
                score2--;
            }
        }
        if(N1[i]==3){
            if(N2[j]==3)continue;
            if(N2[j]==0||N2[j]==2){
            score1--;
            score2++;
            }
            else{
                score1++;
                score2--;
            }
        }
        if(N1[i]==4){
            if(N2[j]==4)continue;
            if(N2[j]==3||N2[j]==2){
            score1--;
            score2++;
            }
            else{
                score1++;
                score2--;
            }
        }
        i++;
        j++;
        k++;
    }
    printf("%d %d",score1,score2);
    return 0;
};