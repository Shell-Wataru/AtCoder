#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll H ,W;
    cin >> H >> W;
    vector<string > G(H);
    for(int i = 0;i < H;i++){
        cin >> G[i];
    }
    ll answer = 0;
    for(int i = 0;i < H -1;i++){
        for(int j = 0;j < W-1;j++){
            ll whites = 0;
            if (G[i][j] == '.'){
                whites++;
            }
            if (G[i+1][j] == '.'){
                whites++;
            }
            if (G[i][j+1] == '.'){
                whites++;
            }
            if (G[i+1][j+1] == '.'){
                whites++;
            }
            if (whites % 2 == 1){
                answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}