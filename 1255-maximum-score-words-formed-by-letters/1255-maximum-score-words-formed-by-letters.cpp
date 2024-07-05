class Solution {
public:
    int solve(int index,int n,vector<string>& words,vector<int>& score,vector<int>& freq,vector<int>& freq2){
        if(index==n)return 0;
        //pick not pick 
        int ans = 0;
        int score1 = 0;
        for(int i=0;i<words[index].size();i++){
            freq2[words[index][i]-'a']++;
            score1+=score[words[index][i]-'a'];
        }
        bool flag = true;
        for(int i=0;i<26;i++){
            if(freq2[i]>freq[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            ans = score1 + solve(index+1,n,words,score,freq,freq2);
        }
        //backtrack
        for(int i=0;i<words[index].size();i++){
            freq2[words[index][i]-'a']--;
        }

        //not pick 
        int val = solve(index+1,n,words,score,freq,freq2);
        ans = max(ans,val);
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        //we have the freq array of letters
        vector<int> freq(26,0);
        int n = letters.size();
        for(int i=0;i<n;i++){
            freq[letters[i]-'a']++;
        }
        int m = words.size(); 
        vector<int> freq2(26,0);
        return solve(0,m,words,score,freq,freq2);
    }
};