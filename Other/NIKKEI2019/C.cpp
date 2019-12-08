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

ll BASE_NUM = 998244353;

 bool shift_value(ll N, ll shift,vector<ll> &B,vector<pair<ll,ll>> &AB){
    bool value = true;
    for(int i = 0;i<N;i++){
        if (AB[(i + shift) % N].second != B[i]){
            value = false;
        }
    }
    return value;
}

bool contains_duplicate(vector<ll> &B){
    map<ll,ll> counts;
    for(int i = 0;i<N;i++){
        counts[B[i]]++;
        if (counts[B[i]] > 1){
            return true;
        }

    }
    return false;
}

int main()
{
    // 整数の入力
    ll N;
    vector<ll> A;
    vector<ll> B;
    vector<pair<ll,ll>> AB;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        ll b;
        cin >> b;
        B.push_back(b);
    }
    for (int i = 0; i < N; i++)
    {
        AB.push_back(make_pair(A[i],B[i]));
    }

    sort(AB.begin(),AB.end());
    sort(B.begin(),B.end());
    // for(auto p:AB){
    //     cout << p.first;
    // }
    // cout << endl;
    // for(auto p:AB){
    //     cout << p.second;
    // }
    // cout << endl;
    for(int i = 0;i<N;i++){
        if (AB[i].first > B[i]){
            cout << "No" << endl;
            return 0;
        }
    }

    bool duplicate = shift_value(N,1,B,AB);
    bool is_shift_one = shift_value(N,1,B,AB);
    bool is_shift_n_1 = shift_value(N,N - 1,B,AB);
    if (is_shift_one || is_shift_n_1){
        cout << "No" << endl;
    }else{
        cout << "Yes"  << endl;
    }
    return 0;
}