class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> parsed{};
        for (char c : s) {
            if (!isalnum(static_cast<unsigned char>(c))) 
                continue;
            parsed.push_back(tolower(static_cast<unsigned char>(c)));
        }

        vector<char> reversed{parsed};
        reverse(reversed.begin(), reversed.end());
        if (parsed == reversed) return true;
        return false;
    }
};
