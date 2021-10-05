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

int solve()
{
    ll N;
    scanf("%lld", &N);
    map<ll,ll> min_uses = {
        {-9,4},
        {-8,5},
        {-7,6},
        {-6,6},
        {-5,5},
        {-4,4},
        {-3,3},
        {-2,2},
        {-1,1},
        {0,0},
        {1,1},
        {2,2},
        {3,3},
        {4,4},
        {5,5},
        {6,6},
        {7,6},
        {8,5},
        {9,4},
    }
    // 桁と合計+-量でDP?
    return 0;
}

int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}