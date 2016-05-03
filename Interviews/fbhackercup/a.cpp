#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;

const int MAXLEN = 10010;
typedef long long int ll;


struct point {
	ll x,y;

	ll hash() const {
        	return MAXLEN*x + y;
	}


	point(){}
	point(ll ax, ll ay) : x(ax), y(ay) {}
	bool operator < (const point &rhs) const {
		return hash() < rhs.hash();
	}
};

struct line {
	point pa, pb;
	line () {}
	line(point apa, point apb) : pa(apa), pb(apb) {}
	ll hash() const {
		return MAXLEN*(MAXLEN+1)*pa.hash() + pb.hash();
	}

	bool operator < (const line &rhs) const {
		return hash() < rhs.hash();
	}
};

struct ptdist {
	point pt;
	ll dist;

	ptdist() {}
	ptdist(point apt, ll adist) : pt(apt), dist(adist){}

	ll hash() const {
		return MAXLEN*(MAXLEN+1)*pt.hash() + dist;
	}

	bool operator < (const ptdist &rhs) const {
		return hash() < rhs.hash();
	}
};



point pts[2010];
map<ptdist, int> dudes;
int main () {
	int T,n;
	scanf(" %d",&T);
	for(int nT = 1; nT <= T; nT++) {
		scanf(" %d",&n);
		memset(pts,0,sizeof(pts));
		dudes.clear();
		for(int i = 0; i < n; i++) {
			scanf("%lld %lld",&pts[i].x, &pts[i].y);
		}
		
		sort(pts, pts+n);

		int ans = 0;
		for(int i = 0; i < n-1; i++) {
			for(int j = i+1; j < n; j++) {
				line l = line(pts[i], pts[j]);
				ll dist = (pts[i].x - pts[j].x)*(pts[i].x - pts[j].x) + (pts[i].y - pts[j].y)*(pts[i].y - pts[j].y);
				ptdist ptda = ptdist(pts[i], dist);
				ptdist ptdb = ptdist(pts[j],dist);
				
				ans += dudes[ptda] + dudes[ptdb];
				dudes[ptda]++;
				dudes[ptdb]++;
			}
		}
		printf("Case #%d: %d\n",nT, ans);		
	}
}
