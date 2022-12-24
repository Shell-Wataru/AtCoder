#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

int main()
{
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<ll> SumA(N+1,0);
    vector<ll> PositiveSumA(N+1,0);
    for(int i = 0;i < N;i++){
        SumA[i+1] = SumA[i] + A[i];
        PositiveSumA[i+1] = PositiveSumA[i] + max(A[i],0ll);
    }
    ll total = SumA[N];
    ll ans = 0;
    for(int i = 0;i + K<= N;i++){
        ans = max(ans,PositiveSumA[N] - PositiveSumA[i+K] + PositiveSumA[i] - PositiveSumA[0] + max(0ll,SumA[i+K] - SumA[i]));
    }
    cout << ans << endl;
    return 0;
}
