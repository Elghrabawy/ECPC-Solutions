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
 
signed main(){
    IO();

    vector<int> v(7);
    for(auto &el : v) cin >> el;

    int idx = min_element(all(v)) - v.begin() + 1;
    switch (idx){
        case 1: cout << "the first"; break;
        case 2: cout << "the second"; break;
        case 3: cout << "the third"; break;
        case 4: cout << "the fourth"; break;
        case 5: cout << "the fifth"; break;
        case 6: cout << "the sixth"; break;
        case 7: cout << "the seventh"; break;
    }
}
