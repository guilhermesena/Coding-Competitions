#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */

int timeToNum(string s) {
	return ((s[0]-'0')*10 + s[1]-'0')*60 + (s[3]-'0')*10+s[4]-'0';
}

int getMinTimeDifference(vector < string > times) {
	int len = times.size();
	int ans = 1 << 30, diff;
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			if(i==j) continue;
			int ta = timeToNum(times[i]);
			int tb = timeToNum(times[j]);
 			if(tb >= ta) diff = tb-ta;
			else diff = tb-ta+24*60;

			if(diff < ans) ans = diff;
		}
	}

	return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    
    int _times_size = 0;
    cin >> _times_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _times;
    string _times_item;
    for(int _times_i=0; _times_i<_times_size; _times_i++) {
        getline(cin, _times_item);
        _times.push_back(_times_item);
    }
    
    res = getMinTimeDifference(_times);
    cout << res << endl;
    
    fout.close();
    return 0;
}

