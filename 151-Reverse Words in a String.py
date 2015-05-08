class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        s = s.strip()
        word_list = s.split(' ')
        n = len(word_list)
        r = ''
        for i in range(n-1, -1, -1):
            if word_list[i] != '':
                r += (word_list[i] + ' ')
            
        r = r.strip()
        return r
    
    
