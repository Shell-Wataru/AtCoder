#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> M(n);
    for(int i = 0;i < n;i++){
        cin >> M[i];
    }

    vector<pair<ll,ll>> ascending_m;
    vector<ll> ascending_m_sums;
    ascending_m_sums.push_back(0);
    ascending_m.push_back({0,-1});
    // cout << "a" << endl;
    for(int i = 0;i < n;i++){
        if (i > 0 && M[i-1] < M[i]){
            ascending_m_sums.push_back(ascending_m_sums.back() + M[i]);
            ascending_m.push_back({M[i],i});
        }else{
            auto data = lower_bound(ascending_m.begin(),ascending_m.end(), make_pair(M[i],0LL));
            ll index = (*data).second;
            // cout << "i" << i <<"index" << index << endl;
            ascending_m_sums.push_back(ascending_m_sums[index] + M[i] * (i - index + 1));
        }

        if (ascending_m.back().first < M[i]){
            ascending_m.push_back({M[i],i});
        }
    }
// cout << "b" << endl;
    vector<pair<ll,ll>> descending_m;
    vector<ll> descending_m_sums;
    descending_m_sums.push_back(0);
    descending_m.push_back({0,n});
    for(int i = n - 1;i >= 0;i--){
        if (i != n - 1 && M[i+1] < M[i]){
            descending_m_sums.push_back(descending_m_sums.back() + M[i]);
        }else{
            auto data = lower_bound(descending_m.begin(),descending_m.end(), make_pair(M[i],0LL));
            ll index = (*data).second;
            // cout << "i" << i <<"index" << index << " "<< descending_m_sums[n - index] << endl;
            descending_m_sums.push_back(descending_m_sums[n - index] + M[i] * (index - i));
        }

        if (descending_m.back().first < M[i]){
            descending_m.push_back({M[i],i});
        }
    }

    for(int i  =  0;i<= n;i++){
        if (i == 0){
            cout << ascending_m_sums[i];
        }else{
            cout << " " <<ascending_m_sums[i];
        }
    }
    cout << endl;

    for(int i  =  0;i<= n;i++){
        if (i == 0){
            cout << descending_m_sums[i];
        }else{
            cout << " " <<descending_m_sums[i];
        }
    }
    cout << endl;
    ll max_total_floors = -1;
    ll max_index = -1;
    for(int i = 0; i <  n;i++){
        ll total_floors = ascending_m_sums[i+ 1] + descending_m_sums[n - i] -  M[i];
        cout << total_floors << endl;
        // cout << ascending_m_sums[i] << descending_m_sums[n - i + 1] <<  M[i - 1] << total_floors << endl;
        if (total_floors > max_total_floors){
            max_total_floors = total_floors;
            max_index = i;
        }
    }

// cout << "d" << endl;
// cout << max_index << endl;
    vector<ll> answer(n);
    answer[max_index] = M[max_index];
    ll m = M[max_index];
    for(int j = max_index - 1;j >= 0; j--){
        m = min(m,M[j]);
        answer[j] = m;
    }

    m = M[max_index];
    for(int j = max_index + 1;j < n; j++){
        m = min(m,M[j]);
        answer[j] = m;
    }

    cout << max_total_floors << endl;
    for(int i  =  0;i< n;i++){
        if (i == 0){
            cout << answer[i];
        }else{
            cout << " " <<answer[i];
        }
    }
    cout << endl;
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
    return 0;
}
