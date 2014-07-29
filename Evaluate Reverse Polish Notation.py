class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        stack = []
        operand_set = set(['+', '-', '*', '/'])
        n = len(tokens)
        for i in range(n):
            if tokens[i] in operand_set:
                num2 = stack.pop()
                num1 = stack.pop()
                result = None
                if tokens[i] == '+':
                    result = num1 + num2
                elif tokens[i] == '-':
                    result = num1 - num2
                elif tokens[i] == '*':
                    result = num1 * num2
                else:
                    if num1 * num2 < 0:
                        tmp = num1 * 1.0 / num2
                        if tmp == int(tmp):
                            result = num1 / num2
                        else:
                            result = num1 / num2 + 1
                    else:
                        result = num1 / num2
                    
                stack.append(result)
            else:
                num = int(tokens[i])
                stack.append(num)
                
        return stack[0]
