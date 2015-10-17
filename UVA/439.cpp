#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
bool marcado[1000];
int level[1000];

int hash(int x, int y) {
	return 100*x+y;
}

bool isValid(int x, int y) {
	return x>=0 && x<8 && y>=0 && y<8;
}

bool liga(int xa, int ya, int xb, int yb) {
	if(!isValid(xa,ya) || !isValid(xb,yb)) return false;
	for(int i = -1; i <= 1; i+= 2) {
		for(int j = -2; j <= 2; j += 4) {
			if(xa+i==xb && ya+j==yb) 
				return true;
		}
	}
	

	for(int i = -2; i <= 2; i+= 4) {
                   for(int j = -1; j <= 1; j += 2) {
                           if(xa+i==xb && ya+j==yb)
                                   return true;
                   }
         }
	return false;
}

int main() {
	char from[3], to[3];
	while(scanf(" %s %s",from,to) >0) {
		memset(marcado,0,sizeof(marcado));
		memset(level,0,sizeof(level));
		int xs = from[0] - 'a';
		int ys = from[1] - '1';
		
		int xe = to[0] - 'a';
		int ye = to[1] - '1';
		queue<int> qx;
		queue<int> qy;
		qx.push(xs);
		qy.push(ys);
		marcado[hash(xs,ys)] = 1;
		level[hash(xs,ys)] = 0;
		while(!qx.empty()) {
			int xc = qx.front(); qx.pop();
			int yc = qy.front(); qy.pop();
			for(int i = -2; i <= 2; i++) {
				for(int j = -2; j <= 2; j++) {
					int xt = xc+i;
					int yt = yc+j;
					if(!marcado[hash(xt,yt)] && liga(xc,yc,xt,yt)) {
						marcado[hash(xt,yt)] =1;
						level[hash(xt,yt)] = level[hash(xc,yc)]+1;
						qx.push(xt);
						qy.push(yt);
					}
				}		
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n",from,to,level[hash(xe,ye)]); 
	}
}
