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
    vector<ll> A(N+1,0);
    vector<ll> B(N+1,0);
    for(int i = 0;i < N;i++){
        ll c,p;
        cin >> c >> p;
        if (c== 1){
            A[i+1] = p;
        }else{
            B[i+1] = p;
        }
    }
    for(int i = 0;i < N;i++){
        A[i+1] +=  A[i];
        B[i+1] +=  B[i];
    }
    ll Q;
    cin >> Q;
    for(int i = 0;i < Q;i++){
        ll l,r;
        cin >> l >> r;
        l--;
        cout << A[r] - A[l] << " " << B[r] - B[l] << endl;
    }
    return 0;
}