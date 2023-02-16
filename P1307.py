#include<stdio.h>
#include<string.h>
int main()
{
    int i,j=1,k;
    char number[15]={'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'};
    gets(number);
    for(i=0;i<15;i++)
    {
        if(number[i]=='\000')
        number[i]='x';
    }
    for(i=14;i>-1;i--)
    {
        if(number[i]=='x')continue;
        while(number[i]!='x'){
            if(number[i]=='0')goto end;
            else{
              break;
            }
        }
        printf("%c",number[i]);
    }
    while(i>-1)
    {
        printf("%c",number[i]);
        i--;
        end:k=1;
    }
    return 0;
}
