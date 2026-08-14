class Solution {
public:
    bool isValid(const string& s) {
        vector<char> st;

        unordered_map<char, char> openToClosed{
            {'{', '}'}, 
            {'[', ']'}, 
            {'(', ')'}
        };

        unordered_set<char> openBrackets{'{', '[', '('};
        unordered_set<char> closedBrackets{'}', ']', ')'};

        for (auto c : s) {
            if (openBrackets.count(c)) {
                st.push_back(c);
                continue;
            }
            if (closedBrackets.count(c)) {
                if (st.empty()) return false;
                char lastOpen{st.back()};
                st.pop_back();
                if (c != openToClosed[lastOpen]) return false;
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};


/**

- define a stack
- traverse chars c in s
    - if c is open bracket, add it to stack
    - if c is close bracket pop stack
        - popped open bracket should correspond to c
        - otherwise invalid 

*/