#ifndef DARKCORE_WEBSOCKETS_WEBSOCKETS_HPP
#define DARKCORE_WEBSOCKETS_WEBSOCKETS_HPP

#ifdef _MSC_VER
#	pragma once
#endif	/* _MSC_VER */

namespace WebSockets
{
	class Server
	{
	public:
		static DWORD WINAPI Start(LPVOID);
		static void Server::Stop();
	};
}

#endif /* DARKCORE_WEBSOCKETS_WEBSOCKETS_HPP */
