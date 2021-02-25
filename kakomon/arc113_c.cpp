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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    vector<ll> occur_count(26, 0);
    ll N = S.length();
    ll ans = 0;
    for (int i = S.length() - 1; i >= 1; i--)
    {
        ll c = S[i] - 'a';
        ll before_c = S[i - 1] - 'a';
        if (c == before_c)
        {
            // cout << S[i] << " " << N - i - 1 - occur_count[c] << endl;
            ans += N - i - 1 - occur_count[c];
            fill(occur_count.begin(), occur_count.end(), 0);
            occur_count[c] = N - i;
        }
        else
        {
            occur_count[c]++;
        }
    }
    cout << ans << endl;
    return 0;
}