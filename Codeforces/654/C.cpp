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
    ll a,b,n,m;
    cin >> a >> b >> n >> m;
    if (b < a){
        swap(a,b);
    }
    if (a < m){
        cout << "No" << endl;
    }else if ( a + b < n + m){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
