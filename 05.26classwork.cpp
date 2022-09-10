class B {
	int *value;
public:
	B(int *&value) {
		this->value = value;
	}
	B(int *&&value) {
		this->value = new int(*value);
		delete value;
	}
	~B() {
		if (this->value)
			delete this->value;
	}
	int getValue() {
		return *this->value;
	}

	/*B operator=(B &b) {
		this->value = b.value;
		return *this;
	}*/

	B* operator=(B *&b) {
		this->value = b->value;
		return this;
	}
	/*B operator=(B &&b) {
		this->value = b.value;
		return *this;
	}*/

	B* operator=(B *&&b) {
		this->value = b->value;
		delete b;
		return this;
	}
};

#include <iostream>
using namespace std;

int main() {
	int i { };
	while (1) {
		B bb(new int(++i));
		cout << bb.getValue() << endl;
	}
	return 0;
}
