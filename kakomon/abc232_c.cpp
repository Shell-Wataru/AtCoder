#define _USE_MATH_DEFINES
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
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> GA(N);
    vector<vector<ll>> GB(N);
    for (int i = 0; i < M; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        GA[a].push_back(b);
        GA[b].push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        sort(GA[i].begin(), GA[i].end());
    }
    for (int i = 0; i < M; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        GB[a].push_back(b);
        GB[b].push_back(a);
    }
    vector<ll> mapping(N);
    iota(mapping.begin(), mapping.end(), 0);
    do
    {
        vector<vector<ll>> newGB(N);
        for (int i = 0; i < N; i++)
        {
            for (auto to : GB[i])
            {
                newGB[mapping[i]].push_back(mapping[to]);
            }
        }
        for (int i = 0; i < N; i++)
        {
            sort(newGB[i].begin(), newGB[i].end());
        }
        if (GA == newGB)
        {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(mapping.begin(), mapping.end()));
    cout << "No" << endl;
    return 0;
}