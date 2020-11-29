/*主要解题思路
根据题意可知，字母异位词是指由相同的字母按照不同的顺序排列组合的单词，因此，异位词的长度也一定相等，所以我们就可以先将所有的单词按照字母的大小进行排序，然后比较单词对应位置上的字母是否相等。然后把排序后的结果作为key，将排序结果相同的异位词存入对应的value（value类型为vector）中，最后再将map中的值放入返回的vector<vector>中。
本文主要在求key的操作上做了多种罗列：
1、直接对单词按照字母大小排序,排序后的单词作为哈希表的key；
2、每个字母相乘、相加，最后两者相加作为哈希表的key；
3、给每个字母分配对应的质数，每个单词中的字母对应的质数进行相乘，最终的乘积作为哈希表的key。
具体解题思路一
先遍历strs，对每个string进行排序，异位词的排序结果是一样的，在map中的key值也就一样，然后在map中添加对应的vector，再将vector逐个添加到res中。
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 1) return {};
        vector<vector<string>> res;
        unordered_map<string,vector<string>> ret_map;
        for(auto &s : strs) {
            string temp = s;
            sort(temp.begin(),temp.end());
            ret_map[temp].emplace_back(move(s));
        }
        for(auto &m : ret_map) res.emplace_back(move(m.second));
        return res;
    }
};

//也可以一次遍历，异位词的排序结果作为key，并保存首次存入res的index，这样就可以直接将string放入res中。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 1) return {};
        vector<vector<string>> res;
        unordered_map<string,int> workStr;
        int index = 0;
        for(auto &str : strs) {
            string temp = str;
            sort(temp.begin(),temp.end());
            if(workStr.count(temp)) {
                res[workStr[temp]].emplace_back(move(str));
            }else {
                vector<string> vec(1,str);
                res.emplace_back(move(vec));
                workStr[temp] = index++;
            }
        }
        return res;
    }
};

//还可以自己定义一个单词排序函数：即题意中所有输入均为小写字母，所以可以只用一个数组，
//统计字符串中每个字符的个数，最终会生成一个新的字符串，如果生成新的字符串相同，说明他们是字母异位词。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 1) return {};
        vector<vector<string>> res;
        unordered_map<string,vector<string>> ret_map;
        for(string &s : strs) 
            ret_map[strSort(s)].emplace_back(move(s));
        for(auto &m : ret_map) res.emplace_back(move(m.second));
        return res;
    }
private:
    string strSort(string& str) {
        int counts[26] = {0};
        for(auto &s: str) ++counts[s-'a'];
        string temp;
        for(int i=0;i<26;++i) {
            temp += string(counts[i],i+'a');
        }
        return temp;
    }
};

//具体解题思路二
//将单词中每个字母相乘、相加，最后再相加，可以用来作为map的key值。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 1) return {};
        unordered_map<unsigned int,vector<string>> temp_map;
        unsigned int mul=1,add=0;
        for(string &s : strs) {
            mul=1,add=0;
            for(char &c:s) {	
                mul *= c;
                add += c;
            }
            temp_map[mul+add].emplace_back(move(s));
        }
        vector<vector<string>> res;
        res.reserve(temp_map.size());
        for(auto &str:temp_map) res.emplace_back(move(str.second));
        return res;
    }
};

//具体解题思路三
//对26个字母分别赋予对应的质数值，因为不同的质数和必定为不同的数字结果，所以可以用来作为map的key值。2
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 1) return {};
        double prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        unordered_map<double,vector<string>> ret_map;
        for(auto &s : strs) {
            double temp = 1;
            for(auto &c:s) temp *= prime[c - 'a'];
            ret_map[temp].emplace_back(move(s));
        }
        vector<vector<string>> res;
        res.reserve(ret_map.size());
        for(auto &m : ret_map) res.emplace_back(move(m.second));
        return res;
    }
};