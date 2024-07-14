class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(st.empty() || st.top()<0 || asteroids[i]*st.top()>0){
                st.push(asteroids[i]);
            }
            else{
                bool flag = true;
                while(!st.empty() && st.top()>0 && asteroids[i]*st.top()<0){
                    int val = st.top();
                    int val2 = asteroids[i];
                    if(abs(val)==abs(val2)){
                        st.pop();
                        flag = false;
                        break;
                    }
                    else if(abs(val)>abs(val2)){
                        flag = false;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(flag)st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            int val = st.top();
            ans.push_back(val);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};