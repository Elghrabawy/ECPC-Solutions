#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

const int N = 3e5 + 5, INF = 1e15;
int n, msd_a, msd_b, ans_a, ans_b;
vector<int> a, b;
int dp[N][2][2];

int solve(int i, bool shift_a, bool shift_b){
    if(i == n) return (shift_a && shift_b) ? 0 : -INF;
 
    int &ret = dp[i][shift_a][shift_b];
    if(~ret) return ret;
 
    ret = -INF;
    if(!shift_a && (i - shift_b < n - 1))
        ret = max(ret, solve(i + 1, true, shift_b) + abs(msd_a - b[i - shift_b]));
    if(!shift_b && (i - shift_a < n - 1))
        ret = max(ret, solve(i + 1, shift_a, true) + abs(a[i - shift_a] - msd_b));
    if(!shift_a && !shift_b)
        ret = max(ret, solve(i + 1, true, true) + abs(msd_a - msd_b));
    if((i - shift_a < n - 1) && (i - shift_b < n - 1))
        ret = max(ret, solve(i + 1, shift_a, shift_b) + abs(a[i - shift_a] - b[i - shift_b]));
    return ret;
}

void build(int i, bool shift_a, bool shift_b){
    if(i == n) return;
 
    int ret = solve(i, shift_a, shift_b);
    if(!shift_a && (i - shift_b < n - 1) && ret == solve(i + 1, true, shift_b) + abs(msd_a - b[i - shift_b]))
        ans_a = i, build(i + 1, true, shift_b);
    else if(!shift_b && (i - shift_a < n - 1) && ret == solve(i + 1, shift_a, true) + abs(a[i - shift_a] - msd_b))
        ans_b = i, build(i + 1, shift_a, true);
    else if(!shift_a && !shift_b && ret == solve(i + 1, true, true) + abs(msd_a - msd_b))
        ans_a = i, ans_b = i, build(i + 1, true, true);
    else if((i - shift_a < n - 1) && (i - shift_b < n - 1))
        build(i + 1, shift_a, shift_b);
}

signed main(){
    IO();

    cin >> n;
    a.resize(n - 1), b.resize(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++) cin >> b[i];
 
    int sum_a = 0, sum_b = 0;
    for(auto &x : a) sum_a += x;
    for(auto &x : b) sum_b += x;
 
 
    msd_a = (n * (n + 1)) / 2 - sum_a;
    msd_b = (n * (n + 1)) / 2 - sum_b;
 
 
 
    memset(dp, -1, sizeof dp);
    cout << solve(0, false, false) << endl;
    build(0, false, false);
    a.insert(a.begin() + ans_a, msd_a);
    b.insert(b.begin() + ans_b, msd_b);
    
    for(int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
    for(int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
}
