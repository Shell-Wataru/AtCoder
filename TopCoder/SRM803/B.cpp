#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
using ll = long long;

class MarriageAndSelectionChallenge
{
public:
    string solve(string S)
    {
        ll N = S.size();
        vector<vector<vector<pair<ll,ll>>>> DP(N+1,vector<vector<pair<ll,ll>>>(1<<12,vector<pair<ll,ll>>(12,{0,-1})));
        for(int i = 0;i < N;i++){
            ll char_index = S[i] - 'a';
            DP[i+1] = DP[i];
            DP[i+1][1<<char_index][char_index] = max(DP[i+1][1<<char_index][char_index],1ll);
            for(int j = 1;j < (1<<12);j++){
                if (j & 1<<char_index){
                    DP[i+1][j][char_index] = max(DP[i+1][j][char_index],DP[i][j][char_index]+1);
                }else{
                    for(int k = 0;k < 12;k++){
                        if (j & 1<<k){
                            DP[i+1][j|1<<char_index][char_index] = max(DP[i+1][j|1<<char_index][char_index],DP[i][j][k]+1ll);
                        }
                    }
                }
            }
        }
        ll max_length = 0;
        for(int j = 1;j < (1<<12);j++){
            for(int k = 0;k < 12;k++){
                max_length = max(max_length,DP[N][j][k]);
            }
        }
        cout << max_length << endl;
        return "";
    }
};

int main(){
    MarriageAndSelectionChallenge m;
    cout << m.solve("kick") << endl;
    cout << m.solve("cccaaccc") << endl;
    cout << m.solve("ccaaccc") << endl;

    return 0;
}