#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
    ll H, W;

    cin >> H >> W;
    vector<vector<ll>> data(H, vector<ll>(W, 0));
    // cout << "--" << endl;
    for (int i = 0; i < H; i++)
    {
        ll r;
        cin >> r;
        for (int j = 0; j <= r && j < W; j++)
        {
            if (j == r){
                if(data[i][j] == 1){
                    cout << 0 << endl;
                    return 0;
                }
                data[i][j] = -1;
            }else{
                if(data[i][j] == -1){
                    cout << 0 << endl;
                    return 0;
                }
                data[i][j] = 1;
            }
        }
    }
    // cout << "--" << endl;

    for (int i = 0; i < W; i++)
    {
        ll c;
        cin >> c;
        for (int j = 0; j <= c && j < H; j++)
        {
            if(j == c){
                if (data[j][i] == 1){
                    cout << 0 << endl;
                    return 0;
                }
                data[j][i] = -1;
            }else{
                if (data[j][i] == -1){
                    cout << 0 << endl;
                    return 0;
                }
                data[j][i] = 1;
            }
        }
    }
    // cout << "--" << endl;

    ll total = 1;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (data[i][j] == 0)
            {
                total = total * 2 % BASE_NUM;
            }
        }
    }
    // cout << "--" << endl;

    cout << total << endl;
    return 0;
}