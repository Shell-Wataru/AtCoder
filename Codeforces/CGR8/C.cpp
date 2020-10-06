#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;


int solve()
{
    // cout << "==" << endl;
    ll n;
    scanf("%lld", &n);
    cout << 3 * (n+1) + 1 << "\n";
    cout << "0 0" << "\n";
    for(int i = 0;i <= n;i++){
        cout << i << " " << i + 1 << "\n";
        cout << i + 1<< " " << i << "\n";
        cout << i + 1 << " " << i + 1 << "\n";
    }
    cout << flush;
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
