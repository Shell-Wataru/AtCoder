#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;


int solve()
{
    // cout << "==" << endl;
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    ll odds = 0;
    ll evens = 0;
    bool has_next = false;
    for(int i = 0;i < N;i++){
        if (A[i] % 2 == 0){
            odds++;
        }else{
            evens++;
        }
        if (i > 0 && A[i] - A[i-1] == 1){
            has_next = true;
        }
    }
    if (has_next || (odds % 2 == 0 && evens % 2 == 0)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
