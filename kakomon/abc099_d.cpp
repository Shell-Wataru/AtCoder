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

int main()
{
    // 整数の入力
    ll N, C;
    cin >> N >> C;
    vector<vector<ll>> D(C, vector<ll>(C));
    vector<map<ll, ll>> colors(3);
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> D[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            ll a;
            cin >> a;
            a--;
            colors[(i + j) % 3][a]++;
        }
    }
    ll ans = numeric_limits<ll>::max();
    vector<ll> color_choose(C,-1);
    for (int i = 0; i < 3; i++)
    {
        color_choose[i] = i;
    }
    sort(color_choose.begin(), color_choose.end());
    do
    {
        vector<ll> target_colors(3);
        for (int i = 0; i < C; i++)
        {
            if (color_choose[i] != -1)
            {
                target_colors[color_choose[i]] = i;
            }
        }
        // for(auto c:target_colors){
        //     cout << c << ",";
        // }
        // cout << endl;
        ll score = 0;
        for (int i = 0; i < 3; i++)
        {
            for (auto &p : colors[i])
            {
                score += D[p.first][target_colors[i]] * p.second;
            }
        }
        // cout << "S" << score << endl;
        ans = min(ans,score);
    } while (next_permutation(color_choose.begin(), color_choose.end()));
    cout << ans << endl;
    return 0;
}