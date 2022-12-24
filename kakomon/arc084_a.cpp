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
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    for(int i = 0; i< N;i++){
        cin >> A[i];
    }

    for(int i = 0; i< N;i++){
        cin >> B[i];
    }

    for(int i = 0; i< N;i++){
        cin >> C[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    vector<ll>  DP_B(N+1,0);
    vector<ll>  DP_C(N+1,0);
    for(int i = 0;i < N;i++){
        DP_B[i+1] = DP_B[i] + (lower_bound(A.begin(),A.end(),B[i]) - A.begin());
    }
    // for(auto c:DP_B){
    //     cout << c  <<",";
    // }
    // cout << endl;
    for(int i = 0;i < N;i++){
        // cout << i << " " << lower_bound(B.begin(),B.end(),C[i]) - B.begin() << endl;
        DP_C[i+1] = DP_C[i] + DP_B[lower_bound(B.begin(),B.end(),C[i]) - B.begin()];
    }
    // for(auto c:DP_C){
    //     cout << c  <<",";
    // }
    // cout << endl;
    cout << DP_C[N] << endl;
    return 0;
}