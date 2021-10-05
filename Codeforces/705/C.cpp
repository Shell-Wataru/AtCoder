#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

bool minimum_greater_array(map<ll, ll> &base_counts, vector<ll> &target, vector<ll> &answer, bool is_greater)
{
    if (is_greater)
    {
        auto itr = base_counts.begin();
        answer.push_back(itr->first);
        base_counts[itr->first]--;
        if (base_counts[itr->first] == 0)
        {
            base_counts.erase(itr->first);
        }
        minimum_greater_array(base_counts, target, answer, true);
        return true;
    }

    ll i = answer.size() + 1;
    ll from_target = target[i];
    auto itr = base_counts.lower_bound(from_target);
    if (itr == base_counts.end())
    {
        return false;
    }
    else
    {
        ll j = itr->first;
        base_counts[j]--;
        answer.push_back(j);
        if (j == from_target)
        {
            minimum_greater_array(base_counts, target, answer, false);
        }
        else
        {
            minimum_greater_array(base_counts, target, answer, true);
        }
    }
}
string answer(string &s, vector<ll> &base, ll n, ll k)
{
    vector<ll> sorted_base(base);
    sort(sorted_base.begin(), sorted_base.end());
    vector<ll> base_counts(26, 0);
    for (auto c : base)
    {
        base_counts[c]++;
    }
    bool is_greater = false;
    string ans = "";
    for (int i = 0; i < k; i++)
    {
        if (!is_greater)
        {
            vector<ll> current_counts(base_counts);
            for (int j = 0; j < n / k; j++)
            {
                ll from_target = s[k * i + j] - 'a';
                ll from_base;
                for (int kk = from_target; kk < 26; kk++)
                {
                    if (current_counts[kk] > 0)
                    {
                        from_base = kk;
                        current_counts[kk]--;
                        break;
                    }
                }
                ans += 'a' + from_base;
                if (from_base != from_target)
                {
                    is_greater = true;
                }
            }
        }
        else
        {
            for (int j = 0; j < n / k; j++)
            {
                ans += 'a' + sorted_base[j];
            }
        }
    }
    return ans;
}

int solve()
{
    ll n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    string s;
    cin >> s;
    if (n % k != 0)
    {
        cout << -1 << "\n";
        return 0;
    }
    vector<ll> base(n / k);
    for (int j = 0; j < n / k; j++)
    {
        base[j] = s[j] - 'a';
    }
    vector<ll> sorted_base(base);
    sort(sorted_base.begin(), sorted_base.end(), greater<ll>());
    bool can_make = true;
    for (int i = 1; i < k; i++)
    {
        vector<ll> target(n / k);
        for (int j = 0; j < n / k; j++)
        {
            target[j] = s[i * k + j] - 'a';
        }
        sort(target.begin(), target.end(), greater<ll>());
        if (target > sorted_base)
        {
            can_make = false;
            break;
        }
    }
    int i = n / k - 1;
    while (!can_make)
    {
        base[i] += 1;
        if (base[i] < 26)
        {
            break;
        }
        else
        {
            base[i] = 0;
        }
        i--;
    }
    for (auto c : base)
    {
        cout << (char)(c + 'a');
    }
    cout << endl;
    cout << answer(s, base, n, k) << "\n";
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
