#include <stdio.h>
#include <math.h>

const int MAXN = 1000010;
double prices[MAXN];
double p,a,b,c,d,n;
double pr(double k) {
	return p*(sin(a*k+b)+cos(c*k+d)+2.0);
}

int main() {

	scanf(" %lf %lf %lf %lf %lf %lf",&p,&a,&b,&c,&d,&n);	
	for(int i = 1; i <= n; i++)
		prices[i] = pr(i*1.0f);

	int max=1,min=1;
	double ans = 0.0;
	for(int i = 2; i <= n; i++) {
		if(prices[i] > prices[max]) max = i;
		else if (prices[max] - prices[i] > ans) {
			ans = prices[max] - prices[i];
		}
	}
	printf("%.8lf\n",ans);
}
