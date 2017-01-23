#pragma once
#include "../Def/StdType.h"
#include "../Def/Config.h"
#include "../Base/Thread.h"
namespace Xler {
	class Server;
	namespace Net {
		class Listener : public Base::Thread {
		public:
			static Listener* getInstance() {
				if (instance == NULL)
					instance = new Listener();
				return instance;
			}
			void create(Server *ser);
			int add_listen(const Def::NetProSet &set);
			virtual void run(void);
		private:
			Listener();
			virtual ~Listener();
			int listen_tcp(const Def::NetProSet &set);
			int listen_udp(const Def::NetProSet &set);

			static Listener *instance;
			Server *ser;
			StdIntList tcp_fd;
			StdIntList udp_fd;
			int epoll_fd;
		};

#define LISTENER Listener::getInstance()
	}
}
