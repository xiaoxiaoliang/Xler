#include <cstddef>
#include "NetWorker.h"
#include "../Server.h"

using namespace Xler::Net;
NetWorker* NetWorker::instance = NULL;
NetWorker::NetWorker() {
	ser = 0;
}

NetWorker::~NetWorker() {

}

void NetWorker::start(Server *ser) {
	this->ser = ser;
	this->run();
}

void NetWorker::run(void) {
	while(true) {
		Base::Stream *data = this->msg_list.pop();
		this->ser->receive(data);
	}
}
