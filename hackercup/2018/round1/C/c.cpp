#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>

typedef long long int lli;

using namespace std;
int T, N, M;
lli h[200010];
lli delta[200010], 
    maxdiff[200010], 
    mindiff[200010],
    maxchange[200010],
    minchange[200010];

lli U[25], D[25];
int A[25], B[25];
lli W,X,Y,Z;
lli inf = 2000000000ll;

bool canChange(double m){
  double cmin = -m, cmax = m;
  for(int i = 0; i < N-1; i++){
    cmax = min(m, cmax + maxchange[i]);
    cmin = max(-m, cmin + minchange[i]);
    if(cmin > cmax) return false;
  }
  return true;
}


int main(){
  cin >> T;
  for(int t = 1; t <= T; t++){
    cin >> N >> M;
    cin >> h[0] >> h[1] >> W >> X >> Y >> Z;
    for(int i = 0; i < M; i++){
      cin >> A[i] >> B[i] >> U[i] >> D[i];
      A[i]--;
      B[i]--;
    }
    for(int i = 2; i < N; i++){
      h[i] = (W*h[i-2] + X*h[i-1] + Y)%Z;
    }
    for(int i = 0; i < N; i++){
      delta[i] = inf;
      maxdiff[i] = inf;
      mindiff[i] = -inf;
    }

    for(int i = 0; i < N-1; i++) {
      delta[i]  = h[i+1] - h[i];
    }
    for(int p = 0; p < M; p++) {
      if(A[p] < B[p]){ 
        for(int i = A[p]; i < B[p]; i++){
          maxdiff[i] = min(maxdiff[i], U[p]);
          mindiff[i] = max(mindiff[i], -D[p]);
        }
      } else {
        for(int i = B[p]; i < A[p]; i++){
          maxdiff[i] = min(maxdiff[i], D[p]);
          mindiff[i] = max(mindiff[i], -U[p]);
        }
      }
    }
    
    for(int i = 0; i < N - 1; i++){
      maxchange[i] = maxdiff[i] - delta[i];
      minchange[i] = mindiff[i] - delta[i];
    }

    double l = 0, r = 1e7, m;
    while(r - l > 1e-7){
      m = (r+l)/2.0;
      if(canChange(m)) {
        r = m;
      } else {
        l = m;
      }
    }
    printf("Case #%d: %.6lf\n", t, m);
  }
  return 0;
}
