#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long N,K,total,remain;
    set<ll> s;
    cin >> N >> K;
    remain = (N+1)/2;
    total=0;
    for(int i = 0;i<N;i++){
        ll a;
        cin >> a;
        if (s.find(a) != s.end()){
            total+= 2;
            remain--;
            s.erase(a);
        }else{
            s.insert(a);
        }
    }

    cout << total + remain << endl;

    return 0;
}