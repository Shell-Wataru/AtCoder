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
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int solve()
{
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<ll>> B(H, vector<ll>(W));
    for (int i = 0; i < H; i++)
    {
        for(int j = 0;j < W;j++){
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for(int j = 0;j < W;j++){
            cin >> B[i][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < H; i++)
    {
        for(int j = 0;j < W;j++){
            A[i][j] -= B[i][j];
        }
    }

    for (int i = 0; i < H-1; i++)
    {
        for(int j = 0;j < W-1;j++){
            ans += abs(A[i][j]);
            for(int x = 1;x >=0;x--){
                for(int y = 1; y >=0; y--){
                    A[i+x][j+y] -= A[i][j];
                }
            }
        }
    }
    bool is_ok = true;
    for (int i = 0; i < H; i++)
    {
        for(int j = 0;j < W;j++){
            if (A[i][j] != 0){
                is_ok = false;
                break;
            }
        }
    }
    if (is_ok){
        cout << "Yes" << endl;
        cout << ans << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
