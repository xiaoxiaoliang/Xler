#pragma once
#include <list>
#include "../Def/Config.h"
namespace Xler {
	class Server;
	namespace Net {
		class Listener {
		public:
			static Listener* getInstance() {
				if (instance == NULL)
					instance = new Listener();
				return instance;
			}
			void create(Server *ser);
			int add_listen(const Def::NetProSet &set);
		private:
			Listener();
			virtual ~Listener();
			int listen_tcp(const Def::NetProSet &set);
			int listen_udp(const Def::NetProSet &set);

			static Listener *instance;
			Server *ser;
			std::list<int> tcp_fd;
			std::list<int> udp_fd;
		};

#define LISTENER Listener::getInstance()
	}
}
