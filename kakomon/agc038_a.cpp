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
    // 整数の入力
    ll H,W,A,B;
    cin >> H >> W >> A >> B;
    vector<ll> row(H,0);
    vector<ll> col(W,0);
    for(int i = 0;i < A;i++){
        col[i] = 1;
    }
    for(int i = 0;i < B;i++){
        row[i] = 1;
    }
    for(int i = 0;i < H;i++){
        for(int j =0 ;j < W;j++){
            cout << (row[i] ^ col[j]);
        }
        cout << "\n";
    }
    cout << flush;
    return 0;
}