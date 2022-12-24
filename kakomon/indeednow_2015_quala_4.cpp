#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

vector<vector<ll>> directions = {
    {
        1,0
    },
    {
        -1,0
    },
    {
        0,1
    },
    {
        0,-1
    }
};
int dfs(map<vector<vector<ll>>,ll> &d,vector<vector<ll>> &A, ll row,ll column, ll depth){
    ll H = A.size();
    ll W = A[0].size();
    if (d.find(A) == d.end() || depth < d[A]){
        d[A] = depth;
        if (depth == 12){
            return 0;
        }
        for(auto direction:directions){
            ll next_row = row + direction[0];
            ll next_column = column + direction[1];
            if (0 <= next_row && next_row < H &&  0<= next_column && next_column < W){
                swap(A[row][column],A[next_row][next_column]);
                dfs(d,A,next_row,next_column,depth+1);
                swap(A[row][column],A[next_row][next_column]);
            }
        }
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> A(H,vector<ll>(W));
    vector<vector<ll>> B(H,vector<ll>(W));
    ll zero_row;
    ll zero_column;
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            cin >> A[i][j];
            if (A[i][j] == 0){
                zero_row = i;
                zero_column = j;
            }
        }
    }
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            B[i][j] = W*i + j + 1;
        }
    }
    B[H-1][W-1] = 0;
    map<vector<vector<ll>>,ll> d1;
    map<vector<vector<ll>>,ll> d2;
    dfs(d1,A,zero_row,zero_column,0);
    dfs(d2,B,H-1,W-1,0);
    ll ans = 30;
    // cout << d1.size() << endl;
    // cout << d2.size() << endl;
    for(auto p:d1){
        if (d2.find(p.first) != d2.end()){
            ans = min(ans,p.second + d2[p.first]);
        }
    }
    cout << ans << endl;
    return 0;
}