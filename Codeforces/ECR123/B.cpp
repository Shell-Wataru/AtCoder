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
    ll n;
    cin >> n;
    vector<ll> A(n);
    iota(A.begin(),A.end(),1);
    reverse(A.begin(),A.end());
    for(int i = n-1;i >= 0;i--){
        for(int j = 0;j < n;j++){
            if (j != 0){
                cout << " ";
            }
            cout << A[j];
        }
        cout << "\n";
        if (i > 0){
            swap(A[i],A[i-1]);
        }
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
