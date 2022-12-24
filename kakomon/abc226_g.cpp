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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

int solve()
{
    vector<ll> A(5);
    vector<ll> B(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cin >> B[i];
    }
    // 5
    ll a = min(A[4],B[4]);
    A[4] -= a;
    B[4] -= a;
    // 4
    a = min(A[3],B[3]);
    A[3] -= a;
    B[3] -= a;
    a = min(A[3],B[4]);
    A[3]-= a;
    B[0] += a;
    B[4] -=a ;
    // 3
    a = min(A[2],B[2]); // 3
    A[2] -= a;
    B[2] -= a;
    a = min(A[2],B[4]);//5
    A[2]-= a;
    B[1] += a;
    B[4] -=a ;
    a = min(A[2],B[3]);//4
    A[2]-= a;
    B[0] += a;
    B[3] -=a ;
    // 2
    for(int i = 4;i >= 1;i--){
        ll b = min(A[1],B[i]);
        A[1]-= b;
        if (i - 2 >= 0){
            B[i-2] += b;
        }
        B[i] -=b;
    }
    // 1
    for(int i = 4;i >= 0;i--){
        ll b = min(A[0],B[i]);
        A[0]-= b;
        if (i - 1 >= 0){
            B[i-1] += b;
        }
        B[i] -=b;
    }
    // for(int i = 0;i < 5;i++){
    //     cout << i +1 << ":" <<  A[i] << "," << B[i] << endl;
    // }
    if (A[0] == 0 && A[1] == 0 && A[2] == 0 && A[3] == 0 && A[4] == 0 ){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}
int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    cout << flush;
    return 0;
}