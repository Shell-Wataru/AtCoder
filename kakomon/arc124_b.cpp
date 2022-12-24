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
    vector<ll> a(N);
    vector<ll> b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> counts;
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
        counts[b[i]]++;
    }
    set<ll> ans;
    for (int i = 0; i < N; i++)
    {
        auto current_counts = counts;
        ll x = a[0] ^ b[i];
        // cout << x << endl;
        bool is_ok = true;
        current_counts[b[i]]--;
        for (int j = 1; j < N; j++)
        {
            ll target = x ^ a[j];
            current_counts[target]--;
            if (current_counts[target] < 0)
            {
                is_ok = false;
                break;
            }
        }
        if (is_ok)
        {
            ans.insert(x);
        }
    }
    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a << endl;
    }
    return 0;
}
