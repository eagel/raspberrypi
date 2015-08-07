#include <iostream>
#include <cstdlib>

#include <unistd.h>
#include <signal.h>

#include <wiringPi.h>

using namespace std;

void reset(int s){
	digitalWrite(0, LOW);
	exit(0);
}

int main(int argc, char *argv[]) {
	if (wiringPiSetup()) {
		cout << "Error happens when initialize GPIO" << endl;
	}

	if(SIG_ERR == signal(SIGINT, reset)){
		cout << "Error set reset function" << endl;
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
