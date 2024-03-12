#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef int ll;
typedef double db;


const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//∂‡◊È ‰»Î

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        sort(nums.begin(),nums.end());
        back_track(nums,0,track,res);
        return res;
    }

    void back_track(vector<int>& nums,int start,vector<int> &track,vector<vector<int>> &res){  
        res.push_back(track);     
        int siz=nums.size();
        for(int i=start;i<siz;++i){
            track.push_back(nums[i]);
            back_track(nums,i+1,track,res);
            track.pop_back();
        }
    }
};


void Solve() {
    ll n; cin >> n;
    vector<ll> a(n), v;
    vector<vector<ll>> res;
    for(ll i = 0; i < n; i ++ ) cin >> a[i];
    Solution s;
    res = s.subsetsWithDup(a);
    for(auto i : res) {
        ll x = 0;
        if(i.size() == 0) continue ;
        for(auto j : i) {x ^= j;}
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(auto i : v) cout << i << " ";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}