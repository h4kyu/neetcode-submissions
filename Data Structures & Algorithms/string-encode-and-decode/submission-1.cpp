class Solution {

public:

    string encode(vector<string>& strs) {
        string encoded;

        for (const string& str : strs) {
            int N{static_cast<int>(str.size())};
            encoded += to_string(N) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        size_t i{0};

        while (s[i] != '\0') {
            string N;
            while (s[i] != '#') {
                N += s[i];
                ++i;
            }
            int Nparsed{stoi(N)};
            ++i;    // skip '#'
            string str{s.substr(i, Nparsed)};
            decoded.push_back(str);
            i += Nparsed;
        }
        return decoded;
    }
};


// 10#abcdefghij3#ab3

/**

delimiter N# where N = str length

encode:
- define result string
- iterate str : strs
    - get str length N
    - concatenate "N#" + str to result
- return result

- define parse length N helper

decode:
- define result vector
- iterate char : str by index
    - if char is #
        - parse N with helper
        - add parsed string to result
        - increment index

*/
