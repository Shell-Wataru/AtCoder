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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

class BIT
{
public:
    vector<ll> data;
    BIT(long long n) : data(n) {}
    void add(int index, long long v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    long long sum(int index)
    {
        long long retValue = 0;
        int i;
        for (i = index; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    void show()
    {
        for (auto v : data)
        {
            cout << v << endl;
        }
    }
};

ll inversion_number(vector<ll> &A){
    // 転倒数
    ll N = A.size();
    BIT bit(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return ans;
}

int main()
{
    ll N,X,Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    vector<ll> B(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    for(int i = 0;i < N;i++){
        cin >> B[i];
    }
    ll ans = numeric_limits<ll>::max();
    vector<ll> DP(1ll<<N,numeric_limits<ll>::max());
    DP[0] = 0;
    for(int i = 0;i < 1ll<<N;i++){
        ll pops = __builtin_popcountll(i);
        ll current = 0;
        for(int j = 0;j < N;j++){
            if (!(i & 1ll<<j)){
                DP[i | 1ll<<j] = min(DP[i | 1ll<<j], DP[i] + abs(A[j] - B[pops]) * X + current * Y);
                current++;
            }
        }
   }
    cout << DP[(1ll<<N)-1] << endl;

    return 0;
}