#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[m], i = 0;
    while (i < m)
    {
        cin >> a[i++];
    }
    sort(a, a + m, greater<int>());
    while (i > 0)
    {
        cout << a[--i] << ' ';
    }
    return 0;
}