class Solution {
private: 
    int numOfNewBottles(int numOfRemainingBottles, int numExchange) { 
        return numOfRemainingBottles / numExchange ;
    }

    int numOfRemainingEmptyBottles (int numOfRemainingBottles, int numExchange) { 
        return numOfRemainingBottles % numExchange ;
    }

public:
    int numWaterBottles(int numBottles, int numExchange) {
        int refilledBottles = numOfNewBottles(numBottles, numExchange); 
        int emptyBottles =  numOfRemainingEmptyBottles(numBottles, numExchange); 
        int maxNumberOfDrinkWater = numBottles + refilledBottles; 
        while (emptyBottles + refilledBottles >= numExchange) { 
            int totalEmptyBottles = emptyBottles + refilledBottles; 
            refilledBottles = numOfNewBottles(totalEmptyBottles, numExchange); 
            maxNumberOfDrinkWater += refilledBottles;
            emptyBottles =  numOfRemainingEmptyBottles(totalEmptyBottles, numExchange); 
        }
        return maxNumberOfDrinkWater; 
    }
};
