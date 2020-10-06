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
ll BASE_NUM = 1000000007;

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

ll lcm(ll a,ll b){
    return a * b/ gcd(a,b);
}
int main()
{
    // 整数の入力
    ll X;
    cin >> X;
    ll minimum = X;
    for(ll i = 2;i * i < X;i++){
        if(X % i == 0 && lcm(i,X/i) == X){
            minimum = X/i;
        }
    }
    cout << X/minimum << " " <<minimum << endl;
    return 0;
}
