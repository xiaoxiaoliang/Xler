#pragma once
#include "def/Config.h"
#include "def/CallBack.h"
namespace Xler {
	using namespace Def;
	class Server {
	public:
		Server(void);
		virtual ~Server(void);
		void set(const ServerConf *conf);
		void on_start(CbStart cb);
		void start(void);
		const ServerConf* get_conf(void);
	private:
		const ServerConf *conf;
		ServerCallBacks call_backs;
	};
}
