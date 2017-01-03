#pragma once
#include <queue>
#include <semaphore.h>
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
			std::queue<Stream*> queue; //数据流队列
			sem_t m_sem;	//信号量
			pthread_mutex_t m_mutex; //互斥锁
		};
	}
}
