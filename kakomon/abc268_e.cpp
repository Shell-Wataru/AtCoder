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
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> P(N);
    vector<ll> kCounts(N);
    ll ans = numeric_limits<ll>::max();
    ll current = 0;
    for (int i = 0; i < N; i++)
    {
        ll p;
        cin >> p;
        // p--;
        kCounts[(N + (i - p)) % N]++;
        ll d = abs(i-p);
        current += min(d,N-d);
    }
    // for(int i = 0;i < N;i++){
    //     cout << kCounts[i] << ",";
    // }
    // cout << endl;
    // cout << current << endl;
    ans = min(current, ans);
    ll positive_l = 0;
    ll positive_r = N / 2;
    ll no_change_l = N / 2;
    ll no_change_r = (N + 1) / 2;
    ll negative_l = (N + 1) / 2;
    ll negative_r = N;
    ll positive_count = 0;
    ll no_change_count = 0;
    ll negative_count = 0;
    // cout << positive_l << "~" << positive_r << endl;
    // cout << no_change_l << "~" << no_change_r << endl;
    // cout << negative_l << "~" << negative_r << endl;
    for (ll i = 0; i < N; i++)
    {
        if (positive_l <= i && i < positive_r)
        {
            positive_count += kCounts[i];
        }
        else if (no_change_l <= i && i < no_change_r)
        {
            no_change_count += kCounts[i];
        }
        else
        {
            negative_count += kCounts[i];
        }
    }
    // cout  << positive_count  << "," << no_change_count << "," << negative_count << endl;
    for (int i = 0; i < N-1; i++)
    {
        current += positive_count - negative_count;
        // cout << current << endl;
        ans = min(current, ans);
        positive_count += kCounts[(N - i + positive_l-1) % N];
        positive_count -= kCounts[(N - i + positive_r-1) % N];
        no_change_count += kCounts[(N - i + no_change_l-1) % N];
        no_change_count -= kCounts[(N - i + no_change_r-1) % N];
        negative_count += kCounts[(N - i + negative_l-1) % N];
        negative_count -= kCounts[(N - i + negative_r-1) % N];
        // cout  << positive_count  << "," << no_change_count << "," << negative_count << endl;
    }
    cout << ans << endl;
    return 0;
}
