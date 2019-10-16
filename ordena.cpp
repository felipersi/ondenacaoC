#include <iostream>

using namespace std;


int main() {

	setlocale(LC_ALL, "portuguese");


	int num1, num2, parT, impT, posT, negT;
	float num3, num4;
	
	cout << "Digite dois valores inteiros: " << endl;
	cin >> num1;
	cin >> num2;

	cout << "Digite dois valores decimais: " << endl;
	cin >> num3;
	cin >> num4;
	
	
	float men1, men2, men3;
	
	if (num1 < num2){
		men1 = num1;
		men2 = num2;
	}
	else {
		men1 = num2;
		men2 = num1;
	}
	if (num3 < men1){
		men1 = num3;
		if (num1 < num2){
			men2 = num1;
			men3 = num2;
		}
		else {
			men2 = num2;
			men3 = num1;
		}
	}
	else{
		if(num3 < men2){
			men2 = num3;
			if (num1 < num2){
				men1 = num1;
				men3 = num2;
			}
			else {
				men1 = num2;
				men3 = num1;
			}
		}
		else {
			if ( num3 > men2 ){
				men3 = num3;
				if (num1 < num2){
					men1 = num1;
					men2 = num2;
				}
				else {
					men1 = num2;
					men2 = num1;
				}
			}
		
		}
	}
	
	
	cout << "Segue abaixo os números em ordem crescente : " << endl << endl;

	
	if (num4 < men1){
		cout << num4 << endl;
		cout << men1 << endl;
		cout << men2 << endl;
		cout << men3 << endl;
	}
	else {
		if(num4 < men2){
			cout << men1 << endl;
			cout << num4 << endl;
			cout << men2 << endl;
			cout << men3 << endl;
		}
		else {
			if(num4 < men3){
				cout << men1 << endl;
				cout << men2 << endl;
				cout << num4 << endl;
				cout << men3 << endl;
			}
			else{
				cout << men1 << endl;
				cout << men2 << endl;
				cout << men3 << endl;
				cout << num4 << endl;
			}
		}
	}
	
	parT = 0;
	impT = 0;
	
	if(num1 % 2 == 0 ){
		parT = parT + 1;
	}
	else {
		impT = impT + 1;
	}
	if(num2 % 2 == 0){
		parT = parT + 1;
	}
	else {
		impT = impT + 1;
	}	
	if ((int)num3 % 2 == 0){
		parT = parT + 1;
	}
	else {
		impT = impT + 1;
	}	
	if((int)num4 % 2 == 0){
		parT = parT + 1;
	}
	else {
		impT = impT + 1;
	}
	
	posT = 0;
	negT = 0;
	
	if(num1 >= 0){
		posT = posT + 1;
	}
	else {
		negT = negT + 1;
	}
	if(num2 >= 0){
		posT = posT + 1;
	}
	else {
		negT = negT + 1;
	}
	if(num3 >= 0){
		posT = posT + 1;
	}
	else {
		negT = negT + 1;
	}
	if(num4 >= 0){
		posT = posT + 1;
	}
	else {
		negT = negT + 1;
	}
	
	cout << "Total de números positivos é: " << posT << endl;
	cout << "Total de números negativos é: " << negT << endl;
	cout << "Total de números impares é : " << impT << endl;
	cout << "Total de números pares é : " << parT << endl;

	system("pause"); 
	
	return 0;
}