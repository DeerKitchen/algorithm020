class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen = s.size(),tLen = t.size();
        if(sLen != tLen) return false;
        if(!sLen) return true;
        int temp[26] = {0};
        for(int i=0;i<sLen;++i) {
            ++temp[s[i]-'a'];
            --temp[t[i]-'a'];
        }
        for(auto &t:temp) if(t) return false;
        return true;
    }
};
