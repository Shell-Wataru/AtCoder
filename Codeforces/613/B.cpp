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

int solve(){
    ll N;
    cin >> N;
    vector<ll> A;
    ll total = 0;
    ll maximum = - BASE_NUM;
    ll min_used = 0;
    ll current = 0;
    ll current_used = 0;
    ll all_positive = true;
    for(int i = 0;i< N;i++){
        ll a;
        cin >> a;
        total += a;
        A.push_back(a);
    }

    for(auto a: A){
        current += a;
        current_used++;
        if (current > maximum){
            maximum = current;
            min_used = current_used;
        }
        if (current <= 0){
            current = 0;
            current_used = 0;
        }
    }

    if (maximum < total || (maximum == total && min_used == N)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for(int i = 0;i< t;i++){
        solve();
    }
    return 0;
}
