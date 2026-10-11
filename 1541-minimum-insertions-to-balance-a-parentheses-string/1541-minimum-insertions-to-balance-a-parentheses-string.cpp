class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int left = 0; // Number of unmatched '('
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                left++;
            } else { // s[i] == ')'
                // Check if there is a second ')' right after
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++; // consume the next ')'
                } else {
                    // We are missing one ')'
                    insertions++;
                }
                
                // Now match with an open '(' if available
                if (left > 0) {
                    left--;
                } else {
                    // No '(' available to match, so we need to insert one '('
                    insertions++;
                }
            }
        }
        
        // Each remaining unmatched '(' requires two ')' insertions
        insertions += (left * 2);
        
        return insertions;
    }
};