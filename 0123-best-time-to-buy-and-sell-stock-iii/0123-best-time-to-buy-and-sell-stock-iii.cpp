class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = 0, profit2 = 0;

        for (int price : prices) {
            // First transaction
            buy1 = min(buy1, price);                   // Lowest price to buy first stock
            profit1 = max(profit1, price - buy1);      // Max profit after selling first stock

            // Second transaction
            buy2 = min(buy2, price - profit1);         // Effective buy price using profit1 as a discount
            profit2 = max(profit2, price - buy2);      // Max profit after selling second stock
        }

        return profit2;
    }
};