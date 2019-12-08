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
void solve(){
    ll x,y;
    cin >> x >> y;
    if (x == 1){
        if (y == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else if(x == 2 || x == 3){
        if (y <= 3){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "YES" << endl;
    }
    return;
}
int main()
{
    ll q;
    cin >> q;
    for(int i =0;i<q;i++){
        solve();
    }
   return 0;
}