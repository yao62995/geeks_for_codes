class Solution {
public:
    string intToRoman(int num) {
        string roman;
        while (num > 0) {
            if (num >= 1000) {
                num -= 1000;
                roman.append("M");
            } else if (num >= 500) {
                if (num >= 900) {
                    num -= 900;
                    roman.append("CM");
                } else {
                    num -= 500;
                    roman.append("D");
                }
            } else if (num >= 100) {
                if (num >= 400) {
                    num -= 400;
                    roman.append("CD");
                } else {
                    num -= 100;
                    roman.append("C");
                }
            } else if (num >= 50) {
                if (num >= 90) {
                    num -= 90;
                    roman.append("XC");
                } else {
                    num -= 50;
                    roman.append("L");
                }
            } else if (num >= 10) {
                if (num >= 40) {
                    num -= 40;
                    roman.append("XL");
                } else {
                    num -= 10;
                    roman.append("X");
                }
            } else if (num >= 5) {
                if (num >= 9) {
                    num -= 9;
                    roman.append("IX");
                } else {
                    num -= 5;
                    roman.append("V");
                }
            } else {
                if (num >= 4) {
                    num -= 4;
                    roman.append("IV");
                } else {
                    num -= 1;
                    roman.append("I");
                }
            }
        }
        return roman;
    }
};