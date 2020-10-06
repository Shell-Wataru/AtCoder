#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n,-1);
    vector<bool> used(n+1,false);
    ll n_candidate = 0;
    ll last_unknown = 0;
    for(int i = 1;i < n;i++){
        cout << "? " << i+1 << " " << last_unknown + 1;
        ll result1;
        cin >> result1;
        cout << "? " << last_unknown+1 << " " << i + 1;
        ll result2;
        cin >> result2;
        if (result1 > result2){
            A[i] = result1;
            used[result1] = true;
        }else{
            A[last_unknown] = result2;
            last_unknown = i;
            used[result2] = true;
        }
    }
    ll unused = -1;
    for(int i = 1;i <= n;i++){
        if (!used[i]){
            unused = i;
        }
    }
    A[last_unknown] = unused;

    cout << "! ";
    for(int i = 0;i < n;i++){
        if (i != 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    return 0;
}
int main()
{
    vector<ll> ans = {4,3,2,1};
    cout << ans.size() << endl;
    while(true){
        char c;
        ll x,y;
        cin >> c;
        if (c == '?'){
            cin >> x >> y;
            cout << ans[x-1] % ans[y-1] << endl;
        }else{
            bool clear = true;
            for(int i = 0;i < ans.size();i++){
                ll a;
                cin >> a;
                if (ans[i] != a){
                    clear = false;
                }
            }
            if (clear){
                cerr << "clear!!!" << endl;
            }else{
                cerr << "failed..." << endl;
            }
            break;
        }
    }
    return 0;
}
