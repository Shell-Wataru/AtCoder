#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    map<ll,ll> counts;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        counts[a]++;
    }
    vector<ll> sorted_counts;
    for(auto p:counts){
        sorted_counts.push_back(p.second);
    }
    ll M = sorted_counts.size();
    sort(sorted_counts.begin(),sorted_counts.end());
    vector<ll> cumSum(M+1);
    for(int i = 0;i < M;i++){
        cumSum[i+1] = cumSum[i] + sorted_counts[i];
    }
    vector<ll> answers(N+1);

    for(int i = 1;i<= N;i++){
        auto index = lower_bound(sorted_counts.begin(),sorted_counts.end(),i) - sorted_counts.begin();
        ll total = cumSum[index] + (M-index)*i;
        // cout << total << endl;
        answers[total/i] = i;
    }
    for(int i = N-1;i>=1;i--){
        answers[i] = max(answers[i],answers[i+1]);
    }
    for(int i = 1;i<=N;i++){
        cout << answers[i] << "\n";
    }
    cout << flush;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
