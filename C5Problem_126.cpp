#include <iostream>

using namespace std;

class Solution {
public:

    void backtracing(const string& src, const string& dst, unordered_map<string, vector<string>>& next_words, vector<string>& path, vector<vector<string>>& ladder){
        if(src == dst){
            ladder.push_back(path);
            return;
        }
        if(!next_words.contains(src)){
            return;
        }
        for(const auto& w: next_words[src]){
            path.push_back(w);
            backtracing(w, dst, next_words, path, ladder);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ladder;

        unordered_map<string> word_dict;

        for(const auto&w : wordList){
            word_dict.insert(w);
        }

        if(!word_dict.contains(endWord)){
            return ladder;
        }

        word_dict.erase(beginWord);
        word_dict.erase(endWord);

        unordered_set<string> q_small{beginWord}, q_large{endWord};
        unordered_map<string, vector<string>> next_words;

        bool reversed_path = false, found_path = false;

        while(!q_small.empty()){
            
        }
    }
};