class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool present = false;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord){
                present = true;
                break;
            }
        }
        if(present){
            set<string> st(wordList.begin(), wordList.end());
            queue<pair<string,int>>q;
            q.push({beginWord,1});

            while(!q.empty()){
                string curr= q.front().first;
                int lvl = q.front().second;
                q.pop();
                if(curr == endWord){
                    return lvl;
                }
                for(int i=0;i<curr.size();i++){
                    char letter = curr[i];
                    for(int j=0;j<26;j++){
                        curr[i]='a'+j;
                       if (st.find(curr) != st.end()){
                            st.erase(curr);
                            q.push({curr,lvl+1});
                        }
                    }
                    curr[i]=letter;
                }
            }
            return 0;
        }
        return 0;
    }
};