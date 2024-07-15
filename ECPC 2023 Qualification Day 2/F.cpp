#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("fileIO/input.txt", "r", stdin);
        freopen("fileIO/output.txt", "w", stdout);
    #endif
}

int main() {
    IO();

    int t = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(auto &el : v) cin >> el;

        bool val = false;

        int a{}, b{};

        for(auto &el : v){
            if(el == 0){
                val ? b++ : a++;
                val ^= 1;
            }
            else if(el == 1) a++;
            else b++;
        }

        if(a == b){
            cout << "Go deploying" << endl;
        }
        else if(a > b){
            cout << "Chess" << endl;
        }
        else {
            cout << "Lol" << endl;
        }
    }
}