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
ll BASE_NUM = 998244353;

ll min_value(vector<ll> &p, vector<ll> &c,vector<ll> &checked,ll from){
    // cout << "++" << endl;
    vector<ll> sequence;
    ll i = from;
    sequence.push_back(i);
    // cout << "a" << endl;
    while(p[i] != from){
        sequence.push_back(p[i]);
        i = p[i];
    }
    // cout << "a" << endl;
    for(auto s:sequence){
        // cout << s << ":" << c[s] << endl;
        checked[s] = true;
    }
    // cout << "a" << endl;
    for(int i =1;i < sequence.size();i++){
        if (sequence.size() % i == 0){
            for(int j = 0; j < i;j++){
                bool all_same = true;
                ll first_color = c[sequence[j]];
                for(int k = 1;k < sequence.size()/i;k++){
                    if(first_color != c[sequence[i*k + j]]){
                        all_same = false;
                        break;
                    }
                }

                if(all_same){
                    return i;
                }
            }
        }
    }
    // cout << "a" << endl;
    return sequence.size();
}

int solve()
{
    ll n;
    cin >> n;
    vector<ll> p(n);
    vector<ll> c(n);
    for(int i = 0;i< n;i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0;i< n;i++){
        cin >> c[i];
    }
    vector<ll> checked(n,false);
    ll min_k = n;
    for(int i = 0;i<n;i++){
        if (!checked[i]){
            min_k = min(min_value(p,c,checked,i),min_k);
        }
    }
    cout << min_k << endl;
    return 0;
}

int main()
{
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}