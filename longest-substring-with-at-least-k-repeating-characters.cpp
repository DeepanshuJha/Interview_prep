/*
    Link - https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/submissions/

    Complexity - O(n*26)

    Sol - As we want to find a substring in which every unique character should appear atleast
          k times. So lets think on unique characters, as there will be only 26 unique characters
          in a substring.

        - So lets check whether a substring is there or not having x unique character

        - This can be simply checked by maintaining a count array of characters and check 
            how many unique characters are there.

            if unique characters are less then the required than keep on adding the characters
            other wise stop and check that all the characters are having count more than k
            if yes than this length substring can be a possible answer

            if unique characters are more than required than start removing them by incrementing 
            the left pointer.
*/
class Solution {
public:
    int check(int h[]){
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(h[i] > 0) cnt++;
        }
        return cnt;
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        
        int len = 0;
        for(int uni = 1; uni < 27; uni++){
            int h[26] = {0};
            int l = 0, r = 0;
            while(l <= r && r < n){
                if(check(h) < uni){
                    h[s[r++] - 'a']++;
                }else if(check(h) == uni){
                    int f = 1;
                    for(int i = 0; i < 26; i++){
                        if(h[i] > 0){
                            if(h[i] < k){
                                f = 0;
                                break;
                            }
                        }
                    }
                    if(f == 1) len = max(len, r - l);
                    h[s[r++] - 'a']++;
                }else if(check(h) > uni){
                    h[s[l++] - 'a']--;
                }
            }
            if(check(h) == uni){
                int f = 1;
                for(int i = 0; i < 26; i++){
                    if(h[i] > 0){
                        if(h[i] < k){
                            f = 0;
                            break;
                        }
                    }
                }
                if(f == 1) len = max(len, r - l);
            }
        }
        
        return len;
    }
};