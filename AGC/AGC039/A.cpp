#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    string S;
    ll K;
    cin >> S >> K;
    char before = '*';
    if (S[0] != S[S.length() -1]){
        ll s_total = 0;
        ll continues = 0;
        for(int i = 0;i < S.length();i++){
            if (S[i] != before){
                s_total += continues/2;
                continues = 1;
            }else{
                continues++;
            }
            before = S[i];
        }
        s_total += continues/2;
        // cout << s_total << endl;
        cout << s_total * K  << endl;
    }else{
        vector<ll> continues;
        ll current_continue = 0;
        for(int i = 0;i < S.length();i++){
            if (S[i] != before){
                if (current_continue != 0){
                    continues.push_back(current_continue);
                }
                current_continue = 1;
            }else{
                current_continue++;
            }
            before = S[i];
        }
        continues.push_back(current_continue);
        // cout << continues.size() << endl;
        if (continues.size() == 1){
            cout << (continues[0]*K)/2 << endl;
        }else{
            ll first_total = 0;
            ll other_total = 0;
            for(int i = 0;i<continues.size()-1;i++){
                if (i==0){
                    first_total += continues[0]/2;
                    first_total += continues[continues.size()-1]/2;
                    other_total += (continues[0] + continues[continues.size()-1])/2;
                }else{
                    first_total += continues[i]/2;
                    other_total += continues[i]/2;
                }
            }
            // cout << first_total << endl;
            // cout << other_total << endl;
            cout << first_total + other_total * (K - 1) << endl;
        }
    }
   return 0;
}