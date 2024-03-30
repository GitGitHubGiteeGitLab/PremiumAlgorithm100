class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size() == s2.size()){
            int hash[26];
            for(auto ch : s1)hash[ch - 'a']++;
            for(auto ch : s2)
            {
                if(--hash[ch - 'a'] < 0)
                    return false;
            }
            return true;
        }
        return false;

    }
};
