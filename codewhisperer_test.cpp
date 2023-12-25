#include <iostream>
#include <cstdlib>
using namespace std;
#define ERROR -1
#define OK 0

typedef int Status;

typedef struct OLNode
{
    int i, j;
    int e;
    struct OLNode *right;
    struct OLNode *down;
} OLNode;

typedef OLNode *OLink;

typedef struct
{
    OLink *rhead, *chead;
    int mu, nu, tu;
} CrossList;

Status CreateSMatrix_OL(CrossList &M);
void PrintSMatrix_OL(const CrossList &M);

Status CreateSMatrix_OL(CrossList &M)
{
    OLNode *p, *q;
    int i, j, e;
    int m = rand() % 3 + 4;
    int n = rand() % 3 + 4;
    int t = rand() % 2 + 4;

    M.mu = m;
    M.nu = n;
    M.tu = t;

    if (!(M.rhead = (OLink *)malloc((m + 1) * sizeof(OLink))))
        return ERROR;
    if (!(M.chead = (OLink *)malloc((n + 1) * sizeof(OLink))))
        return ERROR;

    for (int a = 1; a <= m; a++)
        M.rhead[a] = NULL;

    for (int b = 1; b <= n; b++)
        M.chead[b] = NULL;

    for (int c = 1; c <= t; c++)
    {

        i = rand() % m + 1;
        j = rand() % n + 1;
        e = rand() % 10 + 1;

        if (!(p = (OLNode *)malloc(sizeof(OLNode))))
            return ERROR;

        p->i = i;
        p->j = j;
        p->e = e;
        p->down = NULL;
        p->right = NULL;

        if (M.rhead[i] == NULL || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else
        {
            for (q = M.rhead[i]; (q->right) && (q->right->j < j); q = q->right)
                ;
            p->right = q->right;
            q->right = p;
        }

        if (M.chead[j] == NULL || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else
        {
            for (q = M.chead[j]; (q->down) && (q->down->i < i); q = q->down)
                ;
            p->down = q->down;
            q->down = p;
        }
    }

    return OK;
}

void PrintSMatrix_OL(const CrossList &M)
{
    for (int i = 1; i <= M.mu; ++i)
    {
        OLink p = M.rhead[i];
        for (int j = 1; j <= M.nu; ++j)
        {
            if (p && p->j == j)
            {
                cout << p->e << " ";
                p = p->right;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    CrossList M;
    Status result = CreateSMatrix_OL(M);
    if (result == OK)
    {
        cout << "M:" << endl;
        cout << "行: " << M.mu << ", 列: " << M.nu << ", 非零元素: " << M.tu << endl;
        cout << "Matrix:" << endl;
        PrintSMatrix_OL(M);
    }
    else
    {
        cout << "Error" << endl;
    }

    return 0;
}
