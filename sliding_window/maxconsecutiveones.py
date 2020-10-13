# Max Consecutive Ones
# https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3238


class Solution:
    def findMaxConsecutiveOnes(self, nums):
        start_pos = 0
        end_pos = 0
        max_len = 0
        pos = 0
        while (pos < len(nums)):
            if nums[pos] == 1:
                # 窗口伸长
                l = end_pos - start_pos + 1
                max_len = max(max_len, l)
                end_pos = end_pos + 1
            elif nums[pos] == 0:
                # 窗口移动
                start_pos = pos + 1
                end_pos = start_pos
            pos = pos + 1

        return max_len

if __name__ == "__main__":
    s = Solution()
    print(s.findMaxConsecutiveOnes([1,0,1,1,0,1]))