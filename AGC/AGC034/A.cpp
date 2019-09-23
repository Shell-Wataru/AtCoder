#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    long long N,A,B,C,D;
    string S;
    cin >> N >> A >> B >> C >> D;
    cin >> S;
    if (C < D){
        bool a_can_clear = true;
        bool b_can_clear = true;
        for (int i = A;i< C;i++){
            if (S[i] == '#' && S[i-1] == '#'){
                // cout << "cannotclear" << endl;
                a_can_clear = false;
            }
        }
        for (int i = B;i< D;i++){
            if (S[i] == '#' && S[i-1] == '#'){
                // cout << "cannotclear" << endl;
                b_can_clear = false;
            }
        }
        if (a_can_clear && b_can_clear){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        bool a_can_clear = true;
        bool b_can_clear = true;
        for (int i = A;i< C;i++){
            if (S[i] == '#' && S[i-1] == '#'){
                // cout << "cannotclear" << endl;
                a_can_clear = false;
            }
        }
        for (int i = B;i< D;i++){
            if (S[i] == '#' && S[i-1] == '#'){
                // cout << "cannotclear" << endl;
                b_can_clear = false;
            }
        }
        bool can_oikoshi = false;
        for (int i = B - 1;i< D;i++){
            if (S[i-1] == '.' && S[i] == '.' && S[i+1] == '.'){
                // cout << "oikoshi" << endl;
                can_oikoshi = true;
            }
        }

        if (a_can_clear && b_can_clear && can_oikoshi){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}