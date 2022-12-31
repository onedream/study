#include <bits/stdc++.h>
using namespace std;
void bs(char *a, int b, int c)
{
    int j = -1, x = 0, y = 0, t = 1;
    while (t)
    {
        j++;
        if (a[j] == 'W')
            x++;
        if (a[j] == 'L')
            y++;
        if (a[j] == 'E')
        {
            t = 0;
            printf("%d:%d\n", x, y);
            break;
        }
        if ((x >= b || y >= c) && abs(x - y) >= 2)
        {
            printf("%d:%d\n", x, y);
            x = 0, y = 0;
        }
    };
}
int main()
{
    int i = 0, b = 11, c = 11;
    char a[62526];
    while (1)
    {
        cin >> a[i];
        if (a[i] == 'E')
            break;
        i++;
    }
    bs(a, b, c);
    printf("\n");
    bs(a, b + 10, c + 10);
    return 0;
}