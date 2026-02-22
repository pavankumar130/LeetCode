class Solution {
    int factorial(int num){
        if(num == 0){
            return 1;
        }

        int sum = 1;
        for(int i = 1; i <= num; i++){
            sum *= i;
        }

        return sum;
    }

    vector<int> countdigit(int num){
        vector<int>arr;

        while(num){
            arr.push_back(num % 10);
            num /= 10;
        }
        sort(arr.begin(), arr.end());
        return arr;
    }
public:
    bool isDigitorialPermutation(int n) {
        int num = 0;

        int sum = 0;
        int temp = n;
        while(temp){
            sum += factorial(temp % 10);
            //cout<<factorial(temp % 10)<<" ";
            temp /= 10;
        }

        vector<int>arr1 = countdigit(n);
        vector<int>arr2 = countdigit(sum);
        return arr1 == arr2;
    }
};