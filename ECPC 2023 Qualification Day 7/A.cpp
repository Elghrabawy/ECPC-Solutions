#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
 
int lcm(int a, int b){ return a / gcd(a, b) * b; }
 
vector<int> primeFac(int n){
    vector<int> v;
    while(n % 2 == 0){
        n /= 2;
        v.push_back(2);
    }
    for(int i = 3; i * i <= n; i+= 2){
        while(!(n % i)) {
            v.push_back(i);
            n /= i;
        }
    }
    if(n != 1) v.push_back(n);
    return v;
}
 
int power(int a, int b){
    if(b == 0) return 1;
    int res = power(a * a, b / 2);
    if(b % 2) res *= a;
    return res;
}

signed main(){
    IO();

    int t = 1; cin >> t;
    while(t--){
        int a, c, b = -1; cin >> a >> c;
        vector<int> pfa = primeFac(a), pfc = primeFac(c);
    
        map<int, int> freqa, freqc, freqb;
    
        for(auto &prime : pfa){
            freqa[prime]++;
        }
        for(auto &prime : pfc){
            freqc[prime]++;
        }
        
        for(auto &[prime, freq] : freqc){
            if(freqa[prime] < freq){
                freqb[prime] = freq;
            }
        }
    
        if(c % a == 0){
            b = 1;
            for(auto &[prime, freq] : freqb) b *= power(prime, freq);
        }
        cout << b << endl;
    }
}
