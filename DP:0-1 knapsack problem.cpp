//http://blog.csdn.net/mao_kun/article/details/13004281
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 30
#define  MAXM  100003
int f[MAXM];
int w[MAXN], p[MAXN]; // weight & price



using namespace std;


int KnapSack(int n, int c)
{
    memset( f, 0, sizeof(f) );
    for(int i = 0; i < n; i++)
    {
        for(int j = c; j >= w[i]; j--)
        {
            f[ j ] = ( f[ j - w[i] ] + p[i] > f[ j ] )? f[ j - w[i] ] + p[i] : f[j]; // decide to or not to add w[i]
        }
    }
    return f[c];
}

int main()
{
    int task;
    scanf("%d", &task);
    while(task--)
    {
        int n, c; //  c is the capacity of knapsack
        scanf("%d%d", &n, &c);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &w[i], &p[i]);
        }
        printf("%d\n", KnapSack(n, c));
    }
    return 0;
}


