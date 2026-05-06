class Solution(object):
    def answerString(self, word, numFriends):
        """
        :type word: str
        :type numFriends: int
        :rtype: str
        """
        if numFriends == 1:
            return word
        
        n = len(word)
        best_substr = ""
        
        for i in range(n):
            # j_max(i) = min(n-1, i + (n - numFriends))
            j_max = min(n - 1, i + (n - numFriends))
            if j_max >= i:
                candidate = word[i : j_max + 1]
                if candidate > best_substr:
                    best_substr = candidate
        
        return best_substr
    
sol = Solution()
print(sol.answerString("dbca", 2))