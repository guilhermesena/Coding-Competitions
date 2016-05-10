/*
Guilherme de Sena Brandine
Codeforces 519D
HashMaps
*/

#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 100010;
int val [30];
long long int sum [MAXN];
char st[MAXN];
vector <int> pos[30];
int main()
{
    for(int i = 0; i < 26; i++)
        scanf(" %d",&val[i]);

    getchar();
    gets(st+1);
    int len = strlen (st+1);
    sum[0] = 0;
    for(int i = 1; i <= len; i++)
    {
        sum[i] = sum[i-1] + val[st[i] - 'a'];
        pos[st[i] - 'a'].push_back(i);
    }
    long long int ans = 0;
    for(int c = 0; c < 26; c++)
    {
        map<long long int, int> m;
        size_t sz = pos[c].size();
        for(size_t i = 0; i < sz; i++)
        {
            int p = pos[c][i];
            ans += m[sum[p - 1]];
            m[sum[p]]++;
        }
        m.clear();
    }
    printf("%I64d\n",ans);
}
