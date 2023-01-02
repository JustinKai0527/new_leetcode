from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        
        st = list()
        
        for str in tokens:
            
            if str not in ["+","-","*","/"]:
                st.append(int(str))
            else:
                if str == "+":
                    st.append(st.pop() + st.pop())
                elif str == "-":
                    a = st.pop()
                    b = st.pop()
                    st.append(b - a) 
                elif str == "*":
                    st.append(st.pop() * st.pop())
                elif str == "/":
                    a = st.pop()
                    b = st.pop()
                    st.append((int) (b / a))
                    
        
        return st.pop() 