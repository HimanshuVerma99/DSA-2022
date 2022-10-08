class Solution {
public:
    unordered_map<string,int>m;
    vector<string >ans;
    void WB(int i,string &s,string k){
        if(i==s.size()) {
            k.pop_back();
            ans.push_back(k);
        }
        string t;
        for(int j=i;j<s.size();j++){
            t+= s[j];
            k+= s[j];
            if(m.find(t)!=m.end()){
                k.push_back(' ');
                WB(j+1,s,k);
                k.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(int i=0;i<wordDict.size();i++){
            m[wordDict[i]]++;
        }
        string k;
        WB(0,s,k);
        return ans;
    }
};
