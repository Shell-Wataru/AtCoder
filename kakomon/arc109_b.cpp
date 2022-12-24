#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

ll answer(ll l, ll r, ll n)
{
    if (l + 1 == r)
    {
        return l;
    }
    ll center = (l + r) / 2;
    if (center * (center + 1) / 2 > n)
    {
        return answer(l, center, n);
    }
    else
    {
        return answer(center, r, n);
    }
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    ll a = answer(0ll, 2000000001ll, N + 1);
    // cout << a << endl;
    cout << N - a + 1 << endl;
    return 0;
}