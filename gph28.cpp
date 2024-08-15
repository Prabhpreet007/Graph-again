// Word Ladder II  (GFG)


vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        vector<string>usedWords;
        
        set<string>st(wordList.begin(),wordList.end());

        
        queue<vector<string>>q;
        int level=0;
        q.push({beginWord});
        
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            
            if(front.size()>level){
                level++;
                for(auto i:usedWords){
                    st.erase(i);
                }
                usedWords.clear();
            }
            
            string word=front.back();
            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(front);
                }
                else if(ans[0].size()==front.size()){
                    ans.push_back(front);
                }
            }
            
            for(int i=0;i<word.length();i++){
                string temp=word;
                for(char j='a';j<='z';j++){
                    temp[i]=j;
                    if(st.find(temp)!=st.end()){
                        usedWords.push_back(temp);
                        front.push_back(temp);
                        q.push(front);
                        front.pop_back();
                    }
                }
            }
            
        }
        return ans;
    }