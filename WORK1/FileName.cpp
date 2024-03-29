#include<iostream>
using namespace std;

char x[17];

char K[33];
char Kr[6][17];

char y[17];
char u[17];
char v[17];

int binary4Toint(char* s) {
	int a = 0;
	int power = 8;
	for (int i = 0; i != 4; i++) {
		a += (s[i] - '0') * power;
		power /= 2;
	}
	return a;
}

void intTobinary4(char* s, int n) {

	for (int i = 0; i != 4; i++)
	{
		s[3 - i] = n % 2 + 48;
		n /= 2;
	}
}

char disTo1(char a, char b) {
	int a1 = a - 48;
	int a2 = b - 48;
	char c = (a1 + a2) % 2 + 48;
	return c;
}

void CreateKr(int n) {
	for (int r = 1; r != n + 1; r++)
		for (int i = 1; i != 17; i++)
			Kr[r][i] = K[4 * r - 3 + i - 1];
}


int main() {
	cin >> x;
	for (int i = 0; i < 16; i++)
		x[16 - i] = x[15 - i];

	cin >> K;
	for (int i = 0; i < 32; i++)
		K[32 - i] = K[31 - i];

	//define the S box and P
	int S[16] = { 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7 };
	int P[16] = { 1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16 };

	CreateKr(5);

	for (int i = 1; i != 17; i++)
		y[i] = x[i];

	char temp[4];
	int n = 1;
	while (n < 5) {
		for (int i = 1; i != 17; i++)
			u[i] = disTo1(Kr[n][i], y[i]);

		for (int i = 1; i != 5; i++)
		{
			for (int j = 0; j != 4; j++)
				temp[j] = u[4 * (i - 1) + j + 1];

			int tmp = binary4Toint(temp);
			intTobinary4(temp, S[tmp]);

			for (int j = 0; j != 4; j++)
				v[4 * (i - 1) + j + 1] = temp[j];
		}
	

		if(n!=4){
	    for (int i = 1; i != 17; i++)
			 y[P[i - 1]] = v[i];
		}
		n++;

	}
	
	for (int i = 1; i != 17; i++)
		y[i] = disTo1(Kr[5][i], v[i]);
	

	for (int i = 1; i != 17; i++)
	{
		//if (i % 4 == 0&&(i!=16))
			//cout << y[i] << " ";
		//else
			cout << y[i];
	}
}