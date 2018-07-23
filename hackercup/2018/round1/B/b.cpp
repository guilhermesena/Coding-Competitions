#include <iostream>

using namespace std;
int T,N,K,ind;
int l[2010], r[2010];
int pre[2010], pos[2010];
int L[2010], Laux[2010];

void preorder(int v) {
  pre[ind++] = v;
  if(l[v] != 0) preorder(l[v]);
  if(r[v] != 0) preorder(r[v]);
}

void posorder(int v){
  if(l[v] != 0) posorder(l[v]);
  if(r[v] != 0) posorder(r[v]);
  pos[ind++] = v;
}

// Union Find
int id[2010], sz[2010];
int uf_root(int v){
  while(v != id[v]){
    id[v] = id[id[v]];
    v = id[v];
  }
  return v;
}

bool uf_find(int v, int w){
  return (uf_root(v) == uf_root(w));
}

void uf_union(int v, int w){
  int rv = uf_root(v), rw = uf_root(w);
  if(sz[rv] > sz[rw]){
    id[rw] = rv;
    sz[rv] = sz[rv] + sz[rw];
  } else {
    id[rv] = rw;
    sz[rw] = sz[rw] + sz[rv];
  }
}

int main() {
  cin >> T;
  for(int t = 1; t <= T; t++){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
      cin >> l[i] >> r[i];
      id[i] = i;
      sz[i] = 1;
      Laux[i] = 0;
    }

    ind = 1;
    preorder(1);
    ind = 1;
    posorder(1);
    
    for(int i = 1; i <= N; i++){
      if(pre[i] != pos[i]) {
        int u = pre[i], w =pos[i];
        if(!uf_find(u,w)){
          uf_union(u,w);
        }
      }
    }
    
    int ncc = 0; 
    for(int i = 1; i <= N; i++){
      int ri = uf_root(i);
      if(Laux[ri] == 0){
        Laux[ri] = ++ncc;
      }
      L[i] = Laux[ri];
    }
    
    for(int i = 1; i <= N; i++){
      if(L[i] > K) L[i] = 1;
    }

    cout << "Case #" << t << ": ";
    if(ncc < K) {
      cout << "Impossible\n";
    }
    else {
      for(int i = 1; i < N; i++) cout << L[i] << " ";
      cout << L[N] << "\n";

    }
  }
}
