#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

ll answer(vector<ll> &parts)
{
    if (parts.size() == 0)
    {
        return 3;
    }
    else if (parts.size() == 1)
    {
        return 2;
    }
    else if (parts.size() == 2)
    {
        if (parts[0] == parts[1])
        {
            return 1;
        }
        else if (parts[0] + 1 == parts[1])
        {
            return 1;
        }
        else if (parts[0] + 2 == parts[1])
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        if (parts[0] == parts[1] && parts[1] == parts[2])
        {
            return 0;
        }
        else if (parts[0] + 1 == parts[1] && parts[1] + 1 == parts[2])
        {
            return 0;
        }
        else
        {
            ll diff12 = parts[1] - parts[0];
            ll diff23 = parts[2] - parts[1];
            if (diff12 == 0 || diff12 == 1 || diff12 == 2)
            {
                return 1;
            }
            else if (diff23 == 0 || diff23 == 1 || diff23 == 2)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
}

int main()
{
    // 整数の入力
    long long N;

    vector<ll> m_parts;
    vector<ll> s_parts;
    vector<ll> p_parts;
    string a;
    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        if (a[1] == 'm')
        {
            m_parts.push_back(a[0] - '0');
        }
        else if (a[1] == 's')
        {
            s_parts.push_back(a[0] - '0');
        }
        else if (a[1] == 'p')
        {
            p_parts.push_back(a[0] - '0');
        }
    }
    sort(m_parts.begin(), m_parts.end());
    sort(s_parts.begin(), s_parts.end());
    sort(p_parts.begin(), p_parts.end());
    ll ans = 3;
    ans = min(ans,answer(m_parts));
    ans = min(ans,answer(s_parts));
    ans = min(ans,answer(p_parts));

    cout << ans << endl;
    return 0;
}