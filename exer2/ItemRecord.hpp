#include <iostream>
#include <string>
#include <stdexcept>


using namespace std;

class ItemRecord{
public:
	//constructor
	ItemRecord(string t = "Placeholder", double p = 0.99, char r = 'D'):title(t), price(p), rating(r){
		if(price < 0)throw invalid_argument("invalid_argument");
		if(rating != 'A' && rating != 'B' && rating != 'C' && rating != 'D')throw invalid_argument("invalid_argument");
	}

	//getters
	string get_title()const{ return title;}
	double get_price()const{ return price;}
	char get_rating()const{ return rating;}
	//setters
	void set_price(double p);
    friend ostream& operator<<(ostream& os, ItemRecord& ir){
		os << ir.title << "\n";
		return os;
	}
	virtual void to_string() = 0;
	bool operator==(const ItemRecord& ir){
		if(rating == ir.get_rating()){
			return true;
		}else{
			return false;
		}
	}
	virtual ~ItemRecord(){}
protected:
	string title;
	double price;
	char rating;
	
};

