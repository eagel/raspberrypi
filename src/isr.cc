#include <iostream>
#include <cstdlib>

#include <unistd.h>
#include <signal.h>

#include <wiringPi.h>

using namespace std;

void reset(int s) {
	exit(0);
}

void isr_INT_EDGE_BOTH() {
	cout << "INT_EDGE_BOTH" << endl;
}

void isr_INT_EDGE_FALLING() {
	cout << "INT_EDGE_FALLING" << endl;
}

void isr_EDGE_RISING() {
	cout << "INT_EDGE_RISING" << endl;
}

int main(int argc, char *argv[]) {
	if (wiringPiSetup()) {
		cout << "Error happens when initialize GPIO" << endl;
	}

	if (SIG_ERR == signal(SIGINT, reset)) {
		cout << "Error set reset function" << endl;
	}

	wiringPiISR(2, INT_EDGE_BOTH, isr_INT_EDGE_BOTH);
	wiringPiISR(2, INT_EDGE_FALLING, isr_INT_EDGE_FALLING);
	wiringPiISR(2, INT_EDGE_RISING, isr_EDGE_RISING);

	while (true) {
		usleep(1000);
	}

	return 0;
}
