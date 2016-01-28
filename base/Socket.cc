#include "Socket.h"
#include "InetAddress.h"
#include <assert.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
namespace
{
	typedef struct sockaddr SA;
	const SA* sockaddr_cast(const struct sockaddr_in *addr)
	{
		return static_cast<const SA*>(addr);
	}
	SA* sockaddr_cast(struct sockaddr_in *addr)
	{
		return static_cast<SA*>(implicit_cast<void*>(addr));
	}

}
