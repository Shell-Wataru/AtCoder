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
bool can_make(vector<ll> &A){
    vector<ll> newA;
    for (size_t i = 0; i < A.size(); i++)
    {
        newA.push_back(A[i]);
        while(newA.size() > 1){
            if (newA.size() == 2){
                if (newA[0] < newA[1]){
                    newA.pop_back();
                }else{
                    break;
                }
            }else{
                if (newA[newA.size() - 2] < newA[newA.size() -1]){
                    ll a = newA[newA.size() -1];
                    newA.pop_back();
                    newA.pop_back();
                    newA.push_back(a);
                }else{
                    break;
                }
            }
        }
    }

    return newA.size() == 1;
}
int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n);
    vector<vector<ll>> B;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }

    if (can_make(A)){
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
