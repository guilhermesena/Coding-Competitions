#include <stdio.h>
using namespace std;
typedef long long int ll;
int n_digits(ll d) {
	int ans = 0;
	while(d>0){
		d = d/10;
		ans++;
	}
	return ans;
}
int AreAll9s( int* num, int n )
{
    int i;
    for( i = 0; i < n; ++i )
        if( num[i] != 9 )
            return 0;
    return 1;
}
void generateNextPalindromeUtil (int *num, int n )
{
    int mid = n/2;
    bool leftsmaller = false;
    int i = mid - 1;
    int j = (n % 2)? mid + 1 : mid;
    while (i >= 0 && num[i] == num[j])
        i--,j++;
 
    if ( i < 0 || num[i] < num[j])
        leftsmaller = true;
 
    while (i >= 0) {
        num[j] = num[i];
        j++;
        i--;
    }
 
    if (leftsmaller) {
        int carry = 1;
        i = mid - 1;
        if (n%2 == 1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;
 
        while (i >= 0) {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--]; // copy mirror to right
        }
    }
}
 
void generateNextPalindrome( int *num, int n )
{
        generateNextPalindromeUtil ( num, n );
    
}

ll nextp (ll d) {
	const int nd = n_digits(d);
	int *digs = new int [nd];
	ll  u = d;
	for(int i = nd -1; i >= 0; i--) {
		digs[i] = u%10;
		u = u/10;
	}
	if(AreAll9s(digs, nd)) {
		ll ans = 1;
		for(int i = 0; i < nd; i++) ans *= 10;
		++ans;
		return ans;
	}
	generateNextPalindrome(digs, nd);
	ll next = 0;
	for(int i = 0; i < nd; i++){
		next *=10;
		next += digs[i];
	}
	delete[] digs;
	return next;
}

int main() {
	ll q = 0;
	ll max = 1e14;
	printf("Max = %lld\n",max);
	for(ll i = 1; i < max;) {
		ll u = i;
		i = nextp(i);
		ll r = i - u;
		q += (r*(r-1)) >> 1;
	}
	printf("%lld\n",q);
}
