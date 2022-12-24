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
    ll A, K;
    cin >> A >> K;
    ll nityo = 2000000000000ll;
    if (K == 0)
    {
        cout << nityo - A << endl;
    }
    else
    {
        ll ans = 0;
        while (A < nityo)
        {
            A += 1 + K * A;
            ans++;
            // cout << A << endl;
        }
        cout << ans << endl;
    }
    return 0;
}