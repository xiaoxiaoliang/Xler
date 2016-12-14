#pragma once

#ifndef _WIN32
#define xl_pthread_t pthread_t;			
#else
#define xl_pthread_t HANDLE;
#endif