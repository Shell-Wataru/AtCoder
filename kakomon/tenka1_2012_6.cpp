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


vector<string> splitAsCamelCase(string &S){
    vector<string> ans;
    string current = "";
    for(auto c:S){
        if (0 <= c - 'A' && c - 'A' < 26){
            ans.push_back(current);
            current = "";
            current += c;
        }else{
            current += c;
        }
    }
    ans.push_back(current);
    return ans;
}

vector<string> split_as_snake_case(string &S){
    vector<string> ans;
    string current = "";
    for(auto c:S){
        if (c == '_'){
            ans.push_back(current);
            current = "";
        }else{
            current += c;
        }
    }
    ans.push_back(current);
    return ans;
}

int main()
{
    string S;
    cin >> S;
    ll prefix_count = 0;
    ll suffix_count = 0;
    while(S.back() == '_'){
        suffix_count++;
        S.pop_back();
    }
    reverse(S.begin(),S.end());
    while(S.back() == '_'){
        prefix_count++;
        S.pop_back();
    }
    reverse(S.begin(),S.end());

    vector<string> camelCaseWords = splitAsCamelCase(S);
    vector<string> snake_case_words = split_as_snake_case(S);
    bool isCamel = true;
    bool is_snake = true;
    for(int i = 0; i < camelCaseWords.size();i++){
        if (camelCaseWords[i].size() == 0){
            isCamel = false;
            break;
        }else if (camelCaseWords[i].find('_') != string::npos){
            isCamel = false;
            break;
        }else if (i == 0){
            if (!( 0 <= camelCaseWords[i][0] - 'a' &&  camelCaseWords[i][0] - 'a' < 26)){
                isCamel = false;
                break;
            }
        }else{
            if (!( 0 <= camelCaseWords[i][0] - 'A' &&  camelCaseWords[i][0] - 'A' < 26)){
                isCamel = false;
                break;
            }
        }
    }

    for(int i = 0; i < snake_case_words.size();i++){
        if (snake_case_words[i].size() == 0){
            is_snake = false;
            break;
        }else{
            if (!( 0 <= snake_case_words[i][0] - 'a' &&  snake_case_words[i][0] - 'a' < 26)){
                is_snake = false;
                break;
            }
        }
        for(auto c:snake_case_words[i]){
            if (0 <= c - 'A' && c - 'A' < 26){
                is_snake = false;
                break;
            }
        }
    }
    // cout << S << endl;
    // cout << isCamel << endl;
    // cout << is_snake << endl;
    for(int i = 0;i < prefix_count;i++){
        cout << "_";
    }
    if (isCamel && is_snake){
        cout << S;
    }else if (!isCamel && !is_snake){
        cout << S;
    }else if (isCamel){
        for(auto c:S){
            if (0 <= c - 'A' && c - 'A' < 26){
                cout << "_";
                cout << (char)(c + 32);
            }else{
                cout << c;
            }
        }

    }else{
        bool makeCamel = false;
        for(auto c:S){
            if (c == '_'){
                makeCamel = true;
            }else if (makeCamel){
                cout << (char)(c -32);
                makeCamel = false;
            }else{
                cout << c;
            }
        }
    }
    for(int i = 0;i < suffix_count;i++){
        cout << "_";
    }
    cout << endl;
   return 0;
}