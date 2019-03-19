#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
using namespace std;

string  adder(bitset<4> buff, char f) {
	string res = "";
	ostringstream ost;
	for (int i = 0; i < 4; i++) {
		ost.str("");
		if (f == '1') {
			ost << i + 1;
			if (buff[3 - i] == 0) res += "-x" + ost.str();
			else res += "x" + ost.str();
		}
		else if (f == '0') {
			if (i == 0) res += '(';
			ost << i + 1;
			if (buff[3 - i] == 0) res += "x" + ost.str();
			else res += "-x" + ost.str();
			if (i != 3) res += "v";
		}
	}
	if (f == '0') res += ") ^ ";
	return res;
}

int main() {
	string number, buff, result1 = "DDNF =", result2 = "DKNF =";
	cout << "Enter your function:";
	cin >> number;
	int length = number.length();
	if (length == 16) {
		for (int i = 0; i < length; i++) {
				cout << bitset<4>(i) << ' ' << number[i] << endl;
				if (number[i] == '1') {
					if (i != length - 1)
						result1 += adder(bitset<4>(i), number[i]) + " v ";
					else result1 += adder(bitset<4>(i), number[i]);
				}
				else if (number[i] == '0')
					result2 += adder(bitset<4>(i), number[i]);
		}
		result1.erase(result1.size() - 2);
		result2.erase(result2.size() - 2);
	}
	cout << result1 << endl << endl << result2 << endl;
}
