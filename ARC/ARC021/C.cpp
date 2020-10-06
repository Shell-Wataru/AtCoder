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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

ll minimum_a(vector<pair<ll,ll>> &A,ll K,ll l,ll r){
    if (l + 1 == r){
        return l;
    }
    ll center = (l+r)/2;
    // cout << "center " << center << endl;
    ll total = 0;
    for(int i = 0;i< A.size();i++){
        total += max((center - A[i].first + A[i].second - 1)/A[i].second,0LL);
    }
    if (total >= K){
        return minimum_a(A,K,l,center);
    }else{
        return minimum_a(A,K,center,r);
    }
}

int main()
{
    ll K,N;
    cin >> K >> N;
    vector<pair<ll,ll>> A(N);
    for (int i = 0; i < N; i++)
    {
        ll a,d;
        cin >> a >> d;
        A[i] = {a,d};
    }

    ll min_cost =  minimum_a(A,K,0,1e+15);
    // cout << "min_cost" << min_cost << endl;
    mp::cpp_int total_updates = 0;
    mp::cpp_int total_cost = 0;
    for(int i = 0;i< A.size();i++){
        mp::cpp_int updates = max((min_cost - A[i].first + A[i].second - 1)/A[i].second,0ll);
        total_updates += updates;
        total_cost += A[i].first * updates + A[i].second * (updates - 1) * updates/2;
        A[i].first = A[i].first + A[i].second * (ll)updates;
    }
    sort(A.begin(),A.end());
    // cout << total_updates << endl;
    for(int i = 0;i < K - total_updates;i++){
        total_cost += A[i].first;
    }
    cout << total_cost << endl;
    return 0;
}