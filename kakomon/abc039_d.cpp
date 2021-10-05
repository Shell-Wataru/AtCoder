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

ll ruiseki(vector<vector<ll>> &ruisekiWa, ll from_x, ll from_y, ll to_x, ll to_y)
{
    return ruisekiWa[to_x][to_y] - ruisekiWa[to_x][from_y] - ruisekiWa[from_x][to_y] + ruisekiWa[from_x][from_y];
}

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> G(H);
    vector<string> before(H,string(W,'.'));
    vector<string> after(H,string(W,'.'));
    vector<pair<ll,ll>> directions = {
        {1,1},
        {1,0},
        {1,-1},
        {0,1},
        {0,0},
        {0,-1},
        {-1,1},
        {-1,0},
        {-1,-1}
    };
    for (size_t i = 0; i < H; i++)
    {
        cin >> G[i];
    }

    for(int i= 0; i< H;i++){
        for (size_t j = 0; j < W; j++)
        {
            ll valid_count = 0;
            ll black_count = 0;
            for(auto d: directions){
                ll x = i + d.first;
                ll y = j + d.second;
                if (0 <= x && x < H && 0 <= y && y < W){
                    valid_count++;
                    if (G[x][y] =='#'){
                        black_count++;
                    }
                }
            }
            if (valid_count== black_count){
                before[i][j] = '#';
            }
        }
    }

    for(int i= 0; i< H;i++){
        for (size_t j = 0; j < W; j++)
        {
            if (before[i][j] == '#'){
                for(auto d: directions){
                    ll x = i + d.first;
                    ll y = j + d.second;
                    if (0 <= x && x < H && 0 <= y && y < W){
                        after[x][y] = '#';
                    }
                }
            }
        }
    }
    bool is_same = true;
    // cout << "!!" << endl;
    for(int i = 0;i < H;i++){
        // cout << after[i] << endl;
        if (G[i] != after[i]){
            is_same = false;
        }
    }
    if (is_same){
        cout << "possible" << endl;
        for(auto s:before){
            cout << s << endl;
        }
    }else{
        cout << "impossible" << endl;
    }
    return 0;
}