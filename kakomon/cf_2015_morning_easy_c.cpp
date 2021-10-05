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


int main()
{
    ll N,K,M,R;
    cin >> N >> K >> M >> R;
    ll claer_count = 0;
    vector<ll> s(N-1);
    for(ll i = 0; i < N-1;i++){
        cin >> s[i];;
    }
    sort(s.rbegin(),s.rend());
    ll total = 0;
    for (size_t i = 0; i < K-1; i++)
    {
        total += s[i];
    }

    ll remain = R*K - total;
    if (remain > M){
        cout << -1 << endl;
    }else{
        if (K < N && remain <= s[K-1]){
            cout << 0 << endl;
        }else{
            cout << max(0ll, remain) <<  endl;
        }
    }
   return 0;
}