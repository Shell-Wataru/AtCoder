#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> daughters(n);
    vector<bool> married_princes(n,false);
    for(int i =0;i< n;i++){
        ll k;
        cin >> k;
        daughters[i] = vector<ll>(k);
        for(int j = 0;j<k;j++){
            cin >> daughters[i][j];
            daughters[i][j]--;
        }
    }
    ll not_married_daugher = -1;
    for(int i = 0;i < n;i++){
        bool married = false;
        for(auto prince:daughters[i]){
            if(!married_princes[prince]){
                married_princes[prince] = true;
                married = true;
                break;
            }
        }

        if(!married){
            not_married_daugher = i;
        }
    }

    ll not_married_prince = -1;
    for(int i = 0;i<n;i++){
        if(!married_princes[i]){
            not_married_prince = i;
            break;
        }
    }
    if (not_married_daugher == -1){
        cout << "OPTIMAL" << endl;
    }else{
        cout << "IMPROVE" << endl;
        cout << not_married_daugher + 1 << " " << not_married_prince + 1 << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
