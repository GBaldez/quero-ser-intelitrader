#include <iostream>

using namespace std;

class Book {
  public:
	double value;
	int quantity;

	void setValue(double v) {
		value = v;
	}
	void setQuantity(int q) {
		quantity = q;
	}
};

void printBooks(Book* offerBook, int size) {
		for (int i = 0; i < size; i++) {
		  cout << i + 1 << ",";
	  	cout << offerBook[i].value<< ",";
		
		if(i == size -1) {
		  cout << offerBook[i].quantity<< "\\";
		} else {
		  cout << offerBook[i].quantity<< "\n";
		}
	}
}

void deleteAt(int position, Book* offerBook, int size) {
        for (int i = position; i < size; i++) {
          offerBook[i - 1] = offerBook[i];
        }
        size--;
}
    
int main(int argc, char *argv[]) {
	int updates;
	int size;
	int position;
	int action;
	
	cout << "Insert the input:  "<< endl;
	cin >> updates;
	size = updates;
	
	Book* offerBook = new Book[updates];
	
	for (int i = 0; i < updates; i++) {
		Book properties;
		
		cin >> position;
		cin.ignore(1, ',');
		cin >> action;
		cin.ignore(1, ',');
		cin >> properties.value;
		cin.ignore(1, ',');
		cin >> properties.quantity;
		
		switch (action) {
		  case 0:
			if(offerBook[position -1].value == 0) {
			  size--;
			}
		    offerBook[position -1] = properties;	
			break;
		case 1:
		  if (properties.value > 0) {
    		offerBook[position - 1].setValue(properties.value);
		  }
          if (properties.quantity > 0) {
    	    offerBook[position - 1].setQuantity(properties.quantity);
		  }
		  size--;
	  	break;
		case 2:
		deleteAt(position, offerBook, size);
			break;
		}
 	}
 	
 	printBooks(offerBook, size);
 	
 	delete[] offerBook;
 	offerBook = nullptr;
 	
 	cin.get();
}
