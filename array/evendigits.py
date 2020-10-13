# Find Numbers with Even Number of Digits
# https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3237/

class Solution:
    def getDigits(self, num):
        digits = 0
        while True:
            num = num // 10
            digits = digits + 1
            if num == 0:
                break
        return digits
            
    def findNumbers(self, nums):
        # 计算位数
        max_digits = 0
        even_digits_count = 0
        for num in nums:
            digits = self.getDigits(num)
            if digits%2 == 0:
                even_digits_count = even_digits_count + 1
        return even_digits_count

if __name__ == "__main__":
    s = Solution()
    print(s.findNumbers([12,345,2,6,7896]))