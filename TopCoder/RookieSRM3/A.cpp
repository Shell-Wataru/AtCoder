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

class JudgedScoring {
	public:
	int  overallScore (vector<int> a) {
        ll ans = 0;
        sort(a.begin(),a.end());
        for(int i = 1;i < a.size() - 1;i++){
            ans+= a[i];
        }
        return ans;
	}
};

// int main(){
//     JudgedScoring m;
//     vector<int> a{5,3,2,4};
//     ll ans = m.overallScore(a);
//     cout << ans << endl;
//     return 0;
// }
