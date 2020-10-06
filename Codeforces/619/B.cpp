#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;


int solve(){
    ll n;
    cin >> n;
    vector<ll> A(n);
    for(int i  = 0;i<n;i++){
        cin >> A[i];
    }

    ll max_adjacement = -1;
    ll min_adjacement = BASE_NUM;
    for(int i  = 0;i<n-1;i++){
        if (A[i+1] == -1 && A[i] != -1){
            max_adjacement = max(max_adjacement, A[i]);
            min_adjacement = min(min_adjacement, A[i]);
        }
    }

    for(int i  = 1;i<n;i++){
        if (A[i-1] == -1 && A[i] != -1){
            max_adjacement = max(max_adjacement, A[i]);
            min_adjacement = min(min_adjacement, A[i]);
        }
    }

    ll constant_diff = 0;
    for(int i = 1;i<n;i++){
        if (A[i-1] != -1 && A[i] != -1){
            constant_diff = max(constant_diff, abs(A[i] - A[i-1]));
        }
    }

    if (max_adjacement == -1 && min_adjacement == BASE_NUM){
        cout << constant_diff << " " << 0 << endl;
    }else{
        ll k = (max_adjacement + min_adjacement)/2;
        ll m = max(max_adjacement - k,constant_diff);
        cout << m << " " << k << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for(int i = 1;i<= t;i++){
        solve();
    }
    return 0;
}
