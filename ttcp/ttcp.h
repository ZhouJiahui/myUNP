#include "../basic/InetAddress.h"
#include "../basic/Socket.h"
#include "../basic/TcpStream.h"
#include "../basic/Acceptor.h"
#include <cstring>
#include <cstdio>
#include <memory>
#include <cstdint>
#include <ctime>
#include <assert.h>

struct Options
{
	int32_t number;
	int32_t length;
};
struct SessionMessage
{
	int32_t number;
	int32_t length;
} __attribute__ ((__packed__));

struct PayLoadMessage
{
	int32_t length;
	char	data[0];
};
