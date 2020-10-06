#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator>  // std::rbegin, std::rend


using namespace std;
using ll = long long;

int solve(){
    ll n,s,k;
    cin >> n >> s >> k;
    set<ll> closed;
    for(int i = 0;i< k;i++){
        ll a;
        cin >> a;
        closed.insert(a);
    }
    for(int i = 0;i< n;i++){
        ll floor1 = s + i;
        ll floor2 = s - i;
        if (1 <= floor1 && floor1 <= n && closed.find(floor1) == closed.end()){
            cout << i << endl;
            return 0;
        }

        if (1 <= floor2 && floor2 <= n && closed.find(floor2) == closed.end()){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
   return 0;
}