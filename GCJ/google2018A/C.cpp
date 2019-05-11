#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

struct cookie
{
    ll w, h;
};

struct range
{
    ll l;
    double r;
};

double optimal_p(ll N, ll P, vector<cookie> cookies)
{
    ll base = 0;
    double diff_min = 0;
    double diff_max = 0;
    vector<range> ranges;
    range initial_range = {0, 0};
    ranges.push_back(initial_range);
    for (auto c : cookies)
    {
        base += 2 * c.w + 2 * c.h;
        ll l = 2 * min(c.w, c.h);
        double r = 2 * hypot(c.w * 1.0, c.h * 1.0);

        vector<range> new_ranges;
        for (auto exists_range:ranges){
            range new_range = {exists_range.l + l,exists_range.r+ r};
            new_ranges.push_back(new_range);
        }
        for (auto new_range:new_ranges){
            auto it = upper_bound(ranges.begin(), ranges.end(), new_range,[](auto lrange, auto rrange) { return lrange.l < rrange.l;});
            ranges.insert(it,new_range);
        }

        // for (auto r: ranges){
        //     cout << r.l << "-" <<r.r << endl;
        // }

        // cout << "----" << endl;
        auto it = ranges.begin();
        while(it != ranges.end() && (it + 1) != ranges.end()){
            // cout << "p" << it - ranges.begin() << endl;
            range &current = *it;
            auto next_it = it+1;
            range next = *(it+1);

            // cout << "currnt.r" << current.r << endl;
            if(next.l < current.r){
                current.r = max(next.r,current.r);
                // cout << "currnt.r" << current.r << endl;
                ranges.erase(next_it);
            }else{
                it = it + 1;
            }
        }
    }

    range target = {P - base,0};
    // for (auto r: ranges){
    //     cout << r.l << "-" <<r.r << endl;
    // }
    auto it = lower_bound(ranges.begin(), ranges.end(), target,[](auto lrange, auto rrange) { return lrange.l <= rrange.l ;}) - 1;
    // cout << "targe" << P - base << endl;
    // cout << "range postion" << it - ranges.begin() << endl;
    if (P - base <= (*it).r ){
        return P;
    }else {
        return base*1.0 + (*it).r;
    }
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll N, P;
        vector<cookie> cookies;
        cin >> N >> P;
        for (int j = 0; j < N; j++)
        {
            cookie c;
            cin >> c.w >> c.h;
            cookies.push_back(c);
        };

        cout << "Case #" << i << ": " << fixed  << optimal_p(N, P, cookies) << endl;
    }

    return 0;
}