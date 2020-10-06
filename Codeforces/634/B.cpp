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
    ll n,a,b;
    cin >> n >> a >> b;
    string S = "";
    for(int i = 0; i< n;i++){
        if(i >= a){
            S += S[i-a];
        }else{
            S += 'a' + min((ll)i,b-1);
        }
    }
    cout << S << endl;
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
