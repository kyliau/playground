#include <string>
#include <assert.h>

using namespace std;

int RabinKarp(const string& t, const string& s) {
    static const int kBase = 26;
    static const int kMod  = 997;

    if (s.size() > t.size()) {
        return -1;  // s is not a substring of t
    }

    int t_hash  = 0;
    int s_hash  = 0;
    int power_s = 1;    // the modulo result of kBase ^ |s|
    for (int i = 0; i < s.size(); ++i) {
        power_s = i ? power_s * kBase % kMod : 1;
        t_hash = (t_hash * kBase + t[i]) % kMod;
        s_hash = (s_hash * kBase + s[i]) % kMod;
    }

    for (int i = s.size(); i < t.size(); ++i) {
        // in case of hash collision but two strings are not equal, checks the
        // two substrings are actually equal or not
        if (t_hash == s_hash && !t.compare(i - s.size(), s.size(), s)) {
            return i - s.size();    // found a match
        }

        // uses rolling hash to compute the new hash code
        t_hash -= (t[i - s.size()] * power_s) % kMod;
        if (t_hash < 0) {
            t_hash += kMod;
        }
        t_hash = (t_hash * kBase + t[i]) % kMod;
    }

    // tries to match s and t[t.size() - s.size() : t.size() - 1]
    if (t_hash == s_hash && t.compare(t.size() - s.size(), s.size(), s) == 0) {
        return t.size() - s.size();
    }
    return -1;  // s is not a substring of t
}

int main() {
    assert( 6 == RabinKarp("dfdgfdabcgdfg3", "abc"));
    assert( 0 == RabinKarp("abc", "abc"));
    assert(-1 == RabinKarp("abc", "d"));
    assert(-1 == RabinKarp("a", "abc"));
}