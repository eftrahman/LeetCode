#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLength = words[0].length();
        int wordsCount = words.size();
        int substringLength = wordLength * wordsCount;

        unordered_map<string, int> wordsMap;
        for (const string& word : words) {
            wordsMap[word]++;
        }

        for (int i = 0; i <= s.length() - substringLength; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < wordsCount; j++) {
                int wordStartIndex = i + j * wordLength;
                string word = s.substr(wordStartIndex, wordLength);
                if (wordsMap.find(word) != wordsMap.end()) {
                    seen[word]++;
                    if (seen[word] > wordsMap[word]) {
                        break;
                    }
                } else {
                    break;
                }
            }
            if (j == wordsCount) {
                result.push_back(i);
            }
        }

        return result;
    }
};

