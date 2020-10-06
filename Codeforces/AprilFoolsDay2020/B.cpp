#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
    ll t;
    cin >> t;
    ll ans = 0;
    ll index = 0;
    for(int i = 0;i < 7;i++){
        if (t & (1<<i)){
            ans = ans ^ (1<<index);
            index++;
        }
    }
    cout << ans << endl;
    // for (int i = 1; i <= t; i++)
    // {
    //     solve();
    // }
    return 0;
}
