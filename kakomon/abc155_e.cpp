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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string N;
    cin >> N;
    reverse(N.begin(),N.end());
    N+= "0";
    ll min_moves = 0;
    bool kuriage = false;
    for(int i = 0;i < N.size()-1;i++){
        ll num =  N[i] - '0';
        ll next_num = N[i+1] - '0';
        if (kuriage){
            num++;
            kuriage = false;
        }
        if (num >= 6){
            kuriage = true;
            min_moves += 10 - num;
        }else if (num == 5){
            if (next_num >= 5){
                kuriage = true;
                min_moves += 10 - num;
            }else{
                min_moves += num;
            }
        }else{
            min_moves += num;
        }
    }
    if (kuriage){
        min_moves++;
    }
    cout << min_moves << endl;
    return 0;
}