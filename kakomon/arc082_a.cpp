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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> counts(100001);
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        counts[a]++;
    }
    ll ans = 0;
    for (int i = 1; i < 100000 - 1; i++)
    {
        ll total = counts[i - 1] + counts[i] + counts[i + 1];
        ans = max(ans, total);
    }
    cout << ans << endl;
    return 0;
}
