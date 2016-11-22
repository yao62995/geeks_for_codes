class Solution(object):
    def __init__(self):
        self.digit_map = {0: "Zero", 1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six",
                          7: "Seven", 8: "Eight", 9: "Nine", 10: "Ten",
                          11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen",
                          16: "Sixteen", 17: "Seventeen", 18: "Eighteen", 19: "Nineteen",
                          20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty", 60: "Sixty",
                          70: "Seventy", 80: "Eighty", 90: "Ninety"}
        self.bit_stage = ["", "Thousand", "Million", "Billion"]

    def sub_numberToWords(self, num, stage):
        if num == 0:
            return ""
        res = ""
        if num >= 100:
            res += self.digit_map[num / 100] + " Hundred "
        num %= 100
        num_1 = num % 10
        num_10 = num / 10
        if num >= 20:
            if num_1 == 0:
                res += self.digit_map[num] + " "
            else:
                res += self.digit_map[num_10 * 10] + " " + self.digit_map[num_1] + " "
        elif num > 0:
            res += self.digit_map[num] + " "
        res += self.bit_stage[stage] + " "
        return res


    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return self.digit_map[num]
        stage = 0
        result = ""
        while num > 0:
            sub_num = num % 1000
            result = self.sub_numberToWords(sub_num, stage) + result
            num /= 1000
            stage += 1
        result = result.rstrip()
        return result