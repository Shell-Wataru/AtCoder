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
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    ll max_a = 0;
    for(int i = 0;i < N;i++){
        if (a[i] > max_a + 1){
            // cout << max_a << " ";
            // cout << (a[i]-1)/(max_a+1) << endl;
            ans += (a[i]-1)/(max_a+1);
            max_a = max(max_a,1ll);
        }else{
            max_a = max(max_a,a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}