#include <iostream>
using namespace std;

class Vehicle {
private:
	string* brand;
public:
	Vehicle() : brand(new string("TBD")) {}
	Vehicle(string n) :brand(new string(n)) {}
	string getBrand() { return *brand; }
	void setBrand(string n) { brand = (new string(n)); }
	virtual void output() = 0;
	~Vehicle() { delete brand; }
	Vehicle(Vehicle& n) {
		brand = new string(*(n.brand));
	}
	Vehicle& operator=(Vehicle& n) {
		brand = new string(*(n.brand));
		return n;
	}
};

class Car : public Vehicle {
private:
	int* weight;
public:
	Car() :Vehicle(), weight(new int(0)) {}
	Car(string n, int w) :Vehicle(n), weight(new int(w)) {}
	int getWeight() { return *weight; }
	void setWeight(int w) { weight = (new int(w)); }
	void output() override { cout << "Brand: " << getBrand() << " " << "Weight: " << getWeight() << endl; }
	~Car() { delete weight; }
	Car(Car& c) {
		weight = new int(c.getWeight());
	}
	Car& operator=(Car& c) {
		weight = new int(c.getWeight());
		return c;
	}
};

class Boat : public Vehicle {
private:
	int* hullLength;
public:
	Boat() :Vehicle(), hullLength(new int(0)) {}
	Boat(string n, int h) :Vehicle(n), hullLength(new int(h)) {}
	int gethullLength() { return *hullLength; }
	void sethullLength(int h) { hullLength = (new int(h)); }
	void output() override { cout << "Brand: " << getBrand() << " " << "hullLength: " << gethullLength() << endl; }
	~Boat() { delete hullLength; }
	Boat(Boat& b) {
		hullLength = new int(b.gethullLength());
	}
	Boat operator=(Boat& b) {
		hullLength = new int(b.gethullLength());
		return b;
	}
};

int main() {
	Vehicle* a;
	a = new Car("Honda", 2000);
	a->output(); // Brand:Honda Weight: 2000
	a = new Boat("Baja", 100);
	a->output(); // Brand:Baja hullLength: 100
}