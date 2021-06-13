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

void sub_solve(ll l,ll r,ll level,vector<vector<ll>> &Ans){
    if (l+1 == r){
        return;
    }
    ll center = (l+r)/2;
    for(int i = l;i < center;i++){
        for(int j = center;j < r;j++){
            Ans[i][j] = level;
            Ans[j][i] = level;
        }
    }
    sub_solve(l,center,level+1,Ans);
    sub_solve(center,r,level+1,Ans);
    return;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<vector<ll>> Ans(N,vector<ll>(N,-1));
    sub_solve(0,N,1,Ans);
    for(int i = 0;i < N-1;i++){
        for(int j = i+1;j <N;j++){
            if (j != i+1){
                cout << " ";
            }
            cout << Ans[i][j];
        }
        cout << "\n";
    }
    cout << flush;
  return 0;
}
