#include <iostream>

using namespace std;

class Book {
public:
  int position;
  double value;
  int quantity;

  void setValue(double v) { value = v; }
  void setQuantity(int q) { quantity = q; }
};

class List {
public:
  int size;
  Book *offerBook;
};

void inicializeList(List *list) { list->size = 0; }

void printList(List *list) {
  for (int i = 0; i < list->size; i++) {
    if (i == list->size - 1) {
      cout << list->offerBook[i].position << "," << list->offerBook[i].value
           << "," << list->offerBook[i].quantity << "\\" << endl;
    } else {
      cout << list->offerBook[i].position << "," << list->offerBook[i].value
           << "," << list->offerBook[i].quantity << endl;
    }
  }
}

bool insertBook(List *list, Book book, int position) {
  if (position < 0) {
    return false;
  }
  list->size++;
  int index = position - 1;
  for (int i = list->size; i > index; i--) {
    list->offerBook[i] = list->offerBook[i - 1];
    list->offerBook[i].position++;
  }
  list->offerBook[index] = book;
  return true;
}

int searchBook(List *list, int position) {
  int i = 0;
  while (i < list->size) {
    if (list->offerBook[i].position == position) {
      return i;
    }
    i++;
  }
  return -1;
}

bool uptadeBook(List *list, int position, int quantity, double value) {
  int index = searchBook(list, position);
  if (index == -1) {
    return false;
  }
  if (quantity > 0) {
    list->offerBook[index].setQuantity(quantity);
  }
  if (value > 0) {
    list->offerBook[index].setValue(value);
  }
  return true;
}

bool removeBook(List *list, int position) {
  int index = searchBook(list, position);
  if (index == -1) {
    return false;
  }
  for (int i = index; i < list->size - 1; i++) {
    list->offerBook[i] = list->offerBook[i + 1];
    list->offerBook[i].position--;
  }
  list->size--;
  return true;
}

int main(int argc, char *argv[]) {
  int updates;
  int action;

  cout << "Insert the input:  " << endl;
  cin >> updates;

  Book *books = new Book[updates];
  List offerBook;
  offerBook.offerBook = books;
  inicializeList(&offerBook);

  for (int i = 0; i < updates; i++) {
    Book properties;

    cin >> properties.position;
    cin.ignore(1, ',');
    cin >> action;
    cin.ignore(1, ',');
    cin >> properties.value;
    cin.ignore(1, ',');
    cin >> properties.quantity;

    switch (action) {
    case 0:
      insertBook(&offerBook, properties, properties.position);
      break;
    case 1:
      uptadeBook(&offerBook, properties.position, properties.quantity,
                 properties.value);
      break;
    case 2:
      removeBook(&offerBook, properties.position);
      break;
    }
  }

  printList(&offerBook);

  cin.get();
}
