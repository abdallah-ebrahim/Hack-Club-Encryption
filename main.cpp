#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


void Decrypt(std::string str, int encryption) {

	std::string final_string = "";

	std::vector<char> final;

	for (int i = 0; i < str.length(); i++) {
		
		char sss = str.at(i);

		if (sss == *" " || sss == *"," || sss == *".") {
			final.push_back(sss);
		}
		else {
			int n = sizeof(letters) / sizeof(letters[0]);
			auto itr = std::find(letters, letters + n, sss);
			int index = std::distance(letters, itr);
			if (index - encryption < 0) {
				int new_index = abs(index - encryption);
				if (n - new_index < 0) {
					char& el = letters[n - abs(n - new_index)];
					final.push_back(el);
				}
				else {
					char& el = letters[n - new_index];
					final.push_back(el);
				}
			}
			else {
				char& el = letters[index - encryption];
				final.push_back(el);
			}
		}
	}
	for (char i : final) {
		final_string = final_string + i;
	}

	std::cout << final_string << std::endl;

}
int main() {
	Decrypt("TMXXA QHQDKNAPK, PA ZAF TQEUFMFQ UZ OAYBXQFUZS FTUE MBBXUOMFUAZ RADY, PA ZAF GEQ MU, MZP QZVAK KAGD HMOMFUAZ.", 38);
}