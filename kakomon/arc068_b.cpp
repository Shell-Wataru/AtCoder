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
    ll N, K;
    cin >> N;
    vector<ll> counts(100000,0);
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        a--;
        counts[a]++;
    }
    ll ans = 0;
    ll i = 0;
    ll j = 100000 -1;
    while(i < j){
        if (counts[i] == 0){
            i++;
        }else if(counts[i] == 1){
            i++;
            ans++;
        }else  if (counts[j] == 0){
            j--;
        }else if(counts[j] == 1){
            ans++;
            j--;
        }else{
            ll eat = min(counts[i],counts[j]) - 1;
            counts[i] -= eat;
            counts[j] -= eat;
        }
    }
    if(counts[i] % 2 == 1){
        ans++;
    }
    cout << ans << endl;
    return 0;
}