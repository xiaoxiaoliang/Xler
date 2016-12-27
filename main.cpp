#include <stdio.h>
#include <stdlib.h>
#include "Server.h"

void OnStart(const Xler::Server *ser) {
	printf("onStart");
}

int main(void) {
	Xler::Server *ser = new Xler::Server();
	ser->on_start(OnStart);
	ser->start();
	return 0;
}
