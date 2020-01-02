/*
    Link - https://practice.geeksforgeeks.org/problems/multiply-two-strings/1/?track=sp-strings&batchId=152

    Complexity - O(n * m) where n and m are length of both the string;

*/
string multiplyStrings(string s1, string s2) {
    bool neg = false;
    if(s1[0] == '-' && s2[0] == '-') {
        neg = false;
        s1.erase(0, 1);
        s2.erase(0, 1);
    }
    else if(s1[0] == '-' || s2[0] == '-'){
        neg = true;
        if(s1[0] == '-') s1.erase(0, 1);
        else s2.erase(0, 1);
    }
    int len1 = s1.size();
    int len2 = s2.size();
    
    if(len1 == 0 || len2 == 0) return "0";
    
    vector<int> result(len1 + len2, 0);
    
    int i_1 = 0, i_2 = 0;
    for(int i = len1 - 1; i >= 0; i--){
        int carry = 0;
        i_2 = 0;
        int n1 = s1[i] - '0';
        for(int j = len2 - 1; j >= 0; j--){
            int n2 = s2[j] - '0';
            
            int res = n1 * n2 + result[i_1 + i_2] + carry;
            
            carry = res / 10;
            
            result[i_1 + i_2] = res % 10;
            
            i_2++;
        }
        if(carry > 0){
            result[i_1 + i_2] += carry;
        }
        i_1++;
    }
    
    int i = result.size() - 1;
    while(i >= 0 && result[i] == 0){
        i--;
    }
    
    if(i == -1) return "0";
    
    string ans;
    if(neg) ans += '-';
    
    while(i >= 0){
        ans += to_string(result[i--]);
    }
    return ans;
}