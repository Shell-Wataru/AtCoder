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
    ll normal_sum = 0;
    ll xor_sum = 0;
    for(int i = 0;i<n;i++){
        ll a;
        cin >> a;
        normal_sum += a;
        xor_sum = xor_sum ^ a;
    }
    cout << 2 << endl;
    cout << xor_sum << endl;
    normal_sum = normal_sum + xor_sum;
    // xor_sum = xor_sum ^ xor_sum;
    cout << normal_sum << endl;
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
