#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>
#include <stack>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 2;

int main()
{
    // 整数の入力
    ll n,k;
    cin >> n >> k;
    vector<ll> results(k*n,-1);
    set<ll> sent_ids;
    vector<ll> best_ranks(1000000,numeric_limits<ll>::max());
    for (ll i = 0; i < n; i++)
    {
        for(ll j = 0;j < k;j++){
            ll a;
            cin >> a;
            results[n*j+i] = a;
            best_ranks[a] = min(n*j+i,best_ranks[a]);
        }
        ll count = 0;
        vector<ll> new_qualifier;
        for(int j = 0; j < n*k;j++){
            if(results[j] == -1){
                count++;
            }else if (best_ranks[results[j]] == j){
                count++;
                if (count <= k && sent_ids.find(results[j]) == sent_ids.end()){
                    new_qualifier.push_back(results[j]);
                    sent_ids.insert(results[j]);
                }
            }
        }
        sort(new_qualifier.begin(),new_qualifier.end());
        for(int j = 0; j < new_qualifier.size();j++){
            if (j != 0){
                cout << " ";
            }
            cout << new_qualifier[j];
        }
        cout << endl;
    }
    return 0;
}