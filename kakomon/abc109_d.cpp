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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> A(H,vector<ll>(W));
    for(int i = 0; i < H;i++){
        for (size_t j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }
    vector<vector<ll>> ans;
    for(ll i = 0; i < H;i++){
        if (i % 2 == 0){
            for (ll j = 0; j < W-1; j++)
            {
                if (A[i][j] % 2 == 1){
                    ans.push_back({i,j,i,j+1});
                    A[i][j]--;
                    A[i][j+1]++;
                }
            }
            if (i != H-1){
                if (A[i][W-1] % 2 == 1){
                    ans.push_back({i,W-1,i+1,W-1});
                    A[i][W-1]--;
                    A[i+1][W-1]++;
                }
            }
        }else{
            for (ll j = W-1; j >= 1; j--)
            {
                if (A[i][j] % 2 == 1){
                    ans.push_back({i,j,i,j-1});
                    A[i][j]--;
                    A[i][j-1]++;
                }
            }
            if (i != H-1){
                if (A[i][0] % 2 == 1){
                    ans.push_back({i,0,i+1,0});
                    A[i][0]--;
                    A[i+1][0]++;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] + 1<< " "<< ans[i][1] + 1<< " "<< ans[i][2] + 1<< " "<< ans[i][3] + 1<< "\n";
    }
    cout << flush;
    return 0;
}
