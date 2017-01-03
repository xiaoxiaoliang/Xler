#include "Server.h"
#include "Net/Listener.h"
#include "Net/NetWorker.h"
using namespace Xler;
Server::Server(void) {
	this->conf = 0;
}


Server::~Server(void) {

}

void Server::set(const ServerConf *conf) {
	this->conf = conf;
}

void Server::on_start(CbStart cb) {
	call_backs.cb_start = cb;
}

void Server::start(void) {
	if(this->conf == 0) this->conf = new ServerConf();
	Net::LISTENER->init(this);
	Net::LISTENER->create();
	Net::NETWORKER->start(this);
	call_backs.cb_start(this);
}

void Server::on_receive(void) {

}

void Server::receive(Base::Stream *data) {

}

const ServerConf* Server::get_conf(void) {
	return this->conf;
}
