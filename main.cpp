#include <stdio.h>
#include <stdlib.h>
#include "Server.h"
using namespace Xler;
void OnStart(const Xler::Server *ser) {
	printf("onStart");
}

class TestServer {
public:
	void OnStart(const Xler::Server *ser) {
		printf("TestServer onStart");
	}
};

int main(void) {
	Xler::Def::ServerConf cfg;
	cfg.net_listen.push_back(NetProSet(Def::NPT_TCP, "127.0.0.1", 8001));
	cfg.net_listen.push_back(NetProSet(Def::NPT_TCP, "127.0.0.1", 8002));
	cfg.net_listen.push_back(NetProSet(Def::NPT_TCP, "127.0.0.1", 8003));
	Xler::Server *ser = new Xler::Server();
	//TestServer *test = new TestServer();
	//ser->on_start(ON_START(TestServer::OnStart,test));
	ser->set(&cfg);
	ser->start();
	return 0;
}
