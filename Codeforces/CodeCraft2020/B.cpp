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
    ll n;
    string S;
    cin >> n;
    cin >> S;
    string minS = S;
    ll minK = 1;
    for (int K = 2; K <= n; K++)
    {
        string newS;
        for(int i = K - 1;i < n;i++){
            newS += S[i];
        }
        if ((n - K ) % 2 == 1){
            for(int i = 0;i< K-1;i++){
                newS += S[i];
            }
        }else{
            for(int i = K - 2;i>= 0;i--){
                newS += S[i];
            }
        }
        if (newS < minS){
            minS = newS;
            minK = K;
        }
    }
    cout << minS << endl;
    cout << minK << endl;
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
