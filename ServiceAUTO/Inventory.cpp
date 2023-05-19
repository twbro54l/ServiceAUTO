#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include "Product.cpp"

using namespace std;

class Inventory {
private:
	vector<Product> products;

public:
	void addProduct(Product product) {
		bool found = false;
		for (auto& p : products) {
			if (p.getId() == product.getId()) {
				cout << "ID already exists." << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			products.push_back(product);
			cout << "Product added successfully." << endl;
		}
	}

	void removeProduct(int id) {
		bool found = false;
		for (auto i = products.begin(); i != products.end(); i++) {
			if (i->getId() == id) {
				products.erase(i);
				found = true;
				cout << "Product removed successfully." << endl;
				break;
			}
		}
		if (!found) {
			cout << "ID does not exist" << endl;
		}
	}

	Product* findProduct(int id) {
		for (auto i = products.begin(); i != products.end(); i++) {
			if (i->getId() == id) {
				return &(*i);
			}
		}
		return nullptr;
	}

	void updateProduct(int id, string name, string category, double price, int quantity) {
		bool found = false;
		for (auto i = products.begin(); i != products.end(); i++) {
			if (i->getId() == id) {
				i->setName(name);
				i->setCategory(category);
				i->setPrice(price);
				i->setQuantity(quantity);
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "ID does not exist." << endl;
		}
	}

	void printProduct() const {
		for (auto i = products.begin(); i != products.end(); i++) {
			cout << "ID : " << i->getId() << endl;
			cout << "Name : " << i->getName() << endl;
			cout << "Category : " << i->getCategory() << endl;
			cout << "Price : " << i->getPrice() << endl;
			cout << "Quantity : " << i->getQuantity() << endl;
		}
	}

	void saveInventoryToFile(string filename) {
		ofstream file;
		file.open(filename, ios::out | ios::app);
		for (int i = 0; i < products.size(); i++) {
			Product p = products[i];
			file << p.getId() << "," << p.getName() << "," << p.getCategory() << "," << p.getPrice() << "," << p.getQuantity() << endl;
		}
		file.close();
	}

	void loadInventoryFromFile(string filename) {
		ifstream file;
		file.open(filename);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				stringstream ss(line);
				string idStr, name, category, priceStr, quantityStr;
				getline(ss, idStr, ',');
				getline(ss, name, ',');
				getline(ss, category, ',');
				getline(ss, priceStr, ',');
				getline(ss, quantityStr, ',');

				int id = stoi(idStr);
				double price = stod(priceStr);
				int quantity = stoi(quantityStr);

				Product p(id, name, category, price, quantity);
				products.push_back(p);
			}

			file.close();
		}
		else {
			cout << "Error: Could not open file " << filename << endl;
		}
	}
};
