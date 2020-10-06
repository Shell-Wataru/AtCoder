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
    ll n;
    scanf("%lld",&n);
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    vector<vector<ll>> unsorted(1);
    for(int i = 0;i < n;i++){
        if (A[i] == i+1){
            if (!unsorted.back().empty()){
                unsorted.push_back({});
            }
        }else{
            unsorted.back().push_back(A[i]);
        }
    };
    if (unsorted.back().empty()){
        unsorted.pop_back();
    }
    if (unsorted.size() == 0){
        cout << 0 << endl;

    }else if (unsorted.size() == 1){
        vector<ll> dummy(unsorted.back());
        sort(dummy.begin(),dummy.end());
        bool cansort_once = true;
        for(int i = 0;i < dummy.size();i++){
            if (dummy[i] == unsorted.back()[i]){
                cansort_once = false;
                break;
            }
        }
        if (cansort_once){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }else{
        cout << 2 << endl;
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
