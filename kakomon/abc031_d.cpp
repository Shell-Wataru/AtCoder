#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

bool sub_solve(vector<string> &S, vector<string> &V, vector<string> &W, vector<ll> &VIndex, vector<ll> &WIndex, ll current)
{
    if (current == V.size())
    {
        return true;
    }else if (VIndex[current] >=  V[current].size() || WIndex[current] >=  W[current].size()){
        return false;
    }
    // cout << "c:" << current << endl;
    // cout << "vi:" << VIndex[current] << endl;
    // cout << V[current][VIndex[current]] << endl;
    ll n = V[current][VIndex[current]] - '0';
    if (S[n] != "")
    {
        if (W[current].substr(WIndex[current], S[n].size()) == S[n])
        {
            WIndex[current] += S[n].size();
            VIndex[current] += 1;
            bool current_changed = false;
            if (VIndex[current] == V[current].size() && WIndex[current] == W[current].size())
            {
                current_changed = true;
                current++;
            }
            bool is_ok = sub_solve(S, V, W, VIndex, WIndex, current);
            if (is_ok)
            {
                return true;
            }
            else
            {
                if (current_changed)
                {
                    current--;
                }
                VIndex[current] -= 1;
                WIndex[current] -= S[n].size();
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (int i = 1; i <= 3 && WIndex[current] + i <= W[current].size(); i++)
        {
            S[n] = W[current].substr(WIndex[current], i);
            WIndex[current] += S[n].size();
            VIndex[current] += 1;
            bool current_changed = false;
            if (VIndex[current] == V[current].size() && WIndex[current] == W[current].size())
            {
                current_changed = true;
                current++;
            }
            bool is_ok = sub_solve(S, V, W, VIndex, WIndex, current);
            if (is_ok)
            {
                return true;
            }
            else
            {
                if (current_changed)
                {
                    current--;
                }
                VIndex[current] -= 1;
                WIndex[current] -= S[n].size();
                S[n] = "";
            }
        }
        return false;
    }
}

int solve()
{
    ll k, n;
    cin >> k >> n;
    vector<string> S(k + 1, "");
    vector<string> V(n);
    vector<string> W(n);
    vector<ll> VIndex(n, 0);
    vector<ll> WIndex(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> V[i] >> W[i];
    }
    sub_solve(S, V, W, VIndex, WIndex, 0);
    for (int i = 1; i <= k; i++)
    {
        cout << S[i] << endl;
    }
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;
    //   for (int i = 1; i <= t; i++)
    //   {
    solve();
    //   }
    return 0;
}