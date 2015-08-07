#include <iostream>
#include <cstdlib>

#include <unistd.h>
#include <signal.h>

#include <wiringPi.h>

using namespace std;

void reset(int s) {
	pwmWrite(1, 0);
	exit(0);
}

int main(int argc, char *argv[]) {
	if (wiringPiSetup()) {
		cout << "Error happens when initialize GPIO" << endl;
	}

	if (SIG_ERR == signal(SIGINT, reset)) {
		cout << "Error set reset function" << endl;
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
