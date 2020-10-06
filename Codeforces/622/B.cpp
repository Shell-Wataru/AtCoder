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
    ll n,x,y;
    cin >> n >> x >> y;
    ll good = max(x+y - n,0ll);
    ll bad = min(x+y - 1,n);
    cout << min(good + 1,n) << " " << bad << endl;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for(int i = 1;i<= t;i++){
        solve();
    }
    return 0;
}
