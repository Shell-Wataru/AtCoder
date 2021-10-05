#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

bool is_bigger(string &a,string &b){
    if (a.size() > b.size()){
        return true;
    }else if (a.size() < b.size()){
        return false;
    }else{
        for(int i = 0;i < a.size();i++){
            if (a[i] - b[i] > 0){
                return true;
            }else if (a[i] - b[i] < 0){
                return false;
            }
        }
        return false;
    }
}
string solve(){
    ll N;
    cin >> N;
    vector<string> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    ll ans = 0;
    for(int i = 1;i < N;i++){
        if (is_bigger(A[i],A[i-1])){
            continue;
        }else{
            string a = A[i-1];
            string b = A[i];
            bool bigger = false;
            bool smaller = false;
            bool same = true;
            for(int i = 0;i < b.size();i++){
                if (a[i] - b[i] > 0){
                    smaller = true;
                    same = false;
                    break;
                }else if (a[i] - b[i] < 0){
                    bigger = true;
                    same = false;
                    break;
                }
            }
            if (smaller){
                for(int i = b.size();i <= a.size();i++){
                    b += '0';
                    ans++;
                }
            }else if (bigger){
                for(int i = b.size();i < a.size();i++){
                    b += '0';
                    ans++;
                }
            }else{
                int last_not_nine = -1;
                for(int i = b.size();i < a.size();i++){
                    if (a[i] != '9'){
                        last_not_nine = i;
                    }
                }
                if (last_not_nine == -1){
                    for(int i = b.size();i <= a.size();i++){
                        b += '0';
                        ans++;
                    }
                }else{
                    for(int i = b.size();i < a.size();i++){
                        if (i < last_not_nine){
                            b += a[i];
                        }else if(i == last_not_nine){
                            b += a[i] + 1;
                        }else{
                            b += '0';
                        }
                        ans++;
                    }
                }
            }
            A[i] = b;
            // cout << A[i] << endl;
        }
    }
    return to_string((ans));
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}