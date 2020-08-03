// Given numBottles full water bottles, you can exchange numExchange empty water bottles for one full water bottle.

// The operation of drinking a full water bottle turns it into an empty bottle.

// Return the maximum number of water bottles you can drink.



class Solution {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		int res = numBottles;
		while (numBottles >= numExchange)
		{
			int remainingBottles = numBottles % numExchange;
			numBottles /= numExchange;
			res += numBottles;
			numBottles += remainingBottles;
		}
		return res;
	}
};