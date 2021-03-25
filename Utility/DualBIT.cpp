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

int main(){
    DualBIT<ll> dual_bit(10);
    // for(int i = 0;i<10;i++){
        dual_bit.add(0,1);
    // }
    // for(int i = 0;i<10;i++){
    cout << dual_bit.get(0) << endl;
    // }
}
