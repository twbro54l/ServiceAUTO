#include<string>

using namespace std;

class Product {
private:
	int id;
	string name;
	string category;
	double price;
	int quantity;

public:
	Product(int id, string name, string category, double price, int quantity) {
		this->id = id;
		this->name = name;
		this->category = category;
		this->price = price;
		this->quantity = quantity;
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

	string getName() const {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	string getCategory() const {
		return category;
	}

	void setCategory(string category) {
		this->category = category;
	}

	double getPrice() const {
		return price;
	}

	void setPrice(double price) {
		this->price = price;
	}

	int getQuantity() const {
		return quantity;
	}

	void setQuantity(int quantity) {
		this->quantity = quantity;
	}
};
