#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    ll total = 0;
    vector<ll> others;
    for(int i = 0;i < N;i++){
        if (i < 30){
            A[i] = 1ll<<i;
        }else{
            A[i] = 2*i+1;
            others.push_back(2*i+1);
        }
        total += A[i];
    }
    for(int i = 0;i < N;i++){
        if (i != 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    for(int i = 0;i < N;i++){
        cin >> B[i];
        total += B[i];
        others.push_back(B[i]);
    }
    total /= 2;
    vector<ll> ans;
    for(auto o:others){
        if (total >= o){
            ans.push_back(o);
            total -= o;
        }
    }
    for(int i = 0;i < 30;i++){
        if (total & 1ll<<i){
            ans.push_back(1ll<<i);
        }
    }
    for(int i = 0;i < ans.size();i++){
        if (i != 0){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
    return "";
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        // cout << "Case #" << i  << ": "<< ans <<  endl;
    }

    return 0;
}