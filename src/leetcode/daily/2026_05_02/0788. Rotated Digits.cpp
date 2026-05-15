class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int r, q, m, i = 1; i <= n; ++i){
            bool has_347 = false;
            bool has_2569 = false; 
            m = i;
            while (m){
                q = m % 10;
                m /= 10;
                if (q == 2 || q == 5 || q == 6 || q == 9) has_2569 = true;
                if (q == 3 || q == 4 || q == 7) has_347 = true;
            }
            cnt += (!has_347 && has_2569);
        }   
        return cnt;  
    }
};
