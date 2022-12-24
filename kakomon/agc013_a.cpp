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
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    ll last = a[0];
    ll lastlast = -1;
    ll ans = 0;
    for (int i = 1; i < N; i++)
    {
        if (lastlast == -1 && last != a[i])
        {
            lastlast = last;
            last = a[i];
        }
        else if (lastlast == -1 && last == a[i])
        {
            continue;
        }
        else if (lastlast < last && last < a[i])
        {
            lastlast = last;
            last = a[i];
        }
        else if (lastlast < last && last == a[i])
        {
            continue;
        }
        else if (lastlast < last && last > a[i])
        {
            ans++;
            last = a[i];
            lastlast = -1;
        }
        else if (lastlast > last && last > a[i])
        {
            lastlast = last;
            last = a[i];
        }
        else if (lastlast > last && last == a[i])
        {
            continue;
        }
        else
        {
            ans++;
            last = a[i];
            lastlast = -1;
        }
    }
    ans++;
    cout << ans << endl;
    return 0;
}
