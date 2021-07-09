class Solution {
    public boolean isMatch(char charStack, char charString){
        if( charStack == '(' && charString == ')'){
            return true;
        } else if ( charStack == '[' && charString == ']'){
            return true;
        } else if (charStack == '{' && charString == '}'){
            return true;
        } else {
            return false;
        } 
    }
    
    public boolean isValid(String s) {
        boolean result = false;
        Stack<Character> stack = new Stack<Character>();
        
        for(char c: s.toCharArray()){
            if(stack.empty()){
                stack.push(c);
            } else if(isMatch(stack.peek(), c)){
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }
}
/*
* Time Complexity: O(n)
* Space Complexity: O(n)
*/