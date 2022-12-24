#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

ll value(vector<vector<ll>> &A,vector<ll> &ys,ll l,ll r){
    ll v = 0;
    for(int i = l;i < r;i++){
        ll d = A[i][0];
        for(auto y:ys){
            d= min(d,abs(y- A[i][1]));
        }
        if (r < A.size()){
            d = min(d,abs(A[r][0]- A[i][0]));
        }
        if (l != 0){
            d = min(d,abs(A[l-1][0]- A[i][0]));
        }
        v += d*A[i][2];
    }
    return v;
}

vector<ll> sub_answer(vector<vector<ll>> &A,vector<ll> &ys){
    ll N = A.size();
    ll M = ys.size()-1;
    vector<ll> answers(N+1,numeric_limits<ll>::max()/2);
    vector<vector<ll>> DP(N+1,vector<ll>(N+1,numeric_limits<ll>::max()/2));
    DP[0][0] = 0;
    for(int j = 0;j < N;j++){
        for(int k = 0;k <= j;k++){
            ll v = value(A,ys,k,j);
            for(int l = 0;l < N;l++){
                DP[j+1][l+1] = min(DP[j+1][l+1],DP[k][l] + v);
            }
        }
    }
    for(int j = 0;j <= N;j++){
        ll v= value(A,ys,j,N);
        for(int k = 0;k <= N;k++){
            answers[k] = min(answers[k],DP[j][k]+v);
        }
    }
    return answers;
}
int solve()
{
    ll N;
    cin >> N;
    vector<vector<ll>> A(N);
    vector<vector<ll>> A1;
    vector<vector<ll>> A2;
    for(int i = 0;i < N;i++){
        ll x,y,p;
        cin >> x>> y >> p;
        A[i] = {x,y,p};
        if (x >= 0){
            A1.push_back(A[i]);
        }else{
            A2.push_back(A[i]);
            A2.back()[0] *= -1;
        }
    }
    sort(A1.begin(),A1.end());
    sort(A2.begin(),A2.end());
    vector<ll> answers(N+1,numeric_limits<ll>::max());
    for(int i=0;i< 1ll<<N;i++){
        vector<ll> ys = {0};
        for(int j = 0;j < N;j++){
            if (i & 1ll<<j){
                ys.push_back(A[j][1]);
            }
        }
        vector<ll> sub_answer1 = sub_answer(A1,ys);
        vector<ll> sub_answer2 = sub_answer(A2,ys);
        // for(auto a:sub_answer1){
        //     cout << a << ",";
        // }
        // cout << endl;

        // for(auto a:sub_answer2){
        //     cout << a << ",";
        // }
        // cout << endl;
        for(int i = 0;i < sub_answer1.size();i++){
            for(int j = 0;j < sub_answer2.size();j++){
                if (i+j+ys.size()-1 > N){
                    break;
                }
                answers[i+j+ys.size()-1] = min(answers[i+j+ys.size()-1],sub_answer1[i]+sub_answer2[j]);
            }
        }
	}
    for(int i = 0;i <= N;i++){
        cout << answers[i] << endl;
    }
    return 0;
}

int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}