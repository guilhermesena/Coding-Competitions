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
vector < string > getSuspiciousList(vector < string > transactions) {
	vector <string> ans;
	map<string, int> seen;
	map<string, int> lastTime;
	map<string, string> lastPlace;
	map<string, int> lastPos;
	map<string, int> added;
	const int len = transactions.size();
	int *suspicious = new int[len];
	char name[10010];
	char city[10010];
	int val,time; 
	for(int i = 0; i < len; i++) {
		int sz = transactions[i].size();
		for(int j = 0; j < sz; j++) if(transactions[i][j] =='|') transactions[i][j] = ' ';
		sscanf((const char*) transactions[i].c_str(), "%s %d %s %d", name, &val, city, &time);
		suspicious[i] = 0;
		if(val > 3000) {
			suspicious[i] = 1;
		}
		if(seen[name] && lastPlace[name]!=city && time - lastTime[name] < 60) {
			suspicious[lastPos[name]] = 1;
		}
		seen[name] = 1;
		lastPlace[name] = city;
		lastTime[name] = time;
		lastPos[name] = i;
	}

	for(int i = 0; i < len; i++) {
		sscanf((const char*) transactions[i].c_str(), "%s %d %s %d", name, &val, city, &time);
		if(suspicious[i] && !added[name]) {
			added[name]=1;
			ans.push_back(name);
		}
	}
	return ans;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < string > res;
    
    int _transactions_size = 0;
    cin >> _transactions_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _transactions;
    string _transactions_item;
    for(int _transactions_i=0; _transactions_i<_transactions_size; _transactions_i++) {
        getline(cin, _transactions_item);
        _transactions.push_back(_transactions_item);
    }
    
    res = getSuspiciousList(_transactions);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    fout.close();
    return 0;
}
