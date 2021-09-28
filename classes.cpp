#include<iostream>

using namespace std;

// Declaration
class Carpet{
	private:
		int length;
		int width;
		double price;
		void setPrice();
	public:
		int getLength();
		int getWidth();
		double getPrice();
		void setLength(int);
		void setWidth(int);
};
// Implementation
int Carpet::getLenth(){
	retun length;
}
int Carpet::getWidth(){
	return width;
}
double Carpet::getPrice(){
	return price;
}
void Carpet::setLength(int len){
	length = len;
	setPrice();
}
void Carpet::setWidth(int wid){
	width = wid;
	setPrice();
}
void Carpet::setPrice(){
	const int SMALL = 12;
	const int MED = 24;
	const double PRICE1 = 29.99;
	const double PRICE2 = 59.99;
	const double PRICE3 = 89.99;
	int area = length * width;
}
int main(void){
	
	
	return 0;
}
