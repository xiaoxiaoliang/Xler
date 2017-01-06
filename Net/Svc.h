#pragma once
namespace Xler {
	namespace Net {

		class Svc {
		public:
			Svc();
			virtual ~Svc();
		private:
			unsigned int fd;
		};

	}
}
