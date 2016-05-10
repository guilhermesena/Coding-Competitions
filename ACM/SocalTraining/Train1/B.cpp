#include <stdio.h>
#include <string.h>
int score[110];
int dead[110];
int N,T;
bool ended() {
	int sc = -1;
	for(int i = 0; i < N; i++) {
		if(!dead[i]) {
			if(sc == -1) sc = score[i];
			else if(score[i] != sc) return false;
		}
	}	
	return true;
}

int main() {
	while(scanf(" %d",&N)>0 && N > 0){
		memset(dead,0,sizeof(dead));
		memset(score,0,sizeof(score));
		scanf(" %d",&T);
		int p = 0;
		while(1) {
			int c = T, point = p;
			while(c > 0) {
				if(point == N) point = 0;
				if(!dead[point]) {score[point]++; c--;}
				if(c!=0)point++;
			}
			dead[point] = true;
			p = point;
			
			if(ended()) break;
		}
		int ans_n = 0, ans_score = 0;
		for(int i = 0; i < N; i++) {if(!dead[i]) {ans_n++; ans_score = score[i];}}		
		printf("%d %d\n",ans_n, ans_score);
	}
}
