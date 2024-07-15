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
    
    string s, ans, tmp; cin >> s;
    bool home = true;

    for(int i = 0; i < s.size(); i++){
        if(s[i] != '<' && s[i] != '>'){
            tmp.push_back(s[i]);
        }
        else{
            if(!home) ans.insert(ans.size(), tmp);
            else ans.insert(0, tmp);
            tmp.clear();

            if(s[i] == '<') home = true;
            else home = false;
        }
    }
    if(!home) ans.insert(ans.size(), tmp);
    else ans.insert(0, tmp);

    cout << ans << endl;
}
