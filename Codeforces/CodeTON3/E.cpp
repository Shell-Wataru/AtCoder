#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

// zero indexed and vector
template <typename T>
class BIT
{
public:
    vector<T> data;
    BIT(long long n) : data(n) {}
    //　indexに足す
    void add(int index, T v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    // [0,index)の和
    T sum(int index)
    {
        T retValue = 0;
        for (int i = index - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    // [l,r)の和
    T sum(int l, int r)
    {
        return sum(r) - sum(l);
    }

    void show()
    {
        for (auto v : data)
        {
            cout << v << endl;
        }
    }
};

int solve()
{
    ll n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector<ll> depth(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            depth[i + 1] = depth[i] + 1;
        }
        else
        {
            depth[i + 1] = depth[i] - 1;
        }
    }
    vector<ll> counts(2 * n + 1);
    ll total = 0;

    for (int i = 0; i <= n; i++)
    {
        counts[depth[i] + n]++;
    }
    for (int i = 0; i <= 2 * n; i++)
    {
        total += i * counts[i];
    }
    // cout << total << endl;
    ll ans = 0;
    ll points = n + 1;
    for (int i = 0; i <= 2 * n; i++)
    {
        // cout << i-n << ":"  << counts[i]  << endl;
        ans += total * counts[i];
        points -= counts[i];
        total -= points;
    }
    cout << ans << endl;
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
    cout << flush;
    return 0;
}
