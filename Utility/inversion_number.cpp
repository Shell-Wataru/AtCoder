#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

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

ll inversion_number(vector<ll> &A){
    BIT<ll> bit(A.size()*2);
    ll ans = 0;
    for (int i = 0; i < A.size(); i++) {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return ans;
}
int main(){
    vector<ll> a = {
        1,2,3,4,5
    };
    vector<ll> b = {
        5,4,3,2,1
    };
    cout << inversion_number(a) << endl;
    cout << inversion_number(b) << endl;
}
