#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;



//a function that decrypts cesar cipher
string decrypt(string text, int shift, unordered_map<char, int> &alphabet, unordered_map<int, char> &alphabet_reversed){
	string result = "";
	for(size_t i = 0; i < text.length(); ++i){
		int index = alphabet[text[i]] - shift;
		if(index < 0){
			result+= alphabet_reversed[index + 52];
		}else{
			result+= alphabet_reversed[index % 52];
		}
	}
	return result;
}
void populate_map(const string text, unordered_map<char, int> &alphabet){
	for(size_t i = 0; i < text.length(); ++i){
		alphabet[text[i]] = i;
	}
}
void reverse_map(const unordered_map<char, int> &alphabet, unordered_map<int, char> &alphabet_reversed){
	for(const auto pair: alphabet){
		alphabet_reversed[pair.second] = pair.first;
	}
}
int main (){
	unordered_map<char, int> alphabet;// indicate a map where key is the letter and value is it's position
	unordered_map<int, char> alphabet_reversed;
	const string ALPHABET{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	string str1{"uIFzBOLTbSFbMTPlOPXObTuIFcSPOYcPNCFST"};
	string str2{"dBFTBSdJQIFSfYFSDJTFxJUIdqMVTqMVT"};
	string key{"Yanks"};
	int shift = 1;

	//populate maps
	populate_map(ALPHABET, alphabet);
	reverse_map(alphabet, alphabet_reversed);
	
	while(decrypt(str1, shift, alphabet, alphabet_reversed).find("Yanks") == string::npos){
		shift++;
	}
	cout << decrypt(str1, shift, alphabet, alphabet_reversed) << endl;
	cout << decrypt(str2, shift, alphabet, alphabet_reversed) << endl;

	return 0;
}
