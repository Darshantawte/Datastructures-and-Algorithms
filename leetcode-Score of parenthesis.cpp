class Solution {
public:
    int bin_expo(int a,int b)
    {
        int res=1;

        while(b!=0)
        {
            if(b & 1)res*=a;

            a=a*a;
            b=b>>1;
        }

        return res;
    }
    int scoreOfParentheses(string s) {
        int ans=0;
        int n=s.size();
        if(n==2)
          return 1;

        int i=0;
        stack<char> st;

        while(i<n)
        {
             while(i<n && s[i]=='('){
               st.push(s[i]);
               i++;
             }

             ans+=bin_expo(2,st.size()-1);

             while(i<n && s[i]==')' && st.empty()==false)
             {
                 st.pop();
                 i++;
             }
        }

        return ans;
    }
};