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

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    ll S = 1LL << N;
    vector<double> DP(S, numeric_limits<double>::max());
    vector<vector<pair<ll, double>>> probabilties;
    vector<double> costs;
    for (int i = 0; i < M; i++)
    {
        ll C, cost;
        cin >> C >> cost;
        costs.push_back(cost);
        vector<pair<ll, double>> ps;
        for (int j = 0; j < C; j++)
        {
            ll idol;
            double p;
            cin >> idol >> p;
            idol--;
            ps.push_back({idol, p /100});
        }
        probabilties.push_back(ps);
    }
    DP[0] = 0;
    for (int s = 1; s < S; s++)
    {
        double min_cost = numeric_limits<double>::max();
        for (int i = 0; i < M; i++)
        {
            double cost = costs[i];
            double used_p = 0;
            for (auto p : probabilties[i])
            {
                if (s & (1LL << p.first))
                {
                    used_p += p.second;
                }
            }
            if (used_p == 0.0){
                // cout << "no" << endl;
                continue;
            }
            double current_cost = cost / used_p;

            for (auto p : probabilties[i])
            {
                if (s & (1LL << p.first))
                {
                    current_cost += DP[s ^ (1LL << p.first)] * p.second / used_p;
                }
            }
            min_cost = min(min_cost, current_cost);
        }
        DP[s] = min_cost;
    }

    cout << fixed << setprecision(12) <<DP[S-1] << endl;

    return 0;
}