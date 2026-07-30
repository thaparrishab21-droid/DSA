class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string ans = s;

        // Reverse every prefix
        for (int k = 1; k <= n; k++) {
            string t = s;
            reverse(t.begin(), t.begin() + k);
            ans = min(ans, t);
        }

        // Reverse every suffix
        for (int k = 1; k <= n; k++) {
            string t = s;
            reverse(t.end() - k, t.end());
            ans = min(ans, t);
        }

        return ans;
    }
};