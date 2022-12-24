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
namespace mp = boost::multiprecision;

void warshall_floyd(int n, vector<vector<ll>> &d)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N, vector<ll>(N,numeric_limits<ll>::max()/2));
    vector<vector<ll>> answers(N);

    for (int i = 0; i < N/2; i++)
    {
        ll a, b;
        a = (2 * i + 1) % N;
        b = (2 * i + 2) % N;
        G[i][a] = 1;
        answers[i].push_back(a);
        G[i][b] = 1;
        answers[i].push_back(b);
    }
    for (int i = 0; i < N/2; i++)
    {
        ll a, b;
        a = (2*N - 1 - (2 * i + 1)) % N;
        b = (2*N - 1 - (2 * i + 2)) % N;
        G[N-1-i][a] = 1;
        answers[N-1-i].push_back(a);
        G[N-1-i][b] = 1;
        answers[N-1-i].push_back(b);
    }
    if (N % 2 == 1){
        ll a = 0;
        ll b = N-1;
        G[N/2][a] = 1;
        answers[N/2].push_back(a);
        G[N/2][b] = 1;
        answers[N/2].push_back(b);
    }
    for(int i = 0;i < N;i++){
        G[i][i] = 0;
    }
    ll max_d = 0;
    ll max_i = 0;
    ll max_j = 0;
    // warshall_floyd(N,G);
    // for(int i = 0;i < N;i++){
    //     for(int j = 0;j < N;j++){
    //         cout << G[i][j] << ",";
    //         if (G[i][j] > max_d){
    //             max_d = max(max_d,G[i][j]);
    //             max_i = i;
    //             max_j = j;
    //         }
    //     }
    //     cout << endl;
    // }
    for(auto a:answers){
        cout << a[0] + 1 << " " << a[1] + 1 << endl;
    }
    // cout << max_d << endl;
    // cout << max_i << " " << max_j << endl;
    return 0;
}