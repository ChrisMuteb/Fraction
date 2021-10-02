/*
* Date: 30 Sept. 2021
* Author: Chris Muteb
* Chapter 8--Project: Fractoin.cpp
*/
#include<iostream>

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;
	int wholeNumber;
public:
	Fraction(int num = 0, int denom = 1) {
		this->wholeNumber = 0;
		this->numerator = num;
		this->denominator = denom;
	}
	Fraction(int wholeNum, int num, int denom = 1) {
		this->wholeNumber = wholeNum;
		this->numerator = num;
		this->denominator = denom;
	}
	void reduceFraction() {
		if (numerator > denominator) {// reason: determine how far should the for-loop go
			for (int x = 2; x < numerator; x++) {
				if (((numerator % x) == 0) && ((denominator % x) == 0)) {// Find the multiple of the fraction
					numerator = numerator / x;
					denominator = denominator / x;

					if (numerator % denominator != 0) {//To simplify further again the fraction
						//displayFraction(oneFraction);//1 9/4
						wholeNumber = wholeNumber + (numerator / denominator);
						numerator = numerator % denominator;
						//cout << "Am I being called?" 

					}
					break;
				}

			}
			//displayFraction(frac, sz);
		}
		else if (numerator < denominator) {
			for (int x = 2; x < denominator; x++) {
				if (((numerator % x) == 0) && ((denominator % x) == 0)) {// Find the multiple of the fraction
					numerator = numerator / x;
					denominator = denominator / x;

					/*if (oneFraction.numerator % oneFraction.denominator != 0) {
						oneFraction.numerator = oneFraction.numerator % oneFraction.denominator;
						oneFraction.wholeNumber = oneFraction.wholeNumber + (oneFraction.numerator / oneFraction.denominator);
					}*/
					break;
				}
			}
			//displayFraction(frac, sz);
		}
		else if (numerator == denominator) {
			wholeNumber = wholeNumber + 1;
			//displayFraction(frac, sz);
		}
	}
	void displayFraction() {
		if ((wholeNumber == 0) && (denominator != numerator))
			cout << numerator << "/" << denominator << " ";
		else if (denominator == numerator)
			cout << wholeNumber << endl;
		else
			cout << wholeNumber << " " << numerator << "/" << denominator << " ";
	}
	void setFraction(int num = 0, int denom = 1) {
		this->wholeNumber = 0;
		this->numerator = num;
		this->denominator = denom;
	}
	void setWholeNumber(int wholeNum) { this->wholeNumber = wholeNum; }
	int getNumerator() { return numerator; }
	int getDenominator() { return denominator; }
	int getWholeNumber() { return wholeNumber; }
};

class MathProblem {
private:
	Fraction firstFraction;
	Fraction secondFraction;
	Fraction userFraction;
	Fraction correctFraction;
	char anOperator; // + or *
	bool isAnswerCorrect; // Indicate whether the user entered the correct answer.
public:
	void setProblem(int firstFNum, int firstFDenom, int secondFNum, int secondFDenom, char op){
		
		anOperator = op;
		isAnswerCorrect = false;
		userFraction = 0;
		firstFraction.setFraction(firstFNum, firstFDenom);
		secondFraction.setFraction(secondFNum, secondFDenom);

		
		int denom, num, wholeNum;
		switch (anOperator)
		{
		case '+':
			if (secondFraction.getDenominator() == firstFraction.getDenominator()) {
				denom = firstFraction.getDenominator();
				num = firstFraction.getNumerator() + secondFraction.getNumerator();
				correctFraction.setFraction(num, denom);
				correctFraction.reduceFraction();

				//cout << "sum of the correct fraction: " <<  correctFraction.getNumerator() << "/" << correctFraction.getDenominator() << endl;
				//cout << "-------------------" << endl;
				
				correctFraction.displayFraction();
			}
			else {
				denom = firstFraction.getDenominator() * secondFraction.getDenominator();
				num = (firstFraction.getNumerator() * secondFraction.getDenominator()) + (secondFraction.getNumerator() * firstFraction.getDenominator());
				//cout << "Sum of fraction one and two gives: " << threeFraction.numerator << "/" << threeFraction.denominator << endl;
				correctFraction.setFraction(num, denom);
				
				correctFraction.reduceFraction();
				//correctFraction.displayFraction();
				
			}
			break;
		case '*':
			denom = firstFraction.getDenominator() * secondFraction.getDenominator();
			num = firstFraction.getNumerator() * secondFraction.getNumerator();
			correctFraction.setFraction(num, denom);

			if (correctFraction.getNumerator() % correctFraction.getDenominator() == 0) {

				if (correctFraction.getNumerator() % correctFraction.getDenominator() != 0)
					wholeNum = correctFraction.getNumerator() / correctFraction.getDenominator();
				//cout << " Mul of fraction one and two gives: " << threeFraction.wholeNumber << endl;
				correctFraction.setWholeNumber(wholeNum);

				correctFraction.reduceFraction();
				//correctFraction.displayFraction();
			}
			else {
				correctFraction.reduceFraction();
				//correctFraction.displayFraction();
			}
			break;
		}

	}
	void displayProblem() {
		cout << firstFraction.getNumerator() << "/" << firstFraction.getDenominator() << " " <<
			anOperator << " " << secondFraction.getNumerator() << "/" << secondFraction.getDenominator() << " = ?" << endl;
	}
	bool askUserForAnswer() {
		int num = 0, denom = 0, i;

		cout << "Enter the answer's numerator: ";
		cin >> num;
		cout << "Enter the answer's denominator: ";
		cin >> denom;
		userFraction.setFraction(num, denom);
		userFraction.reduceFraction();
		//userFraction.displayFraction();
		cout << "-------------" << endl;
		correctFraction.reduceFraction();
		//correctFraction.displayFraction();

		if (userFraction.getNumerator() == correctFraction.getNumerator() &&
				userFraction.getDenominator() == correctFraction.getDenominator() &&
				userFraction.getWholeNumber() == correctFraction.getWholeNumber()) {
			isAnswerCorrect = true;
			cout << "Correct!" << endl;
		}
			
		return isAnswerCorrect;
	}
	void displayProblemWithAnswer() {
		cout << firstFraction.getNumerator() << "/" << firstFraction.getDenominator() << " " <<
			anOperator << " " << secondFraction.getNumerator() << "/" << secondFraction.getDenominator() << " = " <<
			userFraction.getNumerator() << "/" << userFraction.getDenominator() << endl;
	}
};
const int SIZE = 5;
int main() {

	/*declares five MathProblem objects you can use to test a student’s
fraction arithmetic skills. Assign values to the MathProblems. Display the problems and
accept the answers. When the five problems are completed, display each of the problems,
along with the student’s answer, the correct answer, and a message indicating whether the
student is right or wrong. Finally, show the student a score indicating the percentage of
problems answered correctly.*/
	MathProblem aMath, bMath, cMath, dMath, eMath;
	int point = 0;
	bool a, b, c;

	aMath.setProblem(1, 2, 1, 4, '+');
	aMath.displayProblem();
	a = aMath.askUserForAnswer();
	aMath.displayProblemWithAnswer();

	bMath.setProblem(1, 3, 2, 3, '*');
	bMath.displayProblem();
	b = bMath.askUserForAnswer();
	bMath.displayProblemWithAnswer();

	cMath.setProblem(3, 4, 1, 2, '+');
	cMath.displayProblem();
	c = cMath.askUserForAnswer();
	cMath.displayProblemWithAnswer();
	
	if (a == true)
		point++;
	if (b == true)
		point++;
	if (c == true)
		point++;
	
	cout << "Score: " << point * 100 / 3 << endl;
	
	return 0;
}