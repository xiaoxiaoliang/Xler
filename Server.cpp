#include "Server.h"
#include "Net/Listener.h"
#include "Net/NetWorker.h"
using namespace Xler;
Server::Server(void) {
	status = INITING;
}


Server::~Server(void) {

}

void Server::set(const ServerConf *conf) {
	memcpy((void *)&this->conf, (void *)conf, sizeof(ServerConf));
}

int Server::add_listen(const Def::NetProType type,const char* ip,const uint16_t port) {
	if(status == INITING) {
		return Net::LISTENER->add_listen(Def::NetProSet(type, ip, port));
	}
	return -1;
}

void Server::on_start(CbStart cb) {
	call_backs.cb_start = cb;
	call_backs.reg.reg_start = 1;
}

void Server::on_receive(void) {

}

void Server::start(void) {
	Net::LISTENER->create(this);
	Net::NETWORKER->start(this);
	if(call_backs.reg.reg_start) {
		call_backs.cb_start(this);
	}
	status = RUNNING;
	Net::NETWORKER->run();
}

void Server::receive(Base::Stream *data) {

}

const ServerConf* Server::get_conf(void) {
	return &this->conf;
}
