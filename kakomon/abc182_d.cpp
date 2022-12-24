#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <cmath>
#include <set>
#include <numeric>
#include <climits>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll d = 0;
    ll max_d = 0;
    ll ans = 0;
    ll current = 0;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        d += a;
        max_d = max(max_d, d);
        ans = max(ans, current + max_d);
        current += d;
        ans = max(ans, current);
    }
    cout << ans << endl;
    return 0;
}
