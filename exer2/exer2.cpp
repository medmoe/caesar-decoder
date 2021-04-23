#include <iostream>
#include <stdexcept>
#include <vector>
#include "ItemRecord.hpp"
#include "BookRecord.hpp"
#include "CdRecord.hpp"

using namespace std;

const int MAX = 2;

void ItemRecord::set_price(double p){
		if(p < 0)throw range_error("range_error");
		price = p;
}

int main(){
	try{
		vector<int> v1 = {2,20,30,40,30,20};
		vector<double> v2 = {4.5, 15.0, 23.5, 4.3, 5.2, 20.3};
		BookRecord book1("SampleBook", 10.99, 'A', v1);
		CdRecord cd1("SampleCd", 14.99, 'B', v2);
		cout << "My book's title is: " << book1;
		cout << "My CD's title is: "<< cd1;
		book1.set_price(book1.get_price() - 1);
		cd1.set_price(cd1.get_price() - 1);
		cout << "Do they have the same rating? ";
		if(book1 == cd1){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
		ItemRecord * records[MAX] = {&book1, &cd1};
		for(int i = 0; i < MAX; ++i){
			records[i]->to_string();
		}


	}catch(const invalid_argument& a){
		cout << "invalid_argument" << endl;
	}catch(const range_error& a){
		cout << "negative price" << endl;
	}
	
	return 0;
}