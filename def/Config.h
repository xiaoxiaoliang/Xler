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
			NetProType type;
			std::string ip;
			uint16_t port;
		};
		struct ServerConf {
			int rec_num;
			std::vector<NetProSet> net_lisen;
			ServerConf(void) {
				rec_num = 1;
				net_lisen.clear();
			}
		};
	}
}
