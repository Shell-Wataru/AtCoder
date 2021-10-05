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

ll value(vector<ll> &A,vector<ll> &F,ll k, ll l ,ll r){
    if (l+ 1 == r){
        return r;
    }
    ll n = A.size();
    ll center = (l + r)/2;
    ll remain_k = k;
    for(int i = 0;i < n;i++){
        ll new_a = center/F[i];
        remain_k -= max(A[i] - new_a,0ll);
    }
    if (remain_k < 0){
        return value(A,F,k,center,r);
    }else{
        return value(A,F,k,l,center);
    }
}
int main()
{
    // 整数の入力
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n);
    vector<ll> F(n);
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    for(int i = 0;i < n;i++){
        cin >> F[i];
    }
    sort(A.begin(),A.end());
    sort(F.rbegin(),F.rend());
    cout << value(A,F,k,-1,numeric_limits<ll>::max()/2) << endl;
    return 0;
}