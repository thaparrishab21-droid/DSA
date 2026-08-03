class Solution {
public:
    string reversee(string s,int i,int j){
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    string reverseWords(string s) {
        int n=s.size();
        string temp="";
        int i=0;
         while (i < n) {

            // Skip all spaces
            while (i < n && s[i] == ' ')
                i++;

            // Copy one complete word
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }

            // Skip spaces after the word
            while (i < n && s[i] == ' ')
                i++;

            // Add only one space if another word exists
            if (i < n)
                temp += ' ';
        }

        s = temp;
        n = s.size();
        reverse(s.begin(),s.end());
        int l=0,r=0;
        i=0;
        int start=0;
        while(i<n){
            if(s[i]==' '){
                s=reversee(s,start,i-1);
                start=i+1;
            }
            i++;
        }
        s=reversee(s,start,n-1);
        return s;
    }
};