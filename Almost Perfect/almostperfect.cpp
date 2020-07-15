#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
using ll = long long int;

ll factorSums(vector<ll>& factors) {
	ll sum = 0;

	for(ll x : factors)
		sum += x;

	return sum;
}

ll getBiggestDivisor(map<ll, vector<ll>>& table, const ll num) {
	ll factor = 0;

	for(auto& x : table)
		if(num % x.first == 0)
			factor = x.first;

	return factor;
}

void getFactors(vector<ll>& factors, const ll num, const ll startingPoint) {
	for(int i = startingPoint + 1; i <= num/2; i++)
		if(num % i == 0)
			factors.emplace_back(i);
}

int main(int argc, char** argv) {
	ll num;
	vector<ll> factors;
	map<ll, vector<ll>> table;

	while(cin >> num) {
		ll biggestDivisor = getBiggestDivisor(table, num);

		if(biggestDivisor > 0)
			factors = table[biggestDivisor];

		getFactors(factors, num, biggestDivisor);

		ll sum = factorSums(factors);

		if(sum == num)
			cout << num << " perfect\n";
		else if(abs(sum - num) <= 2)
			cout << num << " almost perfect\n";
		else
			cout << num << " not perfect\n"; 

		factors.clear();
	}

	return 0;
}