class Solution(object):
    def checkOnesSegment(self, s):
        count = 0
        i = 0
        while i < len(s):
            if s[i] == '1':
                count += 1
                if count > 1:
                    return False
                # Skip entire segment of 1s
                while i < len(s) and s[i] == '1':
                    i += 1
            else:
                i += 1
        return True