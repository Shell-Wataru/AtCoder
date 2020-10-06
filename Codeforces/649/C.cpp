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
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n,0);
    vector<ll> B(n,0);
    for(int i = 0; i< n;i++){
        scanf("%lld", &A[i]);
    }
    bool can_make = true;
    vector<ll> remains;
    ll last = 0;
    for(int i = 0;i < n;i++){
        if (A[i] != last){
            if (A[i] - last - 1 > remains.size()){
                can_make = false;
                break;
            }
            for(int j = 0;j < A[i] - last - 1;j++){
                ll remain_index = remains.back();
                remains.pop_back();
                B[remain_index] = last + 1 +j;
            }
            B[i] = last;
            last = A[i];
        }else{
            remains.push_back(i);
        }
    }
    for(auto r:remains){
        B[r] = 1000000;
    }
    if (can_make){
        for (size_t i = 0; i < n; i++)
        {
            if (i != 0){
                cout << " ";
            }
            cout << B[i];
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
