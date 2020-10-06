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
ll BASE_NUM = 1000000007;

int solve()
{
    // cout << "==" << endl;
    ll n, k;
    cin >> n >> k;
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    ll index = 0;
    priority_queue<string, vector<string>, greater<string>> q;
    for (; index < k; index++)
    {
        q.push({S[index]});
    }

    for (; index < S.size(); index++)
    {
        string a;
        a = q.top();
        if(S[index] == S.back()){
            a += S[index];
            q.pop();
            q.push(a);
        }else{
            a += S.substr(index);
            q.pop();
            q.push(a);
            break;
        }
    }

    string ans = "";
    while (!q.empty())
    {
        // cout << q.top() << endl;
        if (ans == "" || ans < q.top())
        {
            ans = q.top();
        }
        q.pop();
    }
    cout << ans << "\n";
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
