#include <iostream>
#include <string>
#include <vector>

using namespace std;


int RU = 0, LD = 1, RD = 2, LU = 3;
int T,N;
int MOD = 1000000007;
string grid[3];
long long int bizu[3][1000][4];

string print_which(int which){
  if(which == 0) return "RU";
  if(which == 1) return "LD";
  if(which == 2) return "RD";
  if(which == 3) return "LU";
}

long long int solve(int x, int y, int which){
  
  if(bizu[x][y][which] != -1) return bizu[x][y][which];  
  bizu[x][y][which] = 0;

  if(grid[x][y] == '#') {
    return bizu[x][y][which];
  }
  if(x == 0 && (which == LU || which == RU)) return bizu[x][y][which];
  if(x == 2 && (which == RD || which == LD)) return bizu[x][y][which];
  if(y == 0 && (which == LU || which == LD)) return bizu[x][y][which];
  if(y == N-1 && x != 2 && (which == RD || which == RU)) return bizu[x][y][which];

  if(which == RU) {
    if(x > 0 && grid[x-1][y] != '#') {
      bizu[x][y][which] += solve(x-1,y, LD)%MOD; 
    }
  } else if (which == LD) {
    if(y > 0 && grid[x][y-1] != '#') {
      bizu[x][y][which] += solve(x, y-1, RD)%MOD + solve(x,y-1,RU)%MOD;
    }
    
  } else if (which == RD) {
    if(x < 2 && grid[x+1][y] != '#') {
      bizu[x][y][which] += solve(x+1,y,LU)%MOD;
    }
  } else if (which == LU){
    if(y > 0 && grid[x][y-1] != '#'){
      bizu[x][y][which] += solve(x,y-1,RU)%MOD + solve(x,y-1, RD)%MOD;
    }
  }

  return bizu[x][y][which]%MOD;
}

int main() {
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cin >> N;
    for(int i = 0; i < 3; i++) {
      cin >> grid[i];
    }

    for(int i = 0; i < 3; i++){
      for(int j = 0; j < N; j++){
        for(int k = 0; k < 4; k++){
          bizu[i][j][k] =-1;
        }
      }
    }

    cout << "Case #" << t << ": ";
    if(grid[0][0] == '#' || grid[2][N-1] == '#') {
      cout << "0\n";
    } else {
      bizu[0][0][LD] = 1;
      bizu[0][0][RU] = bizu[0][0][RD] = bizu[0][0][LU] = 0;
      cout << solve(2,N - 1,RU)%MOD << "\n";
    }
  }
}
