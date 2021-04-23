#include <string>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000;



class BookRecord: public ItemRecord
{
public:
	//constructor
	BookRecord(string t="placeholder", double p = 0.99 , char r = 'D', vector<int> nums = vector<int>()):chPages{new int[MAX_SIZE]},size{nums.size()}{
		for(size_t i = 0; i < nums.size(); ++i){
			chPages[i] = nums[i];
		}
		title = t;
		price = p;
		rating = r;
	};
	~BookRecord(){
		delete [] chPages;
	};
	void to_string(){
		int total = 0;
		for(size_t i = 0; i < size; ++i){
			total += chPages[i];
		}
		cout << "book[ " << title << ", "<< price << ", "<< rating << ", "<< total << " ]\n";
	}
	//getters
	size_t get_size() const{ return size; };
private:
	int * chPages;
	size_t size;
};

