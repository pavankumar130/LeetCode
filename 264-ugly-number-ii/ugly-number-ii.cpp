class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seenNumbers;  
        vector<int> primeFactors = {2, 3, 5};  

        minHeap.push(1);
        seenNumbers.insert(1);

        long currentUgly = 1;
        for (int i = 0; i < n; ++i) {
            currentUgly = minHeap.top();  
            minHeap.pop();                

            for (int prime : primeFactors) {
                long nextUgly = currentUgly * prime;
                if (seenNumbers.find(nextUgly) == seenNumbers.end()) {  
                    minHeap.push(nextUgly);
                    seenNumbers.insert(nextUgly);
                }
            }
        }

        return int(currentUgly);  
    }
};