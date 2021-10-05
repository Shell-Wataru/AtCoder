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

class DisjointDiceValues {
	public:
	double getProbability (int A,int B) {
        vector<vector<double>> a_probabilities(2,vector<double>(7,0));
        a_probabilities[0][0] = 1;
        for(int i = 0;i < A;i++){
            ll cur_i = i % 2;
            ll next_i = (i + 1) % 2;
            for(int j = 0;j < 7;j++){
                if (j == 0){
                    a_probabilities[next_i][j] = 0;
                }else{
                    a_probabilities[next_i][j] = 1.0 * j/6 * a_probabilities[cur_i][j] + 1.0 * (6-(j-1))/6 * a_probabilities[cur_i][j-1];
                }
            }
        }
        double ans = 0;
        ll ans_index = A % 2;
        for(int j = 0;j < 7;j++){
            // cout << a_probabilities[ans_index][j] << endl;
            // cout << pow(1.0* (6 - j)/6, B) << endl;
            // cout << a_probabilities[ans_index][j] * pow(1.0* (6 - j)/6, B) << endl;
            ans += a_probabilities[ans_index][j] * pow(1.0* (6 - j)/6, B);
        }
        return 1.0 - ans;
	}
};

// int main(){
//     DisjointDiceValues m;
//     cout << m.getProbability(1,1) << endl;
//     return 0;
// }