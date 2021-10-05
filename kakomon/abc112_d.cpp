#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;


int main()
{
    ll N,M;
    cin >> N >> M;
    ll ans = 1;
    for(ll i = 1; i*i <= M;i++){
        if (M % i == 0){
            if (M/i >= N){
                ans = max(ans,i);
            }
            if (i >= N){
                ans = max(ans,M/i);
            }
        }
    }
    cout << ans << endl;
   return 0;
}