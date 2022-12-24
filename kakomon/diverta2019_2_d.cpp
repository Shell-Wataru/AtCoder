#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

ll convert(ll N, vector<pair<ll, ll>> &converter)
{
    if (converter.size() == 0)
    {
        return N;
    }
    else if (converter.size() == 1)
    {
        return N % converter[0].first + N / converter[0].first * converter[0].second;
    }
    else if (converter.size() == 2)
    {
        ll ans = N;
        for (ll i = 0; converter[0].first * i <= N; i++)
        {
            ans = max(ans, i * converter[0].second + (N - i * converter[0].first) / converter[1].first * converter[1].second + (N - i * converter[0].first) % converter[1].first);
        }
        return ans;
    }
    else if (converter.size() == 3)
    {
        ll ans = N;
        for (ll i = 0; converter[0].first * i <= N; i++)
        {
            for (int j = 0; converter[0].first * i + converter[1].first * j <= N; j++)
            {
                ans = max(ans, i * converter[0].second + j * converter[1].second + (N - i * converter[0].first - converter[1].first * j) / converter[2].first * converter[2].second + (N - i * converter[0].first - converter[1].first * j) % converter[2].first);
            }
        }
        return ans;
    }
    else
    {
        return N;
    }
}
int solve()
{

    ll N;
    cin >> N;
    vector<ll> A(3);
    vector<ll> B(3);
    cin >> A[0] >> A[1] >> A[2];
    cin >> B[0] >> B[1] >> B[2];
    vector<pair<ll, ll>> AB;
    vector<pair<ll, ll>> BA;
    for (int i = 0; i < 3; i++)
    {
        if (A[i] < B[i])
        {
            AB.push_back({A[i], B[i]});
        }
        else if (A[i] > B[i])
        {
            BA.push_back({B[i], A[i]});
        }
    }
    // cout << AB.size() << endl;
    // cout << BA.size() << endl;
    cout << convert(convert(N, AB), BA) << endl;
    return 0;
}
int main()
{
    //   int t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}