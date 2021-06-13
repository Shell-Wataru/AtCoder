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

const long long BASE_NUM = 998244353;

void update(vector<string> &result, ll x, ll y, ll d){
    for(int i = -d; i <=d;i++){
        for(int j = -d; j <=d;j++){
            ll current_x = x+i;
            ll current_y = y+j;
            if (0 <= x && x <= 1500 && 0 <= y && y <= 1500 && i*i + j * j <= d*d){
                result[current_x][current_y] = '#';
            }
        }
    }
    result[x][y] = 'o';
}
int main()
{
    // 整数の入力
    vector<string> result(1500,string(1500,'.'));
    vector<pair<ll,ll>> answers;

    ll remain = 100;
    ll head_x = 0;
    ll head_y = 0;
    for(int j = 0; j < 8;j++){
        if (remain == 0){
            break;
        }
        ll base_d = remain;
        for(int i = 0; i< 7;i++){
            if (remain == 0){
                break;
            }
            ll d = remain;
            update(result,head_x + base_d,head_y + 2 * base_d * i+ base_d,d);
            answers.push_back({head_x + base_d,head_y + 2 * base_d * i+ base_d});
            remain--;

        }

        for(int i = 1; i< 7;i++){
            if (remain == 0){
                break;
            }
            ll d = remain;
            update(result,head_x + 2 * base_d * i+base_d,head_y + base_d,d);
            answers.push_back({head_x + 2 * base_d * i+base_d,head_y + base_d});
            remain--;
        }
        head_x += 2* base_d;
        head_y += 2* base_d;
    }
    // for(int i = 0;i < 1500;i++){
    //     cout << result[i] << endl;
    // }
    reverse(answers.begin(),answers.end());
    for(auto p:answers){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}