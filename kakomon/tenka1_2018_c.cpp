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
    sort(a.begin(),a.end());
    if(N % 2 == 0){
        ll m = a[N/2-1];
        ll ans = 0;
        for(int i = 0;i < N/2-1;i++){
            ans +=  2*(m - a[i]);
        }
        ans += m - a[N/2-1];
        ans += a[N/2] -m;
        for(int i = N/2+1;i < N;i++){
            ans +=  2*(a[i] -m);
        }
        cout << ans << endl;
    }else{
        ll m = a[N/2];
        ll ans1 = 0;
        for(int i = 0;i < N/2;i++){
            ans1 +=  2*(m - a[i]);
        }
        ans1 += m - a[N/2];
        ans1 += a[N/2+1] - m;
        for(int i = N/2+2;i < N;i++){
            ans1 +=  2*(a[i] -m);
        }

        ll ans2 = 0;
        for(int i = 0;i < N/2-1;i++){
            ans2 +=  2* (m - a[i]);
        }
        ans2 += m - a[N/2-1];
        ans2 += a[N/2] - m;
        for(int i = N/2+1;i < N;i++){
            ans2 +=  2*(a[i] -m);
        }
        cout << max(ans1,ans2) << endl;
    }

    return 0;
}