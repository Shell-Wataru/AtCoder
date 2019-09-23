#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

ll solve(ll n, ll a, ll b, string &s)
{
    ll current_height = 1;
    ll ans = b;
    for (int i = 0; i < n;)
    {
        if (current_height == 1 && s[i] == '0' && s[i + 1] == '0')
        {
            ans += a + b;
            i++;
        }else if (current_height == 1 && s[i] == '0' && i == n-1){
            ans += a + b;
            i++;
        }        else if (current_height == 1 && s[i] == '0' && s[i + 1] == '1')
        {
            ans += 2 * a + 2 * b;
            current_height = 2;
            i++;
        }
        else if (s[i] == '1')
        {
            ans += a + 2 * b;
            i++;
        }
        else
        {
            // current_height = 2 and  s[i]== '0'
            ll zero_continues = 0;
            ll j = i;
            while (j < s.length() && s[j] == '0')
            {
                zero_continues++;
                j++;
            }
            if (i + zero_continues == n)
            {
                ans += a + zero_continues * a + zero_continues * b;
            }
            else if (2 * a + zero_continues * a + zero_continues * b + b < zero_continues * a + zero_continues * 2 * b)
            {
                ans += 2 * a + zero_continues * a + zero_continues * b + b;
            }
            else
            {
                ans += zero_continues * a + zero_continues * 2 * b;
            }
            i = i + zero_continues;
        }
        // cout << ans << endl;
    }
    return ans;
}

int main()
{
    // 整数の入力

    long long T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        ll n, a, b, ans;
        string s;
        cin >> n >> a >> b;
        cin >> s;
        ans = solve(n, a, b, s);
        cout << ans << endl;
    }
    return 0;
}