#pragma once
namespace Xler {
	namespace Base {
		class Stream {
		public:
			Stream(size_t size = 1024);
			virtual ~Stream(void);

			void reset(void);
		private:
			unsigned int fd;
			size_t max_size;//当前最大buffer大小
			size_t read_idx;//当前读的位置
			size_t write_idx;//当前写的位置
			unsigned char *buffer;//数据流缓冲区
		};
	}
}
