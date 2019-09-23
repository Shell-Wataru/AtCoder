#include<iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
using ll = long long;
int main()
{
    // 整数の入力
    long long N,stable,headB,tailA,headtailAB;
    vector<long long> A;
    cin >> N;
    for (int i = 0;i< N;i++){
        ll a;
        cin >>a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    ll total = 0;
    ll plus_min = 0;
    ll minus_max = 0;
    vector<ll> plus;
    vector<ll> minus;
    vector<ll> zero;

    for(int i =0;i<N;i++){
        if(A[i] > 0){
            plus.push_back(A[i]);
        }else if (A[i] < 0){
            minus.push_back(A[i]);
        }else{
            zero.push_back(A[i]);
        }
    }

    vector<ll> plus_group;
    vector<ll> minus_group;
    if(zero.size()> 0){
        if(plus.size()>0){
            plus_group.push_back(plus[0]);
            for(int i = 0;i< minus.size();i++){
                plus_group.push_back(minus[i]);
            }
            minus_group.push_back(0);
            for(int i = 1;i<plus.size();i++){
                minus_group.push_back(plus[i]);
            }
            for(int i = 1;i<zero.size();i++){
                minus_group.push_back(0);
            }
        }else if(minus.size() >0){
            plus_group.push_back(0);
            for(int i = 1;i< minus.size();i++){
                plus_group.push_back(minus[i]);
            }
            minus_group.push_back(minus[0]);
            for(int i = 0;i<plus.size();i++){
                minus_group.push_back(plus[i]);
            }
            for(int i = 1;i<zero.size();i++){
                minus_group.push_back(0);
            }
        }else{
            for(int i = 0;i<zero.size();i++){
                if(i% 2==0){
                    plus_group.push_back(0);
                }else{
                    minus_group.push_back(0);
                };
            }
        }
    }else{
        if(plus.size() == 0){
            plus_group.push_back(minus[minus.size()-1]);
            minus_group.push_back(minus[0]);
            for(int i = 1;i< minus.size()-1;i++){
                plus_group.push_back(minus[i]);
            }
        }else if(minus.size() == 0){
            plus_group.push_back(plus[plus.size()-1]);
            minus_group.push_back(plus[0]);
            for(int i = 1;i< plus.size()-1;i++){
                minus_group.push_back(plus[i]);
            }
        }else{
            plus_group.push_back(plus[0]);
            minus_group.push_back(minus[0]);
            for(int i = 1;i< minus.size();i++){
                plus_group.push_back(minus[i]);
            }
            for(int i = 1;i< plus.size();i++){
                minus_group.push_back(plus[i]);
            }

        }
    }


    ll plus_total = plus_group[0];
    ll minus_total = minus_group[0];

    total = plus_total - minus_total;
    for(int i =1 ;i<plus_group.size();i++){
        total -= plus_group[i];
    }

    for(int i =1 ;i<minus_group.size();i++){
        total += minus_group[i];
    }
    cout << total << endl;

    for(int i =1 ;i<plus_group.size();i++){
        cout << plus_total << " " << plus_group[i] << endl;
        plus_total -= plus_group[i];
    }

    for(int i =1 ;i<minus_group.size();i++){
        cout << minus_total << " " << minus_group[i] << endl;
        minus_total -= minus_group[i];
    }

    cout << plus_total << " " << minus_total << endl;
     return 0;
}