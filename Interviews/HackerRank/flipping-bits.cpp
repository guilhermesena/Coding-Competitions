#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n;
	scanf(" %d",&n);
	for (int i = 0; i < n; i++) {
		unsigned int m;
		scanf(" %u",&m);
		printf("%u\n", m ^ (0xFFFFFFFF));
	}
	return 0;
}

