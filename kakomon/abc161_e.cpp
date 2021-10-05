#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;

int main()
{
    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<ll> works_from_start(N + 1, 0);
    vector<ll> works_from_end(N + 1, 0);
    ll last_work = -2 * C;
    for (int i = 0; i < N; i++)
    {
        if (i - last_work > C && S[i] == 'o')
        {
            works_from_start[i + 1] = works_from_start[i] + 1;
            last_work = i;
        }
        else
        {
            works_from_start[i + 1] = works_from_start[i];
        }
    }
    ll next_work = numeric_limits<ll>::max();
    for (int i = N - 1; i >= 0; i--)
    {
        if (next_work - i > C && S[i] == 'o')
        {
            works_from_end[i] = works_from_end[i + 1] + 1;
            next_work = i;
        }
        else
        {
            works_from_end[i] = works_from_end[i + 1];
        }
    }
    vector<ll> ans;
    for(int i = 0;i < N;i++){
        if (S[i] == 'x'){
            continue;
        }
        ll before_works = works_from_start[i];
        ll after_works = works_from_end[i+1];
        // cout << i << ":" << before_works << "-" << after_works << endl;
        if (before_works + after_works < K){
            ans.push_back(i+1);
        }
    }
    for(auto a:ans){
        cout << a << "\n";
    }
    cout << flush;

    return 0;
}