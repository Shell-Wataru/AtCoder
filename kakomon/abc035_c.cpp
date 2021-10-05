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

int main()
{
    ll N,Q;
    cin >> N >> Q;
    vector<ll> imos(N+1,0);
    for (size_t i = 0; i < Q; i++)
    {
        ll l,r;
        cin >> l >> r;
        l--;
        imos[l] += 1;
        imos[r] += -1;
    }
    for(int i = 0;i < N;i++){
        imos[i+1] += imos[i];
    }

    for(int i = 0;i < N;i++){
        if (imos[i] % 2 == 0){
            cout << '0';
        }else{
            cout << '1';
        }
    }
    cout << endl;
   return 0;
}