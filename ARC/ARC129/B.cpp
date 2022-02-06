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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    ll L = numeric_limits<ll>::min();
    ll R = numeric_limits<ll>::max();
    for(int i = 0;i < N;i++){
        ll l,r;
        cin >> l >> r;
        L =max(L,l);
        R = min(R,r);
        cout << max(0ll, (L - R+1)/2) << "\n";
    }
    cout << flush;
    return 0;
}