#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    int n = words.size(), m = words[0].size(); // Number of words, length of each word

    // Create a hash map to store word frequencies in the dictionary
    unordered_map<string, int> wordFreq;
    for (string& word : words) {
        wordFreq[word]++;
    }

    // Iterate through all possible starting positions
    for (int i = 0; i <= s.size() - n * m; i++) {
        unordered_map<string, int> windowFreq; // Hash map for sliding window

        // Fill the sliding window with frequencies of encountered words
        for (int j = 0; j < n; j++) {
            string word = s.substr(i + j * m, m);
            if (wordFreq.count(word) == 0 || windowFreq[word] > wordFreq[word]) {
                // Word not found in dictionary or exceeds frequency limit
                break;
            }
            windowFreq[word]++;
        }

        // Check if all word frequencies match in the window
        if (windowFreq.size() == wordFreq.size()) {
            result.push_back(i);
        }
    }

    return result;
}

