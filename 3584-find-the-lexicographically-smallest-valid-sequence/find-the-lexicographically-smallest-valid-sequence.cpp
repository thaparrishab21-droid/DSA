class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        vector<int> ans;

        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        // Find positions from right side
        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        // Build answer from left side
        j = 0;
        bool skip = true;

        for (int i = 0; i < n; i++) {

            if (j == m)
                break;

            if (word1[i] == word2[j] ||
                (skip && (j == m - 1 || i < last[j + 1]))) {

                if (word1[i] != word2[j])
                    skip = false;

                ans.push_back(i);
                j++;
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};