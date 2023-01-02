
class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        i = 0
        j = len(s) - 1
        s = s.upper()
        
        while i < j:
            
            if not(s[i].isalpha() or s[i].isnumeric()):
                i = i + 1
                continue
            if not(s[j].isalpha() or s[j].isnumeric()):
                j = j - 1
                continue              
            if s[i] != s[j]:
                return False
            
            i = i + 1
            j = j - 1
        
        return True
            
            