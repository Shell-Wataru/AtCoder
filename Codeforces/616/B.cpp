#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;


int main()
{
    ll t;
    cin >> t;
    double ans = 0;
    for(int i = 1;i<= t;i++){
        ans += 1.0/i;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
