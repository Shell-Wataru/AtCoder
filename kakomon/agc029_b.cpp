#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    map<ll,ll> needs;
    sort(A.rbegin(),A.rend());
    ll ans  = 0;
    for(int i = 0;i < N;i++){
        // cout << A[i] << endl;
        if (needs[A[i]] > 0){
            ans++;
            needs[A[i]]--;
        }else{
            ll over_power = 1;
            while(over_power <= A[i]){
                over_power = over_power<<1ll;
            }
            ll need = over_power - A[i];
            needs[need]++;
        }

    }
    cout << ans << endl;
  return 0;
}
