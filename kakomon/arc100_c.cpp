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
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

vector<ll> trails(ll N)
{
    vector<ll> ret = {0};
    for (int i = 0; i < N; i++)
    {
        vector<ll> t(ret);
        reverse(t.begin(), t.end());
        for (auto n : t)
        {
            ret.push_back(n | 1 << i);
        }
    }
    return ret;
}

ll solve()
{
    ll N;
    cin >> N;
    vector<ll> A(1ll<<N);
    for(int i = 0;i < 1ll<<N;i++){
        cin >> A[i];
    }
    vector<ll> answers(1ll<<N,0);
    vector<vector<pair<ll,ll>>> DP(1ll<<N);
    DP[0].emplace_back(A[0],0);
    for(int i = 1;i < 1ll<<N;i++){
        DP[i].emplace_back(A[i],i);
        unordered_set<ll> inserted = {i};
        for(int j = 0;j < N;j++){
            if (i & 1ll<<j){
                for(auto &p:DP[i^(1ll<<j)]){
                    if (inserted.count(p.second) == 0){
                        DP[i].push_back(p);
                        inserted.insert(p.second);
                    }
                }
            }
        }

        partial_sort(DP[i].begin(),DP[i].begin()+2,DP[i].end(),greater<pair<ll,ll>>());
        while(DP[i].size() > 2){
            DP[i].pop_back();
        }
    }
    for(int i = 1;i < 1ll<<N;i++){
        answers[i] = max(answers[i-1],DP[i][0].first + DP[i][1].first);
        cout << answers[i] << "\n";
    }
    return 0;
}

int main()
{
    // ll N;
    // cin >> N;
    // for(int i = 1; i <= N;i++){
    solve();
    // }
    cout << flush;
    return 0;
}
