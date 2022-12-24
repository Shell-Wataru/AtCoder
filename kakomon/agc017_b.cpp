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
#include <set>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    ll diff = abs(A-B);
    for(int i = 0; i< N;i++){
        if ((N-1-i) % 2 != 0){
            continue;
        }
        ll l = C*i - ((N-1-i)/2)* (D-C);
        ll r = D*i + ((N-1-i)/2)* (D-C);
        if (l <= diff && diff <= r){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}