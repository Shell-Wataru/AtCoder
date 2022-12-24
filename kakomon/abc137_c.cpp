#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    map<string, ll> counts;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        counts[s]++;
    }
    ll ans = 0;
    for (auto p : counts)
    {
        ans += p.second * (p.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
