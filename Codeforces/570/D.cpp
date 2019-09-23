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

int main()
{
    // 整数の入力
    long long t;
    cin >> t;
    for (int i = 0;i< t;i++){
        ll N,aa,bb;
        vector<ll> a,b;
        for(int j = 0; j<N; j++){
            cin >> aa;
            a.push_back(aa);
        }
        for(int j = 0; j<N; j++){
            cin >> bb;
            b.push_back(bb);
        }

        map<ll,ll> bag_a;
        map<ll,ll> bag_b;

        for(int j = 0;j<N;j++){
            bag[a[j]]++;
            if (j != N - 1 && b[j] > b[j+1]){

            }
        }
    }
    return 0;
}