#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
double MAX_VALUE = 1000001;
struct Effect
{
    double q, x;
    ll t;
};

int main()
{
    // 整数の入力
    ll N, M, H;
    cin >> N >> M >> H;
    vector<vector<ll>> G(N);
    vector<ll> costs(N);
    vector<ll> D;
    vector<ll> ShortestPaths(N, H);
    vector<ll> LongestPaths(N, 0);
    vector<ll> NecessaryHP(N, H + 1);
    ShortestPaths[0] = 0;
    LongestPaths[0] = 0;
    NecessaryHP[N - 1] = 1;
    vector<vector<double>> distances(N, vector<double>(H + 1, MAX_VALUE));
    for (int i = 1; i <= H; i++)
    {
        distances[N - 1][i] = 0;
    }
    for (size_t i = 0; i < M; i++)
    {
        ll f, t;
        cin >> f >> t;
        f--;
        t--;
        G[f].push_back(t);
    }
    for (size_t i = 0; i < N; i++)
    {
        ll d;
        cin >> d;
        D.push_back(d);
    }
    // cout << "--" << endl;
    for (int from = N - 2; from >= 0; from--)
    {
        for (auto to : G[from])
        {
            NecessaryHP[from] = min(NecessaryHP[from], NecessaryHP[to] + D[to]);
        }
        // cout << NecessaryHP[from] << endl;
    }
    for (int from = 0; from < N; from++)
    {
        for (auto to : G[from])
        {
            ShortestPaths[to] = min(ShortestPaths[to], ShortestPaths[from] + D[to]);
            LongestPaths[to] = max(LongestPaths[to], LongestPaths[from] + D[to]);
        }
    }
    double l = 0;
    double r = MAX_VALUE;
    while (abs(r - l) > 1e-9)
    {
        double center = (r + l) / 2;
        distances[0][H] = center;
        for (int from = N - 2; from >= 0; from--)
        {
            for (int h = max(H - LongestPaths[from], 1LL); h <= H - ShortestPaths[from]; h++)
            {
                if (h < NecessaryHP[from])
                {
                    // cout << from << "," << h  << "," << NecessaryHP[from] << endl;
                    if (from == 0 && h == H)
                    {
                        distances[from][h] = MAX_VALUE;
                    }
                    else
                    {
                        distances[from][h] = H - h + distances[0][H];
                    }
                    continue;
                }
                double expect = 1;
                for (auto to : G[from])
                {
                    if (h - D[to] <= 0)
                    {
                        expect = MAX_VALUE;
                        break;
                    }
                    else
                    {
                        expect += distances[to][h - D[to]] / G[from].size();
                    }
                }
                if (G[from].size() == 0)
                {
                    expect = MAX_VALUE;
                }
                // cout << from << "," << h  << "," << expect << endl;
                if (from == 0 && h == H)
                {
                    distances[from][h] = expect;
                }
                else
                {
                    distances[from][h] = min(expect, H - h + distances[0][H]);
                }
            }
        }
        if (distances[0][H] > center)
        {
            l = center;
        }
        else
        {
            r = center;
        }
    }
    // cout << "==" << endl;
    // for(int i = 0;i < N;i++){
    //     for(int j = 0; j<= H;j++){
    //         cout << distances[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    if (distances[0][H] > 1000000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << fixed << setprecision(12) << distances[0][H] << endl;
    }
    return 0;
}