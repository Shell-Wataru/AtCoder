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

int dfs(ll x, ll y, vector<string> &G){
    if (0 <= x && x < G.size() && 0 <= y && y < G.size()){
        if (G[x][y] == '1'){
            G[x][y] = '0';
            dfs(x-1,y,G);
            dfs(x,y-1,G);
        }
    }
    return 0;
}

int solve()
{

    ll N;
    cin >>  N;
    vector<string> G(N);
    for(int i = 0;i < N;i++){
        cin >> G[i];
    }
    for(int i = 0;i < N;i++){
        dfs(N-1,i,G);
    }
    for(int i = 0;i < N;i++){
        dfs(i,N-1,G);
    }
    bool ans = true;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if (G[i][j] == '1'){
                ans = false;
                break;
            }
        }
    }
    if (ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}