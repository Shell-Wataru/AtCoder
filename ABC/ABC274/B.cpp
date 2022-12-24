

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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    vector<string> G(H);
    for(int i = 0;i < H;i++){
        cin >> G[i];
    }
    for(int i = 0;i < W;i++){
        ll c= 0;
        if (i != 0){
            cout << " ";
        }
        for(int j = 0;j < H;j++){
            if (G[j][i] == '#'){
                c++;
            }
        }
        cout << c;
    }
    cout << endl;
    return 0;
}