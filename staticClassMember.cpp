#include<iostream>

using namespace std;
// Declaration section
class Student{
	private:
		int idNum;
		
	public:
		const static double athleticFee;
		void setIdNum(int);
		int getIdNum();
		double getAthleticFee();
};
const double Student::athleticFee = 45.25;
void Student::setIdNum(int num){
	idNum = num;
}
int Student::getIdNum(){
	return idNum;
}
double Student::getAthleticFee(){
	return athleticFee;
}
int main(void){
	
	Student aFreshman, aSophomore;
	aFreshman.setIdNum(1234);
	aSophomore.setIdNum(2345);
	cout << "Freshman: " << aFreshman.getIdNum() << " Athletic fee: " << aFreshman.getAthleticFee() << endl;
	cout << "Freshman: " << aSophomore.getIdNum() << " Athletic fee: " << Student::athleticFee << endl;
	return 0;
}
