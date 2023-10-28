#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Colocando as moedas em ordem crescente.
        sort(coins.begin(), coins.end());

        // O vetor dp para rastrear o número mínimo de moedas.
        vector<int> dp(amount + 1, amount + 1);

        // Inicializamos dp[0] como 0, já que nenhuma moeda é necessária para fazer a quantia de 0.
        dp[0] = 0;

        // Loop para cada valor de 1 até amount.
        for (int i = 1; i <= amount; i++) {
            // Loop para cada tipo de moeda.
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};