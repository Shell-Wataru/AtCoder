#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
using ll = long long;

class BallotCounting {
	public:
	int  count (string s) {
        ll n = s.length();
        ll win_votes = n/2 + 1;
        ll x = 0;
        ll a = 0;
        ll b = 0;
        for(auto &c:s){
            x++;
            if (c == 'A'){
                a++;
            }else{
                b++;
            }
            if (a >= win_votes || b >= win_votes){
                break;
            }
        }
        return x;
	}
};

// int main(){
//     JudgedScoring m;
//     vector<int> a{5,3,2,4};
//     ll ans = m.overallScore(a);
//     cout << ans << endl;
//     return 0;
// }
