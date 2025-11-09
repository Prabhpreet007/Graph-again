// 752. Open the Lock
// t.c & s.c = O(10⁴)


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        string start="0000";
        int steps=0;

        if(st.find(start)!=st.end())return -1;

        queue<string>q;
        q.push(start);

        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();q.pop();
                if(curr==target)return steps;

                for(int i=0;i<4;i++){
                    char currCh=curr[i];
                    char inc,dec;
                    if(currCh=='9'){
                        inc='0';
                        dec='8';
                    }
                    else if(currCh=='0'){
                        inc='1';
                        dec='9';
                    }
                    else{
                        inc=currCh+1;
                        dec=currCh-1;
                    }
                    curr[i]=inc;
                    string incStr=curr;
                    curr[i]=dec;
                    string decStr=curr;
                    
                    if(st.find(incStr)==st.end()){
                        q.push(incStr);
                        st.insert(incStr);
                    }

                    if(st.find(decStr)==st.end()){
                        q.push(decStr);
                        st.insert(decStr);
                    }
                    
                    curr[i]=currCh;
                }
            }
            steps++;
        }

        return -1;

    }
};