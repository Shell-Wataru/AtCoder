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

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<string> A(n);
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    ll cost = 0;
    if (2 * x <= y){
        for(int i = 0;i < n;i++){
            for(auto c:A[i]){
                if (c == '.'){
                    cost += x;
                }
            }
        }
    }else{
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(A[i][j] == '.'){
                    if(j < m -1 && A[i][j+1] == '.'){
                        cost += y;
                        A[i][j+1] = '*';
                    }else{
                        cost += x;
                    }
                    A[i][j] = '*';
                }
            }
        }
    }
    cout << cost << endl;
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
