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

// 1 indexed
void addBIT(long long *BIT, int N, int index, long long v)
{
    int i;
    for (i = index; i < N; i += i & -i)
        BIT[i] += v;
}

long long sumBIT(long long *BIT, int index)
{
    long long retValue = 0;
    int i;
    for (i = index; i > 0; i -= i & -i)
        retValue += BIT[i];
    return retValue;
}

//zero indexed and vector
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

int main(){
    BIT bit(10);
    for(int i = 0;i<10;i++){
        bit.add(i,i);
    }
    for(int i = 0;i<10;i++){
        cout << bit.sum(i) << endl;
    }
    cout << "----------" << endl;
    bit.show();
}
