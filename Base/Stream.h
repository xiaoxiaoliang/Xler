#pragma once
namespace Xler {
	namespace Base {
		class Stream {
		public:
			Stream(size_t size);
			virtual ~Stream(void);

			void reset(void);
		private:
			unsigned int fd;
			size_t max_size;//��ǰ���buffer��С
			size_t read_idx;//��ǰ����λ��
			size_t write_idx;//��ǰд��λ��
			unsigned char *buffer;//������������
		};
	}
}