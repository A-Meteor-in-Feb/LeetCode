#include <iostream>
#include <unordered_set>
#include <unordered_map>

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

        unordered_set<string> word_dict;

        for(const auto &w : wordList){
            word_dict.insert(w);
        }

        if(!word_dict.contains(endWord)){
            return ladder;
        }

        word_dict.erase(beginWord);
        word_dict.erase(endWord);

        unordered_set<string> q_small{beginWord};
        unordered_set<string> q_large{endWord};
        unordered_map<string, vector<string>> next_words;

        bool reversed_path = false, found_path = false;

        while(!q_small.empty()){
            unordered_set<string> q;
            for(const auto &w: q_small){
                string s = w;
                for(int i = 0; i < s.size(); ++i){
                    for(int j = 0; j < 26; ++j){
                        s[i] = j + 'a';
                        if(q_large.contains(s)){
                            reversed_path ? next_words[s].push_back(w) : next_words[w].push_back(s);
                            found_path = true;
                        }
                        if(word_dict.contains(s)){
                            reversed_path ? next_words[s].push_back(w) : next_words[w].push_back(s);
                            q.insert(s);
                        }
                    }
                    s[i] = w[i];
                }
            }
            if(found_path){
                break;
            }
            for(const auto &w : q){
                word_dict.erase(w);
            }
            if(q.size() <= q_large.size()){
                q_small = q;
            }else{
                reversed_path = !reversed_path;
                q_small = q_large;
                q_large = q;
            }
        }
        if(found_path){
            vector<string> path{beginWord};
            backtracing(beginWord, endWord, next_words, path, ladder);
        }
        return ladder;
    }
};