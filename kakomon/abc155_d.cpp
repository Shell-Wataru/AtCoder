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

ll divide_up(ll a,ll b){
    if (a > 0 && b> 0){
        return (a+b-1)/b;
    }else if (a > 0 && b < 0){
        return a/b;
    }else if (a < 0 && b > 0){
        return a/b;
    }else if (a < 0 && b < 0){
        return (a+b+1)/b;
    }else{
        return 0;
    }

}

ll divide_down(ll a,ll b){
    if (a > 0 && b> 0){
        return a/b;
    }else if (a > 0 && b < 0){
        return (a-b-1)/b;
    }else if (a < 0 && b > 0){
        return (a-b+1)/b;
    }else if (a < 0 && b < 0){
        return a/b;
    }else{
        return 0;
    }
}

ll answer(ll l, ll r, vector<ll> &A,ll K){
    if (l+1 == r){
        return r;
    }
    ll center = (l+r)/2;
    ll count = 0;
    ll n = A.size();
    for(int i = 0;i < n;i++){
        if (A[i] < 0){
            ll gte =  divide_up(center,A[i]);
            // cout << "gte" << gte << ":"<< A.end() - lower_bound(A.begin()+i+1,A.end(),gte) << endl;
            count += A.end() - lower_bound(A.begin()+i+1,A.end(),gte);
        }else if (A[i] == 0){
            if (center >= 0){
                count += n - i - 1;
            }
        }else{
            ll lte =  divide_down(center,A[i]);
            // cout << "lte" << lte << ":"<< upper_bound(A.begin()+i+1,A.end(),lte) - (A.begin() + i + 1) << endl;
            count += upper_bound(A.begin()+i+1,A.end(),lte) - (A.begin() + i + 1);
        }
    }
    // cout << center << ":" << count << endl;
    if (count >= K){
        return answer(l,center,A,K);
    }else{
        return answer(center,r,A,K);

    }
}
int main()
{
    // 整数の入力
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    cout << answer(numeric_limits<ll>::min()/2,numeric_limits<ll>::max()/2,A,K) << endl;
    return 0;
}