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

    ll max_total_floors = -1;
    ll max_index = -1;
    for(int i = 0; i< n;i++){
        ll total_floors = M[i];
        ll m = M[i];
        for(int j = i - 1;j >= 0; j--){
            m = min(m,M[j]);
            total_floors += m;
        }

        m = M[i];
        for(int j = i + 1;j < n; j++){
            m = min(m,M[j]);
            total_floors += m;
        }
        // cout << total_floors << endl;
        if (total_floors >= max_total_floors){
            max_total_floors = total_floors;
            max_index = i;
        }
    }

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

    // cout << max_total_floors << endl;
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
