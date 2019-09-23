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

class MilkConsumption {
	public:
	vector <int>  findMaxRegion (vector<int> a,vector<int> b) {
        vector<int> ans;
        double max_drank = 0;
        int max_index = -1;

        for(int i = 0;i < a.size();i++){
            if (max_drank < b[i]*1.0/a[i]){
                max_index = i;
                max_drank = b[i]*1.0/a[i];
            }
        }

        ans.push_back(max_index);
        return ans;
	}
};

// int main(){
//     MilkConsumption m;
//     vector<int> a{10,10,10,10};
//     vector<int> b{47,0,0,0};
//     vector<int> ans = m.findMaxRegion(a,b);
//     for(auto item: ans){
//         cout << item << endl;
//     }
//     return 0;
// }
