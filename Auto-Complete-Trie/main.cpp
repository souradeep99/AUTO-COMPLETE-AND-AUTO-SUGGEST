#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int trie[N][26], finish[N];
int nxt = 1;
void Add (string s){
    int node = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if(trie[node][s[i] - 'a'] == 0) {
            node = trie[node][s[i] - 'a'] = nxt;
            nxt++;
        } else {
            node = trie[node][s[i] - 'a'];
        }
    }
    finish[nxt - 1] = 1;
}


int Find (string s) {
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
        if (trie[idx][s[i] - 'a'] == 0)
            return 0;
        else
            idx = trie[idx][s[i] - 'a'];
    return finish[idx];
}

int GoLast(string s){
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
        if (trie[idx][s[i] - 'a'] == 0){
            cout << "No such str Exist, Please Enter a valid str.\n";
            return 0;
        }
        else
            idx = trie[idx][s[i] - 'a'];
    return idx;
}


void AutoComplete (int nxt, string s){
    if(nxt == 0)
        return ;

    if(finish[nxt]){
        cout << ">> ";
        cout << s << endl;
    }
    for(int i = 0; i < 26; i++){
        if(trie[nxt][i] != 0){
            char c = i + 'a';
            AutoComplete(trie[nxt][i], s + c);
        }
    }
}


int main() {
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
 

    freopen("output.txt", "w", stdout);

    ifstream deep("WordsList.txt");
    if(deep.fail()){
        cout << "File does not exist." << "\n";
        exit(0);
    }
    string s;
    while(deep >> s){
        Add(s);
    }
    deep.close();

    freopen("input.txt", "r", stdin);
    cout << "Enter a string for searching: ";
    string str;
    cin >> str;

    cout << str << endl;

    cout << "The search result is: \n";


    
    AutoComplete(GoLast(str), str);


    

return 0;  
}
 
 
 
