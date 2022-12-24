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
    ll ans = numeric_limits<ll>::max();
    for (int i = 1; i <= N; i++)
    {
        ll b = N / i;
        ans = min(ans, abs(i - b) + N % i);
    }
    cout << ans << endl;
    return 0;
}