// 212. Word Search II

class TrieNode {
public:

    TrieNode* children[26];
    bool isLeaf;
    string word;

    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word="";
    }

void insert(TrieNode* root, const string& key) {
    
    TrieNode* curr = root;

    for (char c : key) {

        if (curr->children[c - 'a'] == nullptr) {
            TrieNode* newNode = new TrieNode();

            curr->children[c - 'a'] = newNode;
        }

        curr = curr->children[c - 'a'];
    }
    curr->isLeaf = true;
    curr->word=key;
}
};



class Solution {
public:

int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};


void dfs(TrieNode* root,int r,int c,vector<vector<char>>& board,vector<string>& ans){
    if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || 
        board[r][c] == '$' || root->children[board[r][c] - 'a'] == nullptr){
            //root->children[board[r][c] - 'a'] == nullptr           ye condition sbse last me likhni hai if me
        return;
    }

    root=root->children[board[r][c]-'a'];
    if(root->isLeaf){
        ans.push_back(root->word);
        root->isLeaf=false;
    }

    char temp=board[r][c];
    board[r][c]='$';

    for(int i=0;i<4;i++){
        int newr=r+x[i];
        int newc=c+y[i];

        dfs(root,newr,newc,board,ans);

    }
    

    board[r][c]=temp;
}


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
        for(auto i:words){
            root->insert(root,i);
        }

        int n=board.size();
        int m=board[0].size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(root->children[board[i][j]-'a']!=nullptr){
                    dfs(root,i,j,board,ans);
                }
            }
        }

        return ans;
    }



};