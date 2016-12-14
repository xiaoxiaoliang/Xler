#pragma once

namespace Xler {
	namespace Base {
		class Stream;

		class StreamQueue {
		public:
			StreamQueue(void);
			virtual ~StreamQueue(void);
			Stream *pop();
			void push(Stream *stream);
		private:
			std::queue<Stream*> queue;
		};
	}
}
