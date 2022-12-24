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
#include <set>
using namespace std;
using ll = long long;

int solve(){
    ll N;
    cin >> N;
    map<ll,ll> counts;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        counts[a]++;
    }
    if (N % 2 == 1){
        cout << "Second\n";
    }else{
        for(auto p:counts){
            if (p.second % 2 == 1){
                cout << "First\n";
                return 0;
            }
        }
        cout << "Second\n";
    }
    return 0;
}

int main()
{
    ll T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
