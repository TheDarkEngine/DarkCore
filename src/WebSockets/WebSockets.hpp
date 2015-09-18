#ifndef DARKCORE_WEBSOCKETS_WEBSOCKETS_HPP
#define DARKCORE_WEBSOCKETS_WEBSOCKETS_HPP

#include "../Platform.hpp"

namespace WebSockets
{
	class Server
	{
	public:
		static DWORD WINAPI Start(LPVOID);
	};
}

#endif /* DARKCORE_WEBSOCKETS_WEBSOCKETS_HPP */
