#include <stdio.h>
#include <stdlib.h>
#include "Server.h"
using namespace Xler;
void OnStart(const Xler::Server *ser) {
	printf("onStart");
}

int main(void) {
	Xler::Def::ServerConf cfg;
	cfg.net_lisen.push_back(NetProSet(Def::NPT_TCP, "127.0.0.1", 8001));
	cfg.net_lisen.push_back(NetProSet(Def::NPT_TCP, "127.0.0.1", 8002));
	cfg.net_lisen.push_back(NetProSet(Def::NPT_TCP, "127.0.0.1", 8003));
	Xler::Server *ser = new Xler::Server();
	ser->on_start(OnStart);
	ser->set(&cfg);
	ser->start();
	return 0;
}
