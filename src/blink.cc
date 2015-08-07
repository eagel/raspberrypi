#include <iostream>

#include <unistd.h>

#include <wiringPi.h>

using namespace std;

int main(int argc, char *argv[]) {
	if (wiringPiSetup()) {
		cout << "Error happens when initialize GPIO" << endl;
	}

	pinMode(0, OUTPUT);

	while (true) {
		digitalWrite(0, HIGH);
		usleep(500000);
		digitalWrite(0, LOW);
		usleep(500000);
	}

	return 0;
}
