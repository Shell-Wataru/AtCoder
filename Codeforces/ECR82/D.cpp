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

int solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> A(n);

    ll total = 0;
    for(int i = 0;i< m;i++){
        cin >> A[i];
        total += A[i];
    }
    if (total < n){
        cout << - 1 << endl;
        return 0;
    }
    sort(A.begin(),A.end());
    ll a_index = 0;
    ll amari = 0;
    ll count = 0;
    for(int i = 0;(1<<i) <= n;i++){
        // cout << i << endl;
        if (n & 1<<i){
            while(amari < 1<<i){
                amari += A[a_index];
                a_index++;
            }
            while(A[a_index-1] > 1<<i){
                count++;
                A[a_index-1] /= 2;
            }
            amari -= 1<<i;
        }
    }
    cout << count << endl;
    return 0;
}
int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for(int i = 0;i< T;i++){
        solve();
    }

    return 0;
}