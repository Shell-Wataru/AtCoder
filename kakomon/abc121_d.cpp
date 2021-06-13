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

using namespace std;
using ll = long long;

ll f(ll A){
    ll ans = 0;
    for(ll i = 0;i <= 40;i++){
        ll remain = A % (1ll<<(i+1));
        ll ones = A/(1ll<<(i+1)) * (1ll<<i) +  max(0ll,remain + 1 - (1ll<<i));
        if (ones % 2 == 1){
            ans += 1ll<<i;
        }
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll A,B;
    cin >> A >> B;
    // cout << f(A-1) << endl;
    // cout << f(B) << endl;
    cout << (f(B) ^ f(A-1)) << endl;
    return 0;
}
