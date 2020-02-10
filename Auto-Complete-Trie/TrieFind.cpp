int Find (string s) {
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
        if (trie[idx][s[i] - 'a'] == 0)
            return 0;
        else
            idx = trie[idx][s[i] - 'a'];
    return finish[idx];
}
