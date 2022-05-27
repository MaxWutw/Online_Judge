// UVa 429
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    IOS
    freopen("sample1.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        vector<string> word;
        string str;
        while(cin >> str){
            if(str == "*") break;
            else word.emplace_back(str);
        }
        string s, e;
        map<string, int> m;
        string line;
        cin.ignore();
        while(getline(cin, line) && line != ""){
            stringstream ss(line);
            ss >> s >> e;
            queue<string> q;
            q.push(s);
            m[s] = 0;
            while(!q.empty() && m.count(e) == 0){
                string w = q.front();
                q.pop();
                for(int i = 0;i < (int)word.size();i++){
                    string com = word[i];
                    if(!m.count(com) && com.size() == w.size()){
                        int dif = 0;
                        for(int i = 0;i < (int)com.size();i++){
                            if(com[i] != w[i]) dif++;
                            if(dif >= 2) break;
                        }
                        if(dif == 1){
                            q.push(com);
                            m[com] = m[w] + 1;
                        }
                    }
                }
            }
            cout << s << ' ' << e << ' ' << m[e];
            if(t >= 0) cout << '\n';
        }
    }

    return 0;
}