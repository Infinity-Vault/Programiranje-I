#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const float g = 9.81;
	for (int i = 0, t = 3; i < 20; i++, t += 3)
	{
		cout << "Situacija u " << t << "-oj sekundi je: " << endl;
		cout << "Brzina je: " << g * t << endl;
		cout << "Predjeni put: " << (g / 2) * pow(t, 2);
		cout << "\n";
		cout << "\n";
	}

	cin.get();
	return 0;
}
