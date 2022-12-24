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
#include <set>
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

int solve()
{
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    if (h * w == 1)
    {
        cout << "No" << endl;
        return 0;
    }
    ll maximum = 1000000000ll;
    ll base = (maximum - 1) / (h * w - 1);
    vector<vector<ll>> ans(H, vector<ll>(W, base));
    for (int i = 0; i < H / h; i++)
    {
        for (int j = 0; j < W / w; j++)
        {
            ans[h * i + h - 1][w * j + w - 1] = -base * (h * w - 1) - 1;
        }
    }
    ll total = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            total+=  ans[i][j];
        }
    }
    if (total < 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        cout << flush;

    }
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
