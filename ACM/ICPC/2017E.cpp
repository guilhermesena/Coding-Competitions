#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main() {
  long long int n,t;
  while (cin >> n >> t) {
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    cout.precision(8);
    long long int ds[n], ss[n];
    double eps = 1e-8;
    double ans = 0.0;
    long long int min_v = 1e9;
    for (long long int i = 0; i < n; ++i) {
      cin >> ds[i] >> ss[i];
      if (ss[i] < min_v) min_v = ss[i];
    }
    double c_up = 1010000, c_down = -min_v, c_mid;
    while (true) {
      if (abs(c_up - c_down) < eps) break;

      c_mid = (c_up + c_down)/2.0;
      ans = 0.0;
      for (long long int i = 0; i < n; ++i) {
        ans += ds[i] / (static_cast<double>(ss[i] + c_mid));
      }
      if (ans > t) c_down = c_mid;
      else c_up = c_mid;
    }

    cout << c_mid << "\n";
  }
  return 0;
}
