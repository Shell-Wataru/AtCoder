#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

char at(string &a,ll index, ll from, ll to, bool forward){
    if (forward){
        return a[from+index];
    }else{
        if (a[from-index] == '1'){
            return '0';
        }else{
            return '1';
        }
    }
}
int solve()
{
    ll n;
    scanf("%lld", &n);
    string a,b;
    cin >> a;
    cin >> b;
    vector<ll> moves;
    ll from = 0;
    ll to = n - 1;
    bool forward = true;

    for(int i = n-1; i >= 0;i--){
        if (at(a,i,from,to,forward) == b[i]){
            if (forward){
                to--;
            }else{
                to++;
            }
        }else{
            if (at(a,0,from,to,forward) == b[i]){
                moves.push_back(1);
            }
            moves.push_back(i+1);
            if (forward){
                swap(from,to);
                to++;
                forward = !forward;
            }else{
                swap(from,to);
                to--;
                forward = !forward;
            }
        }
    }
    cout << moves.size();
    for(int i = 0;i < moves.size();i++){
        cout << " ";
        cout << moves[i];
    }
    cout << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
