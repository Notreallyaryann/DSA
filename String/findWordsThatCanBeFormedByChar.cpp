class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charcount(26, 0);
        int result = 0;

        // Count frequency of each character in chars
        for (char &ch : chars) {
            charcount[ch - 'a']++;
        }

        // Check each word
        for (string &word : words) {
            vector<int> wordcount(26, 0); 
            for (char &ch : word) {
                wordcount[ch - 'a']++;
            }

            bool possible = true;
            for (int i = 0; i < 26; i++) {
                if (wordcount[i] > charcount[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                result += word.size();
            }
        }

        return result;
    }
};