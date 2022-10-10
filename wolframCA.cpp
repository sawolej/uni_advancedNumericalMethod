#include <iostream>

using namespace std;
const int s = 70;
const int rule = 8;

int binToDec(int x);
void in(int(&grid)[s], int(&rules)[rule], int x, int code);
void check(int(&grid)[s], int(&gridTemp)[s], int(&rules)[rule]);
int code(int x);
void sh(int(&grid)[s]);
long long decToBin(int n);

int main() {
	int code = 30, firstCell = 30, n=50, grid[s], gridTemp[s];

	int rules[rule];

	//initialise
	in(grid, rules, firstCell, code);
	sh(grid);	
	//main loop
	while(n){
	check(grid,gridTemp,rules);
	sh(grid);
	n--;
}

}

void in(int(&grid)[s], int(&rules)[rule], int x, int code) {
	code = decToBin(code);
	for (int i = 0; i < s; i++) i == x ? grid[i] = 1 : grid[i] = 0;
	for (int i = 0; i < rule; i++) {
		if (code) {

			code % 10 ? rules[i] = 1 : rules[i] = 0;
			code /= 10;
		}
		else {
			rules[i] = 0;
		}
	}

}

void check(int(&grid)[s], int(&gridTemp)[s], int(&rules)[rule]) {
	for (int i = 0; i < s; i++) {
		if (i == 0) {
			//    grid[i] = code(grid[s - 1] * 100 + grid[i] * 10 + grid[i + 1]);
			gridTemp[i] = rules[binToDec(grid[s - 1] * 100 + grid[i] * 10 + grid[i + 1])];
		}
		else if (i == s - 1) {

			gridTemp[i] = rules[binToDec(grid[i - 1] * 100 + grid[i] * 10 + grid[0])];
		}
		else {
			gridTemp[i] = rules[binToDec(grid[i - 1] * 100 + grid[i] * 10 + grid[i + 1])];
		}
	}
	copy(gridTemp, gridTemp + s, grid);
}
void sh(int(&grid)[s]) {
	for (int i = 0; i < s; i++) grid[i] ? cout << "*" : cout << " ";
	cout << "\n";
}

int binToDec(int n) {
	int dec = 0, i = 0, temp;

	while (n != 0) {
		temp = n % 10;
		n /= 10;
		dec += temp * pow(2, i);
		++i;
	}

	return dec;
}
long long decToBin(int n) {
	long long bin = 0, temp, i = 1;

	while (n != 0) {
		temp = n % 2;
		n /= 2;
		bin += temp * i;
		i *= 10;
	}
	cout << bin << " kek \n";
	return bin;
}