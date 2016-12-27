#pragma once
#include "Def/CallBack.h"
#include "Def/Config.h"
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
