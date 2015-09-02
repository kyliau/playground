// Compare two version numbers version1 and version2.
// If version1 > version2 return 1,
// if version1 < version2 return -1,
// otherwise return 0.
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three",
// it is the fifth second-level revision of the second first-level revision.
// Here is an example of version numbers ordering:
// 0.1 < 1.1 < 1.2 < 13.37

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = version1.begin();
        auto v2 = version2.begin();
        while (v1 != version1.end() || v2 != version2.end()) {
            int n1 = 0;
            int n2 = 0;
            while (v1 != version1.end() && *v1 != '.') {
                n1 = n1 * 10 + (*v1 - '0');
                ++v1;
            }
            while (v2 != version2.end() && *v2 != '.') {
                n2 = n2 * 10 + (*v2 - '0');
                ++v2;
            }
            if (*v1 == '.') {
                ++v1;
            }
            if (*v2 == '.') {
                ++v2;
            }
            if (n1 > n2) {
                return 1;
            }
            if (n1 < n2) {
                return -1;
            }
        }
        return 0;
    }
};
