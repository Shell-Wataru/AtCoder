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
        string S;
        cin >> S;
        counts[S]++;
    }
    ll maximum = 0;
    string ans;
    for (auto p : counts)
    {
        if (p.second > maximum)
        {
            ans = p.first;
            maximum = p.second;
        }
    }
    cout << ans << endl;
    return 0;
}