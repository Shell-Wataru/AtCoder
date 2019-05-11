#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

map<long long,long long> decomposite(long long N, map<long long,long long> & primes,long long next_p = 2){
    if (N == 1){
        return primes;
    }


    while (next_p * next_p <= N ) {
        if (N % next_p == 0) {
            primes[next_p] += 1;
            return decomposite(N/next_p,primes,next_p);
        } else {
            next_p++;
        }
    }
    primes[N] += 1;
    return primes;
}

int main()
{
    // 整数の入力
    long long n, m, s, t, i, ui, vi, ai, bi, StartYen;
    StartYen = 1e15;
    vector<map<long long, long long>> G_yen;
    vector<map<long long, long long>> G_snuke;

    cin >> n >> m >> s >> t;
    for (i = 0; i < n; i++)
    {
        map<long long, long long> yen_edges;
        map<long long, long long> snuke_edges;
        G_yen.push_back(yen_edges);
        G_snuke.push_back(snuke_edges);
    }

    for (i = 0; i < m; i++)
    {
        cin >> ui >> vi >> ai >> bi;
        G_yen[ui - 1][vi - 1] = ai;
        G_yen[vi - 1][ui - 1] = ai;
        G_snuke[vi - 1][ui - 1] = bi;
        G_snuke[ui - 1][vi - 1] = bi;
    }

    G yenMap(n, G_yen);
    G snukeMap(n, G_snuke);

    yenMap.dijkstra(s - 1);
    snukeMap.dijkstra(t - 1);
    // yenMap.output();
    // snukeMap.output();

    priority_queue<Exchange, vector<Exchange>, greater<Exchange>> total_costs;

    for (i = 0; i < n; i++)
    {
        // cout << i << ":" << yenMap.minc[i] + snukeMap.minc[i] << endl;
        total_costs.push(Exchange(i, yenMap.minc[i] + snukeMap.minc[i]));
    }

    for (i = 0; i < n; i++)
    {
        bool outputted = false;
        while (!outputted)
        {
            Exchange e = total_costs.top();
            if (e.index >= i)
            {
                outputted = true;
                cout << StartYen - e.cost << endl;
            }
            else
            {
                total_costs.pop();
            }
        }
    }

    return 0;
}