#pragma once
namespace Xler {
	namespace Base {
		class Stream;
		typedef std::list<Stream*> Stream_List;
		typedef std::set<Stream*> Stream_Set;
		class StreamManager {
		public:
			StreamManager(void);
			virtual ~StreamManager(void);
			Stream* get();
			void put(Stream* stream);
		private:
			Stream_Set using_list;
			Stream_List idle_list;
			size_t max_idle;//最大空闲水位
		};
	}
}
