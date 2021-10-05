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
    ll n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    while(k > 0){
        string next_s;
        for(int i = 0;i < s.size();i++){
            if (s[(2*i)%s.size()] == 'R' && s[(2*i+1)%s.size()] == 'S'){
                next_s+= 'R';
            }else if (s[(2*i)%s.size()] == 'S' && s[(2*i+1)%s.size()] == 'P'){
                next_s+= 'S';
            }else if (s[(2*i)%s.size()] == 'P' && s[(2*i+1)%s.size()] == 'R'){
                next_s+= 'P';
            }else if (s[(2*i)%s.size()] == 'R' && s[(2*i+1)%s.size()] == 'P'){
                next_s+= 'P';
            }else if (s[(2*i)%s.size()] == 'S' && s[(2*i+1)%s.size()] == 'R'){
                next_s+= 'R';
            }else if (s[(2*i)%s.size()] == 'P' && s[(2*i+1)%s.size()] == 'S'){
                next_s+= 'S';
            }else{
                next_s+= s[(2*i)%s.size()];
            }
        }
        s = next_s;
        k--;
    }
    cout << s[0] << endl;
    return 0;
}