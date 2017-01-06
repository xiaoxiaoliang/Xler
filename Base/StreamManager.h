#pragma once
#include <list>
#include <set>
namespace Xler {
	namespace Base {
		class Stream;
		typedef std::list<Stream*> Stream_List;
		typedef std::set<Stream*> Stream_Set;
		class StreamManager {
		public:
			static StreamManager* getInstance() {
				if (instance == NULL)
					instance = new StreamManager();
				return instance;
			}
			Stream* get();
			void put(Stream* stream);
		private:
			StreamManager(void);
			virtual ~StreamManager(void);
			static StreamManager *instance;
			Stream_Set using_list;
			Stream_List idle_list;
			size_t max_idle;//最大空闲水位
			pthread_mutex_t m_mutex; //互斥锁
		};
#define STREAMMANAGER StreamManager::getInstance()
	}
}
