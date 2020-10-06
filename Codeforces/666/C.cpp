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
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    if(n== 1){
        cout << "1 1"  << endl;
        cout << - A[0] << endl;
        cout << "1 1"  << endl;
        cout << 0 << endl;
        cout << "1 1"  << endl;
        cout << 0 << endl;
    }
    else{
        cout << "1 1"  << endl;
        cout << - A[0] << endl;
        A[0] = 0;
        cout << "2 " << n << endl;
        for(int i = 1;i < n;i++){
            if (i != 1){
                cout << " ";
            }
            cout << (A[i] % n) * (n - 1);
            A[i] = A[i] + (A[i] % n) * (n - 1);
        }
        cout << endl;
        cout << "1 " << n << endl;
        for(int i = 0;i < n;i++){
            if (i != 0){
                cout << " ";
            }
            cout << - A[i];
        }
        cout << endl;
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
    //     }
    // cout << flush;
    return 0;
}
