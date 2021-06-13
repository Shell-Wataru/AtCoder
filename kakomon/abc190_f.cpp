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

    void show(){
        for (auto v:data){
            cout << v << endl;
        }
    }
};

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    BIT bit(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    cout << ans << endl;
    for(int i = 0;i < N-1;i++){
        ans -= A[i];
        ans += N - 1 - A[i];
        cout << ans << endl;
    }
    return 0;
}