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

ll boarder(ll l,ll r,ll k,vector<ll> &S){
    if (l+1 == r){
        return r;
    }
    ll center = (l+r)/2;
    ll clears = S.end() - lower_bound(S.begin(),S.end(),center);
    // cout << center << ":" << clears << endl;
    if (clears > k){
        // cout << "l" << endl;
        return boarder(center,r,k,S);
    }else{
        // cout << "r" << endl;
        return boarder(l,center,k,S);
    }
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> S;
    for (size_t i = 0; i < N; i++)
    {
        ll s;
        scanf("%lld",&s);
        if (s > 0){
            S.push_back(s);
        }
    }
    sort(S.begin(),S.end());
    ll Q;
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        ll k;
        cin >> k;
        if (S.size() <= k){
            cout << 0 << endl;
        }else{
            cout << boarder(0,1000001,k,S) << endl;
        }
    }

    return 0;
}