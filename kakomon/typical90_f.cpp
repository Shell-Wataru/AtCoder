#define _USE_MATH_DEFINES
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

using namespace std;
using ll = long long;

vector<ll> dfs(ll N, string S, ll current, ll K, ll l, ll r)
{
    vector<ll> ans;
    for (int i = l; i < r; i++)
    {
        if (S[i] == current)
        {
            ans.push_back(i);
        }
    }
    ll k = K;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        vector<ll> sub = dfs(N, S, current + 1, k, ans[i], r);
        k -= sub.size();
    }
}

int main()
{
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    pr return 0;
}