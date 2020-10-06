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
    cin >> n;
    ll last;
    vector<ll> A;
    for(int i = 0;i< n;i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    last = A[0];

    for(int i = 1;i< n;i++){
        ll a;
        a = A[i];
        if (abs(a-last) >= 2){
            cout << "YES" << endl;
            cout << i << " " << i + 1 << endl;
            return 0;
        }else{
            last = a;
        }
    }
    cout << "NO" <<endl;
    return 0;
}


int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        solve();
    }
    return 0;
}
