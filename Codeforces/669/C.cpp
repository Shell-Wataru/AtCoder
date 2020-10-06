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
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n,-1);
    vector<bool> used(n+1,false);
    ll n_candidate = 0;
    ll last_unknown = 0;
    for(int i = 1;i < n;i++){
        cout << "? " << i+1 << " " << last_unknown + 1 << endl;
        ll result1;
        cin >> result1;
        cout << "? " << last_unknown+1 << " " << i + 1 << endl;
        ll result2;
        cin >> result2;
        if (result1 > result2){
            A[i] = result1;
            used[result1] = true;
        }else{
            A[last_unknown] = result2;
            last_unknown = i;
            used[result2] = true;
        }
    }
    ll unused = -1;
    for(int i = 1;i <= n;i++){
        if (!used[i]){
            unused = i;
        }
    }
    A[last_unknown] = unused;

    cout << "! ";
    for(int i = 0;i < n;i++){
        if (i != 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
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
    //     }
    // cout << flush;
    return 0;
}
