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
    vector<ll> a(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    ll continues = 0;
    ll last =numeric_limits<ll>::max();
    ll ans = 0;
    for(int i = 0; i < N;i++){
        if (a[i] > last){
            continues++;
        }else{
            // cout << continues << endl;
            ans +=  continues*(continues+1)/2;
            continues = 1;
        }
        last = a[i];
    }
    ans +=  continues*(continues+1)/2;
    cout << ans << endl;
    return 0;
}