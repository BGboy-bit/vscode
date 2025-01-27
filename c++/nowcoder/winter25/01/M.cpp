#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
    int n;
    vector<vector<long long>> stMin, stMax;
    vector<int> log2v;
    
    SparseTable(const vector<long long> &arr) {
        n = (int)arr.size();
        log2v.resize(n+1,0);
        for(int i=2; i<=n; i++){
            log2v[i] = log2v[i/2]+1;
        }
        int K = log2v[n];
        stMin.assign(n, vector<long long>(K+1));
        stMax.assign(n, vector<long long>(K+1));
        
        for(int i=0;i<n;i++){
            stMin[i][0] = arr[i];
            stMax[i][0] = arr[i];
        }
        for(int k=1; k<=K; k++){
            int len = (1<<k);
            for(int i=0; i+len-1 < n; i++){
                stMin[i][k] = min(stMin[i][k-1], 
                                  stMin[i + (1<<(k-1))][k-1]);
                stMax[i][k] = max(stMax[i][k-1], 
                                  stMax[i + (1<<(k-1))][k-1]);
            }
        }
    }
    
    pair<long long,long long> query(int L,int R){
        int k = log2v[R-L+1];
        long long mn = min(stMin[L][k], stMin[R-(1<<k)+1][k]);
        long long mx = max(stMax[L][k], stMax[R-(1<<k)+1][k]);
        return make_pair(mn,mx);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    if(n==1){
        cout << 0 << "\n";
        return 0;
    }

    long long globalMin = LLONG_MAX, globalMax = LLONG_MIN;
    for(int i=0;i<n;i++){
        globalMin = min(globalMin, A[i]);
        globalMax = max(globalMax, A[i]);
    }

    vector<long long> prefixMin(n), prefixMax(n), suffixMin(n), suffixMax(n);
    {
        long long curMin=LLONG_MAX, curMax=LLONG_MIN;
        for(int i=0;i<n;i++){
            curMin = min(curMin,A[i]);
            curMax = max(curMax,A[i]);
            prefixMin[i] = curMin;
            prefixMax[i] = curMax;
        }
    }
    {
        long long curMin=LLONG_MAX, curMax=LLONG_MIN;
        for(int i=n-1;i>=0;i--){
            curMin = min(curMin, A[i]);
            curMax = max(curMax, A[i]);
            suffixMin[i] = curMin;
            suffixMax[i] = curMax;
        }
    }
    SparseTable st(A); 

    long long ans = 2LL*(globalMax - globalMin);

    vector<pair<long long,int>> sortedVal(n);
    for(int i=0;i<n;i++){
        sortedVal[i] = {A[i], i};
    }
    sort(sortedVal.begin(), sortedVal.end()); // 按value升序

    int minIndex = INT_MAX, maxIndex = INT_MIN;

    for(int k=0; k<n; k++){
        auto [val, idx] = sortedVal[k];
        minIndex = std::min(minIndex, idx);
        maxIndex = std::max(maxIndex, idx);
        int L = minIndex;
        int R = maxIndex;
        if(L==0 && R==n-1) {
            continue;
        }

        auto [insideMin, insideMax] = st.query(L,R);

        long long outMin = LLONG_MAX;
        long long outMax = LLONG_MIN;
        if(L>0){
            outMin = min(outMin, prefixMin[L-1]);
            outMax = max(outMax, prefixMax[L-1]);
        }
        if(R<n-1){
            outMin = min(outMin, suffixMin[R+1]);
            outMax = max(outMax, suffixMax[R+1]);
        }

        long long newMin = min(outMin, 2LL*insideMin);
        long long newMax = max(outMax, 2LL*insideMax);
        long long newRange = newMax - newMin;
        ans = min(ans, newRange);
    }

    cout << ans << "\n";
    return 0;
}
