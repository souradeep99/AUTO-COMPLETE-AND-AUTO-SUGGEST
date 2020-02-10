void Delete (string s){
    if(Find(s) == 0){
        cout << "No such word exist.\n";
        return ;
    }
    vector<int> track;
    vector<char> word;
    int idx = 0;

    for (int i = 0; i < s.size(); i++){
        idx = trie[idx][s[i] - 'a'];
        track.push_back(idx);
        word.push_back(s[i]);
    }

    finish[idx] = 0;

    while(track.size()){
        idx = track.back();

        if(finish[idx])
            return ;
        for(int i = 0; i < 26; i++){
            if(trie[idx][i] != 0){
                return ;
            }
        }

        char c = word.back();
        word.pop_back();
        track.pop_back();
        if(track.size()){
            trie[track.back()][c - 'a'] = 0;
        }else{
            if(!finish[0])
                trie[0][c - 'a'] = 0;
        }
        
    }
    
}
