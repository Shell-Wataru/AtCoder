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
using namespace std;
using ll = long long;

int solve()
{
    ll H,W,N;
    cin >> H >> W >> N;
    map<pair<ll,ll>,ll> count;
    for(int i = 0;i < N;i++){
        ll a,b;
        cin >> a>> b;
        for(int j = -2;j <= 0;j++){
            for(int k = -2;k <= 0;k++){
                ll x_from = a + j;
                ll y_from = b + k;
                ll x_to = x_from + 2;
                ll y_to = y_from + 2;
                if (1 <= x_from && x_to <= H && 1 <= y_from && y_to <= W){
                    count[{x_from,y_from}]++;
                }
            }
        }
    }
    vector<ll> answers(10,0);
    ll zero = (H-2)*(W-2);
    for(auto p:count){
        answers[p.second]++;
        zero--;
    }
    answers[0] += zero;
    for (size_t i = 0; i <= 9; i++)
    {
        cout << answers[i] << endl;
    }
    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}
