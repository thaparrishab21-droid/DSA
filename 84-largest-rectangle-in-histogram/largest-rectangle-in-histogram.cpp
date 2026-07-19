class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        st.push(-1);
        int area=0;
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                int height=heights[st.top()];
                st.pop();
                int width=i-st.top()-1;
                area=max(area,height*width);
            }
            st.push(i);
        }
        while (st.top() != -1) {
            int height = heights[st.top()];
            st.pop();
            int width = heights.size() - st.top() - 1;
            area = max(area, height * width);
        }
    return area;
    }
};
