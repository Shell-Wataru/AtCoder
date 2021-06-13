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
    vector<ll> A(N);
    for(int i =0;i < N;i++){
        cin >> A[i];
    }
    if (A[0] != 0){
        cout << -1 << endl;
    }else{
        ll ans = 0;
        for(int i = 1;i < N;i++){
            if (A[i] > A[i-1] + 1){
                cout << -1 << endl;
                return 0;
            }else if (A[i] == A[i-1] + 1){
                ans++;
            }else{
                ans += A[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}