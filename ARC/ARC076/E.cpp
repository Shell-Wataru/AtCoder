#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int main()
{
    // 整数の入力
    long long R,C,N,x1,x2,y1,y2,i;
    vector<vector<long long>> dots;
    deque<long long> stack;
    cin >> R >> C >> N;
    for (i =0;i < N ;i++){
        cin >> x1 >> y1 >>x2 >>y2;
        if ((x1 == 0 || x1 == R ||y1== 0 || y1==  C ) && (x2 == 0 || x2 == R || y2== 0 || y2==  C )){
            dots.push_back({x1,y1,i} );
            dots.push_back({x2,y2,i} );
        }
    }
        auto sortValue = [&R,&C](vector<long long> v) {
            if (v[0] == 0){
                return v[1];
            }else if(v[1] == C){
                return C + v[0];
            }else if (v[0] == R){
                return C + R + (C - v[1]);
            }else{
                return 2 * C + 2 * R - v[0];
            }
        };

    sort(dots.begin(),dots.end(),[&sortValue](vector<long long> v1,vector<long long> v2){
        return sortValue(v1) < sortValue(v2);
    });
    for (i = 0;i< dots.size();i++){
        stack.push_back(dots[i][2]);
        if (stack.size() >= 2 && stack[stack.size()-1] == stack[stack.size()-2]){
            stack.pop_back();
            stack.pop_back();
        }
    }
    if (stack.size() == 0){
        cout << "YES" <<endl;
    }else{
        cout << "NO" <<endl;
    }
    return 0;
}