/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

    int guessNumber(int n) {
        int L{1};
        int R{n};

        while (L <= R){
            int mid = L + (R-L) / 2;
            int curr = guess(mid);
            if (curr < 0) R = mid-1;
            else if (curr > 0) L = mid+1;
            else return mid;
        }

        return n; 
    }
};