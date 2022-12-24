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

int solve()
{
    ll Q;
    ll N = 1048576;
    cin >> Q;
    set<ll> can_uses;
    for(int i = 0;i < N;i++){
        can_uses.insert(i);
    }
    vector<ll> A(N,-1);
    for(int i = 0;i < Q;i++){
        ll t,x;
        cin >> t >> x;
        ll h = x % N;
        if (t == 1){
            if (can_uses.lower_bound(h) != can_uses.end()){
                ll index = *can_uses.lower_bound(h);
                A[index] = x;
                can_uses.erase(index);
            }else{
                ll index = *can_uses.lower_bound(0);
                A[index] = x;
                can_uses.erase(index);
            }
        }else{
            cout << A[h] << "\n";
        }
    }
    return 0;
}

int main()
{
    // ll t;
    // cin >> t;
    // for(int i = 0;i < t;i++){
    solve();
    // }
    cout << flush;
    return 0;
}