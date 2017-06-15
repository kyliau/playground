// XML encoding

// Example:

// 0123456789
// foo bar baz
// [
//   [ 0, 11, 'b' ],
//   [ 4, 11, 'i' ],
//   [ 8,  9, 'u' ]
// ]

// <b>foo <i>bar <u>b</u>az</i></b>

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;

struct Input {
    int  start;
    int  end;
    char tag;
};

bool operator==(const Input& lhs, const Input& rhs) {
    return lhs.start == rhs.start &&
           lhs.end   == rhs.end &&
           lhs.tag   == rhs.tag;
}

bool operator!=(const Input& lhs, const Input& rhs) {
    return lhs.start != rhs.start ||
           lhs.end   != rhs.end ||
           lhs.tag   != rhs.tag;
}

void openTag(ostream& stream, std::stack<Input>& s, const Input& input) {
    stream << '<' << input.tag << '>';
    s.push(input);
}

void closeTag(ostream& stream, std::stack<Input>& s, const Input& input) {
    if (!s.empty() && s.top() != input) {
        Input temp = s.top();
        closeTag(stream, s, temp);
        closeTag(stream, s, input);
        openTag(stream, s, temp);
    }
    else {
        assert(!s.empty());
        assert(s.top() == input);
        stream << "</" << input.tag << '>';
        s.pop();
    }
}

string encode(const string& str, vector<Input>& v) {
    std::sort(v.begin(),
              v.end(),
              [](const Input& lhs, const Input& rhs) {
                  return lhs.start < rhs.start;
              });
    auto cmp = [](const Input& lhs, const Input& rhs) {
        return lhs.end > rhs.end;
    };
    std::stack<Input> s;
    std::priority_queue<Input, std::vector<Input>, decltype(cmp)> q(cmp);
    std::ostringstream oss;
    int i = 0;
    for (int j = 0; j < str.size(); ++j) {
        while (!q.empty() && q.top().end == j) {
            closeTag(oss, s, q.top());
            q.pop();
        }
        while (i < v.size() && v[i].start == j) {
            openTag(oss, s, v[i]);
            q.push(v[i]);
            ++i;
        }
        oss << str[j];
    }
    while (!s.empty()) {
        closeTag(oss, s, s.top());
    }
    return oss.str();
}

int main() {
    struct {
        int           num;
        string        str;
        vector<Input> v;
    } CASES[] = {
        { 1, "foo bar baz", {{0, 11, 'b'}, {4, 11, 'i'}, {8, 9, 'u'}} },
        { 2, "helloworld", {{0, 2, 'b'}, {3, 8, 'i'}, {5, 10, 'u'}} },
        { 3, "foo", {{0, 3, 'a'}, {0, 3, 'b'}, {0, 3, 'c'}} },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int            num = CASES[i].num;
        const string&  str = CASES[i].str;
        vector<Input>&  v   = CASES[i].v;
        cout << "Test case " << num << " ... ";
        string result = encode(str, v);
        cout << result << endl;
    }
    return 0;
}