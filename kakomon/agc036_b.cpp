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

ll get_period(ll N, ll K,vector<ll> &next_same_index){
    ll i = 0;
    ll j = 0;
    while(true){
        if (i < next_same_index[i] ){
            i = next_same_index[i] + 1;
        }else{
            j++;
            i = next_same_index[i]+1;
        }
        if (i == N){
            return j+1;
        }
    }
}
int solve()
{
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> last_occur(200000,-1);
    vector<ll> next_same_index(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
        A[i]--;
    }
    for(int i = N-1;i>=0;i--){
        next_same_index[i] = last_occur[A[i]];
        last_occur[A[i]] = i;
    }
    for(int i = N-1;i>=0;i--){
        next_same_index[i] = last_occur[A[i]];
        last_occur[A[i]] = i;
    }
    ll i = 0;
    ll j = 0;
    vector<ll> ans;
    ll period = get_period(N,K,next_same_index);
    // cout << period << endl;
    while(j < (K % period)){
        if (i < next_same_index[i] ){
            i = next_same_index[i] + 1;
        }else{
            if (j+1 == K % period){
                ans.push_back(A[i]);
                i++;
            }else{
                j++;
                i = next_same_index[i]+1;
            }
        }
        if (i == N){
            i = 0;
            j++;
        }
    }
    for(int i = 0;i < ans.size();i++){
        if (i != 0){
            cout << " ";
        }
        cout << ans[i] + 1;
    }
    cout << "\n";
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
