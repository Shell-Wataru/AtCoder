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

string sutehuda(vector<string> &deck,string mark){
    string value = "";
    ll count = 0;
    for(int i = 0;i < deck.size();i++){
        // cout << deck[i];
        if (deck[i] == mark + "10" || deck[i] == mark + "J" || deck[i] == mark + "Q" || deck[i] == mark + "K" || deck[i] == mark + "A" ){
            count++;
            if (count >= 5){
                return value;
            }
        }else{
            value += deck[i];
        }
    }
    return value;
}

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    vector<string> deck;
    string card = "";
    for(auto c:S){
        if (c == 'S' || c == 'H' || c == 'D' || c == 'C'){
            if (card != ""){
                deck.push_back(card);
                card = "";
            }
        }
        card += c;
    }
    deck.push_back(card);

    string s_ans = sutehuda(deck,"S");
    string h_ans = sutehuda(deck,"H");
    string d_ans = sutehuda(deck,"D");
    string c_ans = sutehuda(deck,"C");
    string ans = s_ans;
    if (ans.size() > h_ans.size()){
        ans = h_ans;
    }
    if (ans.size() > d_ans.size()){
        ans = d_ans;
    }
    if (ans.size() > c_ans.size()){
        ans = c_ans;
    }
    if (ans == ""){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}