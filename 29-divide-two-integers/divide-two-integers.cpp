class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Division by 1
        if (divisor == 1)
            return dividend;

        // Division by -1
        if (divisor == -1)
            return -dividend;

        // Determine sign
        bool negative = false;

        if ((dividend < 0 && divisor > 0) ||
            (dividend > 0 && divisor < 0)) {
            negative = true;
        }

        // Convert to positive using long long
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long ans = 0;

        // Repeated subtraction
        while (a >= b) {
            a -= b;
            ans++;
        }

        // Apply sign
        if (negative)
            ans = -ans;

        return (int)ans;
    }
};