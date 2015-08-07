#include <iostream>

#include <unistd.h>

#include <wiringPi.h>

using namespace std;

int main(int argc, char *argv[]) {
	if (wiringPiSetup()) {
		cout << "Error happens when initialize GPIO" << endl;
	}

	pinMode(1, PWM_OUTPUT);

	while (true) {
		for (int i = 0; i < 1024; ++i) {
			pwmWrite(1, i);
			usleep(1000);
		}

		for (int i = 1022; i >= 0; --i) {
			pwmWrite(1, i);
			usleep(1000);
		}
	}

	return 0;
}
