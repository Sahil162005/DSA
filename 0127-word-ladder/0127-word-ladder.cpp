class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>stt;
        for(int i=0;i<wordList.size();i++){
            stt.insert(wordList[i]);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string u=q.front().first;
            int lvl=q.front().second;
            if(u==endWord){
                return lvl;
            }
            q.pop();
           for (int i = 0; i < u.size(); ++i) {
                char original = u[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    u[i] = c;
                    if (stt.find(u) != stt.end()) {
                        q.push({u, lvl + 1});
                        stt.erase(u);
                    }
                }
                u[i] = original;
            }
        }
        return 0;
    }
};