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

ll BASE_NUM = 1000000007;

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
    ll N,K;
    cin >> N >> K;
    vector<ll> A;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }

   return 0;
}