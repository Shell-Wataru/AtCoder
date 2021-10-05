#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;


int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n);
    vector<bool> used(n,false);
    vector<pair<ll,ll>> ans;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    vector<ll> one_indexes;
    for (size_t i = 0; i < n; i++)
    {
        if (A[i] == 1){
            one_indexes.push_back(i);
        }
    }
    reverse(one_indexes.begin(),one_indexes.end());
    // cout << one_indexes.size() << endl;
    for (size_t i = 0; i < n; i++)
    {
        if(A[i] == 2){
            while(!one_indexes.empty() && one_indexes.back() <= i){
                one_indexes.pop_back();
            }
            if (!one_indexes.empty()){
                ans.push_back({i,one_indexes.back()});
                used[one_indexes.back()] = true;
                one_indexes.pop_back();
            }else{
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector<ll> not_used_indexes;
    for (size_t i = 0; i < n; i++)
    {
        if (A[i] != 0 && !used[i]){
            not_used_indexes.push_back(i);
        }
    }
    reverse(not_used_indexes.begin(),not_used_indexes.end());

    for (size_t i = 0; i < n; i++)
    {
        if(A[i] == 3){
            while(!not_used_indexes.empty() && not_used_indexes.back() <= i){
                not_used_indexes.pop_back();
            }
            if (!not_used_indexes.empty()){
                ans.push_back({i,not_used_indexes.back()});
                not_used_indexes.pop_back();
            }else{
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if(A[i] == 1 && !used[i]){
            ans.push_back({i,-1});
        }
    }

    sort(ans.begin(),ans.end());
    vector<pair<ll,ll>> real_ans;
    ll current_row = 0;
    for(auto &p: ans){
        if (p.second == -1){
            real_ans.push_back({current_row,p.first});
        }else{
            real_ans.push_back({current_row,p.first});
            real_ans.push_back({current_row,p.second});
        }
        current_row++;
    }
    cout << real_ans.size() << "\n";
    for (size_t i = 0; i < real_ans.size(); i++)
    {
        cout << real_ans[i].first + 1 << " " << real_ans[i].second + 1 << "\n";
    }
    cout << flush;

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
    //     }
    // cout << flush;
    return 0;
}
