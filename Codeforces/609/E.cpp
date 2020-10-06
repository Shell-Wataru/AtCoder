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
    ll N;
    cin >> N;
    vector<ll> A;
    map<ll,ll> indexes;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        indexes[a] = i;
        A.push_back[a];
    }
    // 転倒数
    BIT bit(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return 0;
}