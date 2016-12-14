#include "Server.h"
using namespace Xler;
Server::Server(void) {
	this->conf = 0;
}


Server::~Server(void) {

}

void Server::Set(ServerConf *conf) {
	this->conf = conf;
}

void Server::OnStart(CbStart cb) {
	call_backs.cb_start = cb;
}

void Server::Start(void) {
	call_backs.cb_start(this);
}
