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

int solve()
{

    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    for(int i = 0;i < N;i++){
        scanf("%lld", &a[i]);
    }
    for(int i = 0;i < N;i++){
        scanf("%lld", &b[i]);
    }
    map<pair<ll,ll>,ll> a_pairs;
    map<pair<ll,ll>,ll> b_pairs;
    for(int i = 0;i < N/2;i++){
        a_pairs[{min(a[i],a[N-i-1]),max(a[i],a[N-i-1])}]++;
    }
    for(int i = 0;i < N/2;i++){
        b_pairs[{min(b[i],b[N-i-1]),max(b[i],b[N-i-1])}]++;
    }
    if (N % 2 == 0){
        if (a_pairs == b_pairs){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        if (a_pairs == b_pairs && a[N/2] == b[N/2]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}