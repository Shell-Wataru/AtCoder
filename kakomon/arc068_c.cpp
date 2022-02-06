#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> total(M + 2,0);
    for (int i = 0; i < N; i++)
    {
        ll l, r;
        cin >> l >> r;
        r++;
        total[l] += 1;
        total[r] -= 1;
    }
    for(int i = 0;i <= M;i++){
        total[i+1] += total[i];
    }
    for(int i = 1;i <= M;i++){
        ll ans = 0;
        for(int j = 0;i * j <= M;j++){
            ans += total[i*j];
        }
        cout << ans << "\n";
    }
    cout << flush;
    return 0;
}