#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        
        // Ordena o vetor de satisfação em ordem decrescente
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        
        int maxTimeSimilarity = 0;
        int currentSum = 0;
        int time = 0;
        
        for (int i = 0; i < n; i++) {
            //Atualiza a soma das satisfações
            currentSum += satisfaction[i];
            //Atualiza o tempo considerando a soma
            time += currentSum;
            //Atualiza o valor máximo do coeficiente de tempo semelhante
            maxTimeSimilarity = max(maxTimeSimilarity, time);
        }
        
        return maxTimeSimilarity;
    }
};
