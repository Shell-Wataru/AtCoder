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
    ll n;
    ll counter = 0;
    cin >> n;

    set<ll> solved;
    for(int i = 0; i< n;i++){
        ll a;
        cin >> a;
        while(a % 2 == 0 && solved.find(a) == solved.end()){
            solved.insert(a);
            a = a/2;
            counter++;
        }
    }
    return counter;
}
int main()
{
    ll t;
    cin >> t;
    for(int i=0;i<t;i++){
        cout << solve() << endl;
    }
   return 0;
}
