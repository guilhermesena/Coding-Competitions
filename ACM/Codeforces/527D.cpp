/*
Guilherme Sena
Codeforces problem 527D
Activity selection greedy algorithm
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN = 200010;

struct vertex
{
    int x,w;

    bool operator < (const vertex b) const
    {

        return x+w < b.x+b.w;
    }
};

vertex v[MAXN];

int main()
{
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < n; i++)
        scanf(" %d %d",&v[i].x, &v[i].w);

    sort(v, v+n);
    int start = 0;
    int ans = 1;
    for(int i = 1; i < n; i++)
    {
        if(v[i].x - v[i].w >= v[start].x + v[start].w)
        {
            start = i;
            ans++;
        }
    }
    printf("%d\n",ans);

}
