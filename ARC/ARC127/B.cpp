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

using namespace std;
using ll = long long;

vector<vector<string>> append(vector<vector<string>> &heads){
    if (heads.empty()){
        return {{"2","1","0"}};
    }
    vector<vector<string>> ans;
    for(auto &head:heads){
        vector<string> sub_ans1;
        vector<string> sub_ans2;
        vector<string> sub_ans3;
        for(int i = 0;i < 3;i++){
            sub_ans1.push_back(head[i] + (char)('0' + (i % 3)));
            sub_ans2.push_back(head[i] + (char)('0' + ((i+1) % 3)));
            sub_ans3.push_back(head[i] + (char)('0' + ((i+2) % 3)));
        }
        ans.push_back(sub_ans3);
        ans.push_back(sub_ans2);
        ans.push_back(sub_ans1);
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll N,L;
    cin >> N >> L;
    vector<vector<string>> heads;
    ll tail_length = 0;
    while(3*heads.size()< 3*N){
        heads = append(heads);
        tail_length++;
    }
    sort(heads.begin(),heads.end());
    // for(auto head:heads){
    //     for(auto h:head){
    //         cout << h << endl;
    //     }
    // }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < 3;j++){
            cout << heads[i][j][0];
            for(int k = 0;k < L - tail_length;k++){
                cout << (heads[i][j][0] - '0' + 1) % 3;
            }
            for(int k = 1;k < tail_length;k++){
                cout << heads[i][j][k];
            }
            cout << "\n";
        }
    }
    cout << flush;
    return 0;
}