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

// 区間加算　一点取得
//zero indexed and vector
// 区間加算　一点取得
//zero indexed and vector
template< typename T>
class DualBIT
{
public:
    vector<T> data;
    DualBIT(long long n) : data(n) {}
    // [0,index)に足す
    void add(int index, T v)
    {
        for (int i = index - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            data[i] += v;;
        }
    }

    // indexを取得
    long long get(int index)
    {
        T retValue = 0;
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> C(N);
    DualBIT<ll> dual_bit(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> C[i];
        C[i]--;
    }
    vector<ll> last_occurs(N, -1);
    vector<pair<ll, ll>> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].second >> queries[i].first;
        queries[i].second--;
        queries[i].first--;
    }
    vector<pair<ll, ll>> base_queries(queries);
    map<pair<ll,ll>,ll> answers;
    sort(queries.begin(), queries.end());
    ll current_r = -1;
    for (int i = 0; i < Q; i++)
    {
        ll l = queries[i].second;
        ll r = queries[i].first;
        while (current_r != r)
        {
            current_r++;
            ll last_occur = last_occurs[C[current_r]];
            last_occurs[C[current_r]] = current_r;
            dual_bit.add(current_r + 1, 1);
            dual_bit.add(last_occur + 1, -1);
        }
        answers[queries[i]] =  dual_bit.get(l);
    }

    for (int i = 0; i < Q; i++)
    {
        cout << answers[base_queries[i]] << "\n";
    }
    cout << flush;
    return 0;
}