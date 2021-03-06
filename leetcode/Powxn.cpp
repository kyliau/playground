//Implement pow(x, n).

class Solution {
    double positivePow(double x, unsigned n) {
        if (0 == n) {
            return 1;
        }
        double result = positivePow(x, n / 2);
        result *= result;
        return (n % 2 == 0) ? result : result * x;
    }
public:
    double myPow(double x, int n) {
        return n > 0 ? positivePow(x, n) : 1 / positivePow(x, -n);
    }
};
