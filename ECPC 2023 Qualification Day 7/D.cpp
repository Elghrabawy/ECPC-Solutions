#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

int main(){
    IO();
    
    int n; cin >> n;
    if(n == 63) cout << "=";
    else if( n < 63) cout << "<";
    else cout << ">";
}