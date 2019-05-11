#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <iomanip>

using namespace std;
using ll = long long;
int main()
{
    // 整数の入力
    string W,aiueo;
    aiueo = "aiueo";
    cin >> W;
    for (int i =0;i<W.size();i++){
        if (aiueo.find(W[i]) == string::npos ){
            cout << W[i];
        }
    }
    cout <<  endl;
    return 0;
}