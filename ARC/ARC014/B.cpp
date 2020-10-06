#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    long long N;
    set<string> used_words;
    vector<string> words;
    string last_word = "";
    ll ends_turn = -1;
    cin >> N;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        words.push_back(s);
    }

    for(int i = 0;i < N;i++){
        string s = words[i];
        if (i  != 0){
            if (last_word.back() != s.front() ||  used_words.find(s) != used_words.end()){
                ends_turn = i;
                break;
            }
        }
        last_word = s;
        used_words.insert(s);
    }

    // cout << ends_turn << endl;
    if (ends_turn == -1){
        cout << "DRAW" << endl;
    }else if(ends_turn % 2 == 0){
        cout << "LOSE" << endl;
    }else{
        cout << "WIN" << endl;
    }
    return 0;
}