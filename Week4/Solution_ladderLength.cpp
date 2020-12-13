/*
*  127. 单词接龙
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end()) return 0;
        //初始化起始点和终点
        unordered_set<string> frontSet,backSet,tmp,visited;
        frontSet.insert(beginWord);
        backSet.insert(endWord);
        int step=1;
        while(!frontSet.empty() && !backSet.empty()) {
            if(backSet.size() < frontSet.size()) {
                tmp = frontSet;
                frontSet = backSet;
                backSet = tmp;
            }
            tmp.clear();
            for(auto word : frontSet) {
                for(int i=0;i<word.size();++i) {
                    char old = word[i];
                    //开始变换
                    for(char c='a' ;c<='z' ;++c ) {
                        if(old == c) continue;
                        word[i] = c;
                        if(backSet.find(word) != backSet.end()) return ++step;
                        if(visited.find(word) == visited.end() && dict.find(word) != dict.end()) {
                            tmp.insert(word);
                            visited.insert(word);
                        }
                    }
                    word[i]=old;
                }
            }
            frontSet = tmp;
            ++step;
        }
        return 0;
    }
};
