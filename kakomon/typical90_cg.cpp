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
    ll K;
    cin >> K;
    ll ans = 0;
    ll aa = 0;
    ll bb = 0;
    for (ll b = 1; b * b <= K; b++)
    {
        if (K % b == 0)
        {
            for (ll a = 1; a <= b && K / b / a >= b; a++)
            {
                if (K / b % a == 0)
                {
                    ans++;
                }
            }
        }
    }
    cout << aa << endl;
    cout << bb << endl;
    cout << ans << endl;
    return 0;
}