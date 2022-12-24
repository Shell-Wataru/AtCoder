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

int main()
{
    ll H,W;
    scanf("%lld", &H);
    scanf("%lld", &W);
    vector<string> G(H);
    for(int i = 0;i < H;i++){
        cin >> G[i];
    }
    vector<ll> rows;
    vector<ll> columns;
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if (G[i][j] == '#'){
                rows.push_back(i);
                break;
            }
        }
    }
    for(int i = 0;i < W;i++){
        for(int j = 0;j < H;j++){
            if (G[j][i] == '#'){
                columns.push_back(i);
                break;;
            }
        }
    }
    for(auto r:rows){
        for(auto w:columns){
            cout << G[r][w];
        }
        cout << endl;
    }

    return 0;
}