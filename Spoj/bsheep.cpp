#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;
const int MAXN = 100010;
struct point {
	int x,y,ind;
	bool operator < (const point &rhs) const {
		if(y != rhs.y) return y < rhs.y;
		if(x != rhs.x) return x < rhs.x;
		return ind < rhs.ind;
	}
};

bool ccw (point p1, point p2, point p3){
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x) > 0;
}

int main() {
	point p[MAXN], H[2*MAXN];
	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;
		map<pair<int,int>, int> seen;
		seen.clear();
		int m = 0;
		for(int i = 0; i < n; i++) {
			int _x,_y;
			cin >> _x;
			cin >> _y;
			if(seen[make_pair(_x,_y)]) continue;
			seen[make_pair(_x,_y)] = 1;
			p[m].x = _x;
			p[m].y = _y;
			p[m].ind = i+1;
			m++;
		}

		sort(p, p+m);
		double len = 0;

		int k = 0;
		for(int i = 0; i < m; i++) {
			while(k>=2 && ccw(H[k-2], H[k-1], p[i]) <= 0) k--;
			H[k++] = p[i];
		}

		for(int i = m-1, t = k+1; i >= 0; i--) {
			while(k>=t && ccw(H[k-2], H[k-1], p[i]) <= 0) k--;
			H[k++] = p[i];
		}
		k--;
		for(int i = 0; i < k; i++) {
			double dx = (H[i].x - H[i+1].x);
			double dy = (H[i].y - H[i+1].y);
			len += sqrt(dx*dx+dy*dy);
		}
		
		printf("%.2lf\n", len);
		for(int i = 0; i < k; i++) {
			printf("%d ", H[i].ind);
		} printf("\n\n");
	}
}
