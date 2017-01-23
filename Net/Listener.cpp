#include <cstddef>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include "Listener.h"
#include "../Server.h"

using namespace Xler::Net;
Listener* Listener::instance = NULL;
Listener::Listener() {
	ser = 0;
	tcp_fd.clear();
	udp_fd.clear();
	epoll_fd = 0;
}

Listener::~Listener() {
}

void Listener::create(Server *ser) {
	const ServerConf *conf = ser->get_conf();
	for(Def::NetProSetVec::const_iterator it = conf->net_listen.begin();
			it != conf->net_listen.end(); ++it) {
		add_listen(*it);
	}
	//init epoll
	epoll_fd = epoll_create(this->tcp_fd.size()+this->udp_fd.size());
	//add all listen fd to epll
	struct epoll_event ev;
	ev.events=EPOLLIN|EPOLLET;
	for(StdIntList::const_iterator it = this->tcp_fd.begin();
			it != this->tcp_fd.end(); ++it) {
		ev.data.fd = *it;
		epoll_ctl(epoll_fd, EPOLL_CTL_ADD, *it, &ev);
	}
	for(StdIntList::const_iterator it = this->udp_fd.begin();
			it != this->udp_fd.end(); ++it) {
		ev.data.fd = *it;
		epoll_ctl(epoll_fd, EPOLL_CTL_ADD, *it, &ev);
	}
	start();
}

int Listener::add_listen(const Def::NetProSet &set) {
	switch(set.type) {
		case NPT_TCP: {
			return listen_tcp(set);
			break;
		};
		case NPT_UDP: {
			return listen_udp(set);
			break;
		};
	}
	return -1;
}

int Listener::listen_tcp(const Def::NetProSet &set) {
	int tcp_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(tcp_fd == -1) return -1;
	/*sockaddr_in结构体相关参数*/
	struct sockaddr_in sockaddr;
	memset(&sockaddr,0,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	//sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_pton(AF_INET,set.ip.c_str(),&sockaddr.sin_addr);
	sockaddr.sin_port = htons(set.port);
	if(bind(tcp_fd,(struct sockaddr *) &sockaddr,sizeof(sockaddr)) == -1) return -1;
	if(listen(tcp_fd,1024) == -1) return -1;
	this->tcp_fd.push_back(tcp_fd);
	return tcp_fd;
}

int Listener::listen_udp(const Def::NetProSet &set) {
	return true;
}

void Listener::run(void) {
	int fd_num = this->tcp_fd.size()+this->udp_fd.size();
	struct epoll_event events[fd_num];
	struct sockaddr_in clientaddr;
	socklen_t clilen;
	while(true) {
		int nfds = epoll_wait(epoll_fd,events,fd_num, -1);
		for(int i=0; i < nfds; ++i) {
			int connfd = accept(events[i].data.fd,(sockaddr *)&clientaddr, &clilen);
			if(connfd < 0) {
				 perror("connfd < 0");
				 abort();
			}
			char *str = inet_ntoa(clientaddr.sin_addr);
			printf("%s", str);
		}
	}
}
