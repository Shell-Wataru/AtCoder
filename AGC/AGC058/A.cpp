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

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int solve(){
    ll N;
    cin >> N;
    vector<ll> a(2*N);
    for(int i = 0;i < 2*N;i++){
        cin >> a[i];
    }
    vector<ll> ans;
    for(int i = 0;i < 2*N-1;i++){
        if (i % 2 == 0){
            if (a[i] > a[i+1]){
                if (i + 2 < 2*N && a[i] < a[i+2]){
                    ans.push_back(i+2);
                    swap(a[i+1],a[i+2]);
                }else{
                    ans.push_back(i+1);
                    swap(a[i],a[i+1]);
                }
            }
        }else{
            if (a[i] < a[i+1]){
                if (i + 2 < 2*N && a[i] > a[i+2]){
                    ans.push_back(i+2);
                    swap(a[i+1],a[i+2]);
                }else{
                    ans.push_back(i+1);
                    swap(a[i],a[i+1]);
                }
            }
        }
    }
    // for(auto aa:a){
    //     cout << aa << " ";
    // }
    // cout << endl;
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++){
        if (i != 0){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
    return 0;
}


int main()
{
    // ll t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}