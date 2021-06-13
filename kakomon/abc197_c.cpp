#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    vector<vector<set<ll>>> DP(n,vector<set<ll>>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;i+j<n;j++){
            ll total = 0;
            // cout << j << "~" << i+j << endl;
            for(int k = j;k <= i+j;k++){
                total = total | A[k];
            }
            DP[j][i+j].insert(total);
            for(int k = j;k < i+j;k++){
                for(auto a:DP[j][k]){
                    ll b_total = 0;
                    for(int l = k+1;l<= i+j;l++){
                        b_total = b_total | A[l];
                    }
                    DP[j][i+j].insert(a ^ b_total);
                }
            }
        }
    }
    // cout << DP[0][n-1].size() << endl;
    cout << *DP[0][n-1].begin() << endl;
  return 0;
}
