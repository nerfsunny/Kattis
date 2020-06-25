#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	string line;

	while(cin >> line) {
		string comp = "", temp = "";
		int degree = 0;
		temp = line.substr(1);

		for(int len = 1; len <= line.length(); len++) {
			comp = line.substr(0, len);

			if(len == line.length())
				degree++;
			else if(temp.find(comp) == string::npos)
				break;
			else
				degree++;
		}

		if(degree == 0)
			cout << degree << endl;
		else
			cout << degree - 1 << endl;
	}

	return 0;
}