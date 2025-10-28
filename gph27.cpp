// Word Ladder I  (GFG) (BFS)


    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({startWord,1});
        
        set<string>st(wordList.begin(),wordList.end());
        st.erase(startWord);
        
        while(!q.empty()){
            string word=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(word==targetWord)return cnt;
            for(int i=0;i<word.length();i++){
                string curr=word;
                for(char j='a';j<='z';j++){
                    curr[i]=j;
                    if(st.find(curr)!=st.end()){
                        st.erase(curr);
                        q.push({curr,cnt+1});
                    }
                }
            }
        }
        return 0;
    }