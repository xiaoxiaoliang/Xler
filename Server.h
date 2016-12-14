#pragma once
#include "def\Config.h"
#include "def\CallBack.h"
namespace Xler {
	using namespace Def;
	class Server {
	public:
		Server(void);
		virtual ~Server(void);
		void Set(ServerConf *conf);
		void OnStart(CbStart cb);
		void Start(void);
	private:
		ServerConf *conf;
		ServerCallBacks call_backs;
	};
}