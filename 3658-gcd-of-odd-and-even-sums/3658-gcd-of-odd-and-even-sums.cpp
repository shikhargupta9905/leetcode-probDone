class Solution {
public:
    int sumOdd(int n){
        int sum =0;
        for( int i =1; i<=2*n-1;i++){
            if(i%2!=0){
                sum +=i;
            }
        }
        return sum;
    }
    int sumEven(int n){
        int sum =0;
        for(int i =2; i<=2*n;i++){
            if(i%2==0){
             sum +=i;
            }
        }
        return sum;
    }

   
    int gcdOfOddEvenSums(int n) {
       int  a= sumOdd(n);
        int b=  sumEven(n);
        return gcd(a, b);
    }
};