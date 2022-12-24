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
ll BASE_NUM = 1000000007;

int solve()
{
    ll n,a,b;
    scanf("%lld",&n);
    scanf("%lld",&a);
    scanf("%lld",&b);
    string s;
    cin >> s;
    char last = 'a';
    ll group = 0;
    for(int i = 0;i < n;i++){
        if (s[i] != last){
            last = s[i];
            group++;
        }
    }
    if (b < 0){
        cout << n*a + (group/2 + 1)*b << "\n";
    }else{
        cout << n*a + n*b << "\n";
    }
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
    cout << flush;
    return 0;
}
