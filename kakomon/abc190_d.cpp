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
    ll ans = 0;
    for (ll i = 1; i * i < 2 * N; i++)
    {
        if ((2 * N) % i == 0)
        {
            ll j = 2 * N / i;
            if ((i + j) % 2 == 1)
            {
                ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}