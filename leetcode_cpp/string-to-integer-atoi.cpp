class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL || *str == '\0') {
            return 0;
        }
        int integer = 0;
        int sign = 1;  // positive one
        const char * p = str;
        while (*p == ' ') {
            p++;   
        }
        if (*p == '-') {
            sign = -1;  // negative one
            p++;
        } else if (*p == '+') {
            p++;
        }
        if (!isdigit(*p)) {
            return 0;
        }
        while (*p == '0') {
            p++;
        }
        while (*p != '\0' && isdigit(*p)) {
            int number = *p - '0';
            if (integer < 214748364) {
                integer *= 10;
                integer += number;
                p++;
            } else if (integer == 214748364){
                if (number < 7) {
                    integer *= 10;
                    integer += number;
                } else if (number == 7) {
                    integer = 2147483647 * sign;
                    return integer;
                } else if (sign < 0) {
                    return -2147483648;
                } else {
                    return 2147483647;
                }
            } else {
                if (sign > 0) {
                    return 2147483647;  // overflow 
                } else {
                    return -2147483648;
                }
            }
        }
        integer *= sign;
        return integer;
    }
};