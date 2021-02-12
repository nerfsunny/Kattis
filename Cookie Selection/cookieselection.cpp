#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

int main(int argc, char** argv) {
	string input;
	list<int> cookies;
	list<int>::iterator cookie1, cookie2;

	while(getline(cin, input)) {
		if(input != "#") {
			cookies.emplace_back(stoi(input));
			cookies.sort();
		}else {
			cookie1 = cookies.begin();
			cookie2 = cookies.begin();

			if(cookies.size() > 1) {
				if(cookies.size() % 2 == 0)
					advance(cookie2, cookies.size()/2);
				else
					advance(cookie2, cookies.size()/2);

				if(*cookie1 == *cookie2) {
					cout << *cookie1 << endl;
					cookies.pop_front();
				}else {
					cout << *cookie2 << endl;
					cookies.erase(cookie2);
				}
			}else {
				cout << *cookie1 << endl;
				cookies.pop_front();
			}
		}
	}

	return 0;
}