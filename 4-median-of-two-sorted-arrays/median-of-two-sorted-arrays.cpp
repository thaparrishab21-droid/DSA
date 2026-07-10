class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        int l = 0, r = 0;
        vector<int> sorted;

        while (l < n && r < m) {
            if (nums1[l] <= nums2[r]) {
                sorted.push_back(nums1[l]);
                l++;
            } else {
                sorted.push_back(nums2[r]);
                r++;
            }
        }

        while (l < n) {
            sorted.push_back(nums1[l]);
            l++;
        }

        while (r < m) {
            sorted.push_back(nums2[r]);
            r++;
        }

        int total = n + m;

        if (total % 2 == 1)
            return sorted[total / 2];

        return (sorted[total / 2] + sorted[total / 2 - 1]) / 2.0;
    }
};