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
    ll n,m;
    cin >> n >> m;
    ll zeros = n - m;
    ll total = n * (n + 1)/2;
    if (m + 1 >= zeros){
        cout << total - zeros << endl;
    }else{
        ll small_pattern = zeros/(m+1);
        ll big_pattern = small_pattern + 1;
        ll big_pattern_count = zeros % (m+1);
        ll small_pattern_count = m + 1 - big_pattern_count;

        ll big_pattern_pattern = big_pattern *(big_pattern + 1)/2;
        ll small_pattern_pattern = small_pattern *(small_pattern + 1)/2;
        cout << total - big_pattern_count * big_pattern_pattern - small_pattern_count * small_pattern_pattern << endl;
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
    return 0;
}
