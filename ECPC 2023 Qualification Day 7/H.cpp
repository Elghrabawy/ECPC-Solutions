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

    int t = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> case000{
            79, 88, 97, 169, 178, 187, 196
        },
        case200{
            259, 268, 277, 286, 295, 349, 358, 367, 376, 385, 394
        },
        case400{
            439, 448, 457, 466, 475, 484, 493, 529, 538, 547, 556, 565, 574, 583, 592
        },
        case600{
            619, 628, 637, 646, 655, 664, 673, 682, 691, 709, 718, 727, 736, 745, 754, 763, 772, 781, 790
        },
        case800{
            808, 817, 826, 835, 844, 853, 862, 871, 907, 916, 925, 934, 943, 952, 961, 970
        };
    
        bool ans = false; 
    
        string num = to_string(n);
        int sum_f3 = 0, last_3 = n % 1000;
        for(int i = 0; i < 3; i++) sum_f3 += (num[i] - '0');
    
        if(last_3 >= 800){
            auto it = lower_bound(all(case800), last_3);
            if(it != case800.end()) ans = true;
        }
        else if(last_3 >= 600){
            auto it = lower_bound(all(case600), last_3);
            if(it != case600.end()) ans = true;
        }
        else if(last_3 >= 400){
            auto it = lower_bound(all(case400), last_3);
            if(it != case400.end()) ans = true;
        }
        else if(last_3 >= 200){
            auto it = lower_bound(all(case200), last_3);
            if(it != case200.end()) ans = true;
        }
        else{
            auto it = lower_bound(all(case000), last_3);
            if(it != case000.end()) ans = true;
        }
    
        cout << ((ans && sum_f3 == 16) ? "YES" : "NO") << endl;
    }
}
