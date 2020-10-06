#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const int BASE_NUM = 1000000007;


//zero indexed and vector
template< typename T>
class BIT
{
public:
    vector<T> data;
    BIT(long long n) : data(n) {}
    void add(int index, T v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    long long sum(int index)
    {
        T retValue = 0;
        for (int i = index; i >= 0; i = (i & (i + 1)) - 1)
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

ll inversion_number(vector<int> &A){
    BIT<int> bit(A.size()*2);
    ll ans = 0;
    for (int i = 0; i < A.size(); i++) {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return ans;
}

ll inversion_number(vector<int> &A,int x){
    vector<int> vals;
    for (int i = 0; i < A.size(); ++i) vals.push_back(A[i] ^ x);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<int> a(A.size());
    for(int i = 0;i < A.size();i++){
        a[i] = lower_bound(vals.begin(), vals.end(), A[i]^x) - vals.begin();
    }
    return inversion_number(a);
}

int solve()
{
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    int x = 0;
    ll current = inversion_number(A,x);
    for(int i = 30;i >=0;i--){
        ll one_inversions = inversion_number(A,x+ (1<<i));
        if (one_inversions < current){
            // cout << i << ":"<< one_inversions<< "," << zero_inversions << endl;
            x += 1<<i;
            current = one_inversions;
        }
    }
    cout << current << " " << x << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
        // }
    // cout << flush;
    return 0;
}
