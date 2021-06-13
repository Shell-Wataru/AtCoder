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

ll combination(ll n,ll m){
    ll ans = 1;
    for(int i = 1;i <= m;i++){
        ans = ans * (n - i + 1)/i;
    }
    return ans;
}

int main()
{
    ll A,B,K;
    cin >> A >> B >> K;
    ll remainA = A;
    ll remainK = K;
    string ans = "";
    for(int i = 0;i < B;i++){
        int useA = 0;
        while(combination(B-i+useA,useA) < remainK){
            useA++;
        }
        // cout << useA << endl;
        for(int k = 0; k < remainA - useA;k++){
            ans+= 'a';
        }
        ans+= 'b';
        remainK -= combination(B-i+useA-1,useA-1);
        remainA = useA;
    }
    for(int i = 0;i < remainA;i++){
        ans+= 'a';
    }
    cout << ans << endl;
    return 0;
}