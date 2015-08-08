#include <iostream>
#include <cstdlib>

#include <unistd.h>
#include <signal.h>

#include <wiringPi.h>

using namespace std;

void reset(int s) {
	exit(0);
}

void isr() {
	cout << "isr" << endl;
}


int main(int argc, char *argv[]) {
	if (wiringPiSetup()) {
		cout << "Error happens when initialize GPIO" << endl;
	}

	if (SIG_ERR == signal(SIGINT, reset)) {
		cout << "Error set reset function" << endl;
	}

	wiringPiISR(2, INT_EDGE_FALLING, isr);

	while (true) {
		usleep(1000);
	}

	return 0;
}
