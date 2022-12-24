#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <cmath>
#include <set>
#include <numeric>
#include <climits>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        ans = gcd(ans, a);
    }
    cout << ans << endl;
    return 0;
}
