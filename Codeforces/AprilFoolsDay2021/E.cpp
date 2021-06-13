#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

ll BASE_NUM = 998224353;

int count(vector<string> &G, vector<ll> &path){
    ll very = 0;
    ll current_i = 0;
    ll current_j = 0;
    if (G[0][0] == '*'){
        very++;
    }
    for(auto d:path){
        if (d == 0){
            current_i++;
        }else{
            current_j++;
        }
        if (G[current_i][current_j] == '*'){
            very++;
        }
    }
    return very;
}
int solve()
{
    ll H,W;
    cin >> H >> W;
    vector<string> G(H);
    for(int i = 0;i < H;i++){
        cin >> G[i];
    }
    ll very = 0;
    ll current_i = 0;
    ll current_j = 0;
    while(true){
        if (G[current_i][current_j] == '*'){
            very++;
        }
        if (current_j == W -1 && current_i == H -1){
            break;
        }else if (current_j == W -1){
            current_i++;
        }else if (current_i == H - 1){
            current_j++;
        }else if(G[current_i+1][current_j] == '*' && G[current_i][current_j+1] == '*'){
            current_j++;
        }else if(G[current_i+1][current_j] == '*' && G[current_i][current_j+1] == '.'){
            current_i++;
        }else if(G[current_i+1][current_j] == '.' && G[current_i][current_j+1] == '*'){
            current_j++;
        }else{
            current_j++;
        }
    }
    cout << very << endl;
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}