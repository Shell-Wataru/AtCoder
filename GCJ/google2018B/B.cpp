#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
using ll = long long;

class sign
{
    public:
        ll d, a, b;
};

pair<ll,ll> optimal(vector<sign> signs){
    ll longest_sign_set_length = 0LL;
    ll num_of_longest_sign_sets = 0LL;
    ll N,M;
    vector<pair<ll,ll>> n_sets;
    vector<pair<ll,ll>> m_sets;
    M = signs[0].d + signs[0].a;
    N = signs[0].d - signs[0].b;

    for(ll i = 0;i < signs.size();i++){
        if (N != signs[i].d - signs[i].b){
            N = signs[i].d - signs[i].b;
            n_sets.push_back(current_sign_set_start_at,i-1)
            current_sign_set_start_at = i;
        }
    }
    n_sets.push_back(make_pair(current_sign_set_start_at,signs.size()-1));

    current_sign_set_start_at = 0LL;
    for(ll i = 0;i < signs.size();i++){
        if (M != signs[i].d + signs[i].a){
            M = signs[i].d + signs[i].a;
            m_sets.push_back(current_sign_set_start_at,i-1)
            current_sign_set_start_at = i;
        }
    }
    m_sets.push_back(make_pair(current_sign_set_start_at,signs.size()-1));
    int j = 0;
    int i = 0;
    while(i < m_sets.size() && j < n_sets.size()){
        pair<ll,ll> m = m_sets[i];
        pair<ll,ll> n = n_sets[i];
        ll size = max(m.second,n.second) - min(m.first,n.first) + 1;
        if(size >  longest_sign_set_length){
            num_of
        }
    }

    return make_pair(total,longest_sign_set_length);
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll S;
        cin >> S;
        vector<sign> signs;
        for (int j = 0; j < S; j++)
        {
            sign s;
            cin >> s.d >> s.a >> s.b;
            signs.push_back(s);
        };

        pair<ll,ll> result = optimal(signs);
        cout << "Case #" << i << ": " << result.first << " " << result.second << endl;
    }

    return 0;
}