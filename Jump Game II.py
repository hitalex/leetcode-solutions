class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        n = len(A)
        min_steps = [0] * n
        for i in range(1, n):
            min_steps[i] = float('inf')
            for j in range(i):
                if min_steps[j] != float('inf') and j + A[j] >= i: # can jump from j to i
                    min_steps[i] = min_steps[j] + 1 # inc the number of jumps
                    break
                else:
                    continue
                    
            
        return min_steps[-1]
