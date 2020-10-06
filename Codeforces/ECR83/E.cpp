#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

int min(vector<pair<ll,ll>> &A){
    pair<ll,ll> min_pair = {100000,2};
    ll min_pair_index = -1;
    for(int i = 0;i < A.size();i++){
        if(A[i].second() >= 2){

        }
    }
}
int solve()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>> A;
    for(int i = 0;i<n;i++){
        ll a;
        cin >> a;
        if (A.size() == 0 || A.back().first != a){
            A.push_back({a,1});
        }else{
            A.back().second++;
        }
    }
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}