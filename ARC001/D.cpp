#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // 整数の入力
    long long N,start,goal,i,left_i,right_i;
    double d;
    d = 0;
    deque<pair<long long,long long>> left,right;
    cin >> N;
    cin >> start >> goal;

    left.push_back(make_pair(0,start));
    right.push_back(make_pair(0,start));
    for (i = 0;i<= N;i++){
        cin >> left_i >> right_i;
        if (0 < i){
            if (i == N){
                left_i = goal;
                right_i = goal;
            }
            while (left.size() > 1 && (left[left.size()-1].second - left[left.size()-2].second )*1.0/(left[left.size()-1].first - left[left.size()-2].first ) < (left_i -  left[left.size()-1].second)*1.0/(i - left[left.size()-1].first )){
                left.pop_back();
            }

            while (right.size() > 1 && (right[right.size()-1].second - right[right.size()-2].second )*1.0/(right[right.size()-1].first - right[right.size()-2].first ) > (right_i -  right[right.size()-1].second)*1.0/(i - right[right.size()-1].first )){
                right.pop_back();
            }

            if (left.size() == 1 && right.size() > 1){
                while(right.size() > 1 && left[0].second + (left_i - left[0].second) *1.0/(i - left[0].first)*(right[1].first - left[0].first) > right[1].second){
                    d += hypot(right[0].first - right[1].first,right[0].second - right[1].second);
                    right.pop_front();
                    left[0].first = right[0].first;
                    left[0].second = right[0].second;
                }
            }else if(right.size() == 1 && left.size() > 1){
                while(left.size() > 1 && right[0].second + (right_i - right[0].second) *1.0/(i - right[0].first)*(left[1].first - right[0].first) < left[1].second){
                    d += hypot(left[0].first - left[1].first,left[0].second - left[1].second);
                    left.pop_front();
                    right[0].first = left[0].first;
                    right[0].second = left[0].second;
                }
            }
            left.push_back(make_pair(i,left_i));
            right.push_back(make_pair(i,right_i));
        }
    }

    d += hypot(left.front().first - left.back().first, left.front().second - left.back().second);

    cout << fixed << setprecision(14) << d << endl;
    return 0;
}