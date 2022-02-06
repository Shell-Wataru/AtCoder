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
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> A(H,vector<ll>(W,0));
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            cin >> A[i][j];
        }
    }
    vector<ll> row(H,0);
    vector<ll> column(W,0);
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            row[i]+= A[i][j];
            column[j]+= A[i][j];
        }
    }
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if (j != 0){
                cout << " ";
            }
            cout << row[i] + column[j] - A[i][j];
        }
        cout << endl;
    }
    return 0;
}