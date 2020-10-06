#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N,L;
    vector<pair<ll,ll>> X;
    cin >> N;
    for(int i = 0;i<N;i++){
        ll x,l;
        cin >> x;
        cin >> l;
        X.push_back({x+l,x-l});
    }
    sort(X.begin(),X.end());
    ll last_r= X[0].first;
    ll counts = 1;
    for(int i = 1;i<N;i++){
        if (X[i].second >= last_r){
            last_r = X[i].first;
            counts++;
        }
    }
    cout << counts++ << endl;
   return 0;
}