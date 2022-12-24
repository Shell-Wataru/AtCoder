#include <iostream>
#include <cstdio>
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

char next(char a,char b,char b_shape){
    if (b == 'S')
        {
            if (b_shape == 'o')
            {
                return a;
            }
            else
            {
                if (a == 'S')
                {
                    return 'W';
                }
                else
                {
                    return 'S';
                }
            }
        }
        else
        {
            if (b_shape == 'x')
            {
                return a;
            }
            else
            {
                if (a == 'S')
                {
                    return 'W';
                }
                else
                {
                    return 'S';
                }
            }
        }
}

bool pattern(string &S, char first, char second, string &ans)
{
    ll N = S.size();
    ans.clear();
    ans.push_back(first);
    ans.push_back(second);
    for (int i = 1; i < N-1; i++)
    {
        ans.push_back(next(ans[i-1],ans[i],S[i]));
    }
    if (next(ans[N-2],ans[N-1],S[N-1]) == ans[0] && next(ans[1],ans[0],S[0]) == ans[N-1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solve()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    string ans;
    if (pattern(S, 'S', 'S', ans))
    {
        cout << ans << "\n";
    }
    else if (pattern(S, 'S', 'W', ans))
    {
        cout << ans << "\n";
    }
    else if (pattern(S, 'W', 'S', ans))
    {
        cout << ans << "\n";
    }
    else if (pattern(S, 'W', 'W', ans))
    {
        cout << ans << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
