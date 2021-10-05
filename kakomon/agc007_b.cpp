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
    ll N;
    cin >> N;
    vector<ll> P(N);
    vector<ll> invP(N);
    for(int i = 0;i < N;i++){
        cin >> P[i];
        P[i]--;
        invP[P[i]] = i;
    }
    vector<ll> a(N);
    vector<ll> b(N);
    for(int i = 0;i < N;i++){
        b[i] = (N+1) * N - (N+1) * i + invP[i];
    }

    for(int i = 0;i < N;i++){
        a[i] = (N+1) * i + invP[i] + 1;
    }
    for(int i = 0;i < N;i++){
        if(i != 0){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    for(int i = 0;i < N;i++){
        if(i != 0){
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;
    // for(int i = 0;i < N;i++){
    //     if(i != 0){
    //         cout << " ";
    //     }
    //     cout << a[i] + b[i];
    // }
    // cout << endl;
    return 0;
}