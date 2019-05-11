#include<iostream>
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
namespace mp = boost::multiprecision;

bool is_correct(string S,ll first_term_end,mp::cpp_int d ,mp::cpp_int second_term){
    if (d <= 0){
        return false;
    }

    string second_term_string = second_term.str();
    for (int i = 0; first_term_end + i < S.size() && i < second_term_string.size() ;i++){
        if (second_term_string[i] != S[i + first_term_end]){
            return false;
        }
    }
    if (first_term_end + second_term_string.size() < S.size()){
        return is_correct(S,first_term_end + second_term_string.size(), d,second_term + d);
    }else {
        return true;
    }
}

int main()
{
    // 整数の入力
    string S;
    long long f,d;
    d = 1;
    cin >> S;
    string first_term_string = "";
    mp::cpp_int first_term;
    ll first_term_end = 0;
    for (first_term_end = 1;first_term_end < S.size();first_term_end++){
        if (S[first_term_end] != '0'){
            break;
        }
    }

    first_term_string = S.substr(0,first_term_end);
    first_term.assign(first_term_string);
    if (first_term == 0){
        first_term_string = "1" + first_term_string;
    }
    first_term.assign(first_term_string);

    if (first_term_end == S.size()){
        cout << first_term << " 1" << endl;
        return 0;
    }else {
        string second_term_string = "";
        for(int i= first_term_end ;i < S.size();i++){
            second_term_string.push_back(S[i]);
            mp::cpp_int second_term(second_term_string);
            if (is_correct(S,first_term_end,second_term - first_term,second_term)){
                // cout << second_term << endl;
                cout << first_term << " " << second_term - first_term << endl;
                return 0;
            }
        }
        // cout << "----" << endl;
        string second_term_low_string =  second_term_string + string(first_term_string.size() - second_term_string.size(), '0');
        string second_term_high_string =  second_term_string + string(first_term_string.size() - second_term_string.size(), '9');
        string second_term_next_digit_string =  second_term_string + string(first_term_string.size() - second_term_string.size() + 1, '0');
        // cout << second_term_low_string << " " << second_term_high_string << " " << first_term_string << endl;
        if (second_term_low_string > first_term_string){
            mp::cpp_int second_term(second_term_low_string);
            cout << first_term << " " << second_term - first_term << endl;
        }else if(second_term_high_string > first_term_string){
            mp::cpp_int second_term(second_term_low_string);
            cout << first_term << " 1" << endl;
        }else{
            mp::cpp_int second_term(second_term_next_digit_string);
            cout << first_term << " " << second_term - first_term << endl;
        }
    }
    return 0;
}
