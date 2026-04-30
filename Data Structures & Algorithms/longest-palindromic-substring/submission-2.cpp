class Solution {
public:
    string getPalin(string s, int b, int f) {
        while(b >= 0 && f < s.size() && s[b] == s[f]) {
            b--; f++;
        }
        b++; f--;
        if(f <= b) return "";
        return s.substr(b, f-b+1);
    }

    string longestPalindrome(string s) {
        string res = "";
        res += s[0];

        for(int i = 1; i < s.size(); i++) {
            auto t = getPalin(s, i-1, i+1);
            if(t.size() > res.size()) res = t;
            t = getPalin(s, i-1, i);
            if(t.size() > res.size()) res = t;
        }

        return res;
    }
};
