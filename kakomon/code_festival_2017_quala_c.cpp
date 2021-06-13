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

const long long BASE_NUM = 1000000007;

int main()
{
    ll H,W;
    scanf("%lld", &H);
    scanf("%lld", &W);
    vector<ll> counts(26,0);
    for (size_t i = 0; i < H; i++)
    {
        string S;
        cin >> S;
        for (size_t j = 0; j < W; j++)
        {
            counts[S[j] - 'a']++;
        }
    }
    ll odd = 0;
    ll two = 0;
    ll four = 0;
    for(int i = 0;i < 26;i++){
        four += counts[i]/4;
        two += (counts[i]%4)/2;
        odd += counts[i]%2;
    }
    if (H % 2 == 0 && W % 2 == 0){
        ll need_fours = (H/2) * (W/2);
        if (need_fours == four){
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }else if(H % 2 == 0 && W % 2 == 1){
        ll need_fours = (H/2) * (W/2);
        ll need_twos = H/2;
        four = four - need_fours;
        if (four < 0){
            cout << "No" << endl;
            return 0;
        }
        two += four*2;
        two -= need_twos;
        if (two < 0){
            cout << "No" << endl;
            return 0;
        }else{
            cout << "Yes" << endl;
            return 0;
        }
    }else if(H % 2 == 1 && W % 2 == 0){
        ll need_fours = (H/2) * (W/2);
        ll need_twos = W/2;
        four = four - need_fours;
        if (four < 0){
            cout << "No" << endl;
            return 0;
        }
        two += four*2;
        two -= need_twos;
        if (two < 0){
            cout << "No" << endl;
            return 0;
        }else{
            cout << "Yes" << endl;
            return 0;
        }
    }else if(H % 2 == 1 && W % 2 == 1){
        ll need_fours = (H/2) * (W/2);
        ll need_twos = H/2 + W/2;
        ll need_odds = 1;
        // cout << need_fours << endl;
        // cout << need_twos << endl;
        // cout << need_odds << endl;
        four = four - need_fours;
        if (four < 0){
            cout << "No" << endl;
            return 0;
        }
        two += four*2;
        two -= need_twos;
        if (two < 0){
            cout << "No" << endl;
            return 0;
        }
        odd += 2 * two;
        odd -= need_odds;
        if (odd < 0){
            cout << "No" << endl;
            return 0;
        }else{
            cout << "Yes" << endl;
            return 0;
        }
    }
    return 0;
}