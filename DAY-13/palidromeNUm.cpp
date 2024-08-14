link: https://leetcode.com/problems/palindrome-number/
//leetcode problem num=9

class Solution {
public:
    bool isPalindrome(int x) {
        int rev=0;
        int temp=x;
        if(temp<0) return false;
        while(temp!=0){
            int pop=temp%10;
            temp = temp/10;
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return false;
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return false;
            rev = (rev*10) + (pop);

            
        }
        return (rev==x); 
    }
};