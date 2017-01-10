#pragma once
#include <stdint.h>
#include <string>
#include <vector>
namespace Xler {
	namespace Def {
		enum NetProType {
			NPT_TCP,
			NPT_UDP,
		};
		struct NetProSet {
			NetProSet(NetProType type, const char* ip, uint16_t port) {
				this->type = type; this->ip.assign(ip); this->port = port;
			}
			NetProType type;
			std::string ip;
			uint16_t port;
		};
		typedef std::vector<NetProSet> NetProSetVec;
		struct ServerConf {
			int rec_num;
			NetProSetVec net_listen;
			ServerConf(void) {
				rec_num = 1;
				net_listen.clear();
			}
		};
	}
}
