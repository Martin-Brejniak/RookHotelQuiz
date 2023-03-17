//Martin Brejniak

#include <stdio.h>

//Inputs: int N, int M
//Output: A series of squares that can be made out of from that piece of paper.
int squaresCal(int n, int m) {
    int k;
    int min;
    if (n < m) { //Find min size of paper
        k = n;
        min = n;
    } else {
        k = m;
        min = k;
    }
    
    for (k; k > 0; k--) {
        int numSquares = (n/k) * (m/k); //The amount of paper squares that can be cut
        
        int j;
        for (j = 0; j < numSquares; j++) { 
            printf("%dx%d ", k, k);
        }
        
        if (min == n) {
            m -= k * numSquares; //Paper remaining
            if (m < k) { 
                int temp = m; 
                m = n;
                n = temp;
            }
        } else {
            n -= k * numSquares; //Paper remaining
            if (n < k) { 
                int temp = n; 
                n = m;
                m = temp;
            }
        }
        
    }
    
    return k;
};
 
//Run code here
int main() {
   squaresCal(5, 6);
   return 0;
}