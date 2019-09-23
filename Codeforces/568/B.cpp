#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long N;
    cin >> N;
    for(int i = 0;i< N;i++){
        string s1,s2;
        cin >> s1 >> s2;
        ll s1_index = 0;
        ll s2_index = 0;
        bool is_clear = true;
        while(s1_index < s1.size() && s2_index < s2.size()){
            if (s1[s1_index] == s2[s2_index]){
                ll s1_next = s1_index + 1;
                while(s1_next < s1.size() && s1[s1_index] == s1[s1_next]){
                    s1_next++;
                }
                ll s2_next = s2_index + 1;
                while(s2_next < s2.size() && s2[s2_index] == s2[s2_next]){
                    s2_next++;
                }

                if (s1_next - s1_index > s2_next - s2_index){
                    is_clear = false;
                    break;
                }else{
                    s1_index = s1_next;
                    s2_index = s2_next;
                }
            }else{
                is_clear = false;
                break;
            }
        }

        if(s1_index !=  s1.size() || s2_index !=  s2.size()){
            is_clear = false;
        }
        if(is_clear){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}