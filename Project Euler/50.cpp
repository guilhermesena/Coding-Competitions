#include <stdio.h>
#include <string.h>
const int MAXN = 1000010;
bool iscomposed [MAXN+10];
int indprimo[MAXN+10];
int primo[MAXN+10];
long long int cumsum[MAXN+10];
int main()
{
    memset(iscomposed, false, sizeof(iscomposed));
    int nprimos = 0;
    //crivo
    for(long long int i = 2; i < MAXN; i++)
    {
        if(!iscomposed[i])
        {
            primo[nprimos] = i;
            indprimo[i] = nprimos++;
            for(long long int j = i*i; j < MAXN; j += i)
            {
                iscomposed[j] = true;
            }

        }
    }

    cumsum[0] = 0;
    for(int i = 1; i <= nprimos; i++)
        cumsum[i] = cumsum[i-1] + ((long long int)primo[i-1]);

    int ans = 1, numans = 2;
    for(int i = 1; i < nprimos; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(cumsum[i] - cumsum[j] > MAXN) break;

            else if (!iscomposed[cumsum[i] - cumsum[j]])
                if(i - j > ans)
                {
                    ans = i - j;
                    numans = cumsum[i] - cumsum[j];
                }
        }
    }

    printf("ans = %d, numans = %d\n",ans, numans);

    return 0;
}
