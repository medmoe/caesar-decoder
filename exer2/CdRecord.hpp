#include <string>
#include <vector>

using namespace std;

class CdRecord: public ItemRecord
{
public:
	CdRecord(string t = "placeholder", double p = 0.99, char r = 'D', vector<double> vec = vector<double>()):trackTimes{new double[MAX_SIZE]},size{vec.size()}{
		for(size_t i = 0; i < size ; ++i){
			trackTimes[i] = vec[i];
		}
		title = t;
		price = p;
		rating = r;
	}
	~CdRecord(){
		delete [] trackTimes;
	}
	void to_string() override {
		double total = 0;
		for(size_t i = 0; i < size; ++i){
			total += trackTimes[i];
		}
		cout << "CD[ "<< title << ", " << price << ", " << rating << ", " << total << " ]"<<  endl;
	}
private: 
	double * trackTimes;
	size_t size;
};
