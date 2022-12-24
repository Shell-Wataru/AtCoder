#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll x,y,z;
    cin >> x >> y >> z;
    ll ans = x + y;
    ans = max(ans,y+z);
    ans = max(ans,z+x);
    cout << ans << endl;
    return 0;
}