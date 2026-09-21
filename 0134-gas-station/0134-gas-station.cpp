class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int currentTank = 0;
        int startIndex = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentTank += gas[i] - cost[i];

            // If currentTank drops below 0, we cannot reach station i + 1 from startIndex.
            // Reset startIndex to i + 1 and reset currentTank.
            if (currentTank < 0) {
                startIndex = i + 1;
                currentTank = 0;
            }
        }

        // If overall gas is less than overall cost, completing the circuit is impossible.
        if (totalGas < totalCost) {
            return -1;
        }

        return startIndex;
    }
};