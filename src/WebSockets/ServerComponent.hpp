#ifndef DARKCORE_WEBSOCKETS_SERVER_COMPONENT_HPP
#define DARKCORE_WEBSOCKETS_SERVER_COMPONENT_HPP

#ifdef _MSC_VER
#	pragma once
#endif	/* _MSC_VER */

namespace DarkCore
{
	class ServerComponent : public Component
	{
	public:
		DarkCoreAPI ServerComponent(const std::string &name = "ServerComponent", Container *parent = NULL);

		DarkCoreAPI bool Initialize();
		DarkCoreAPI void Finalize();
	};
}

#endif /* DARKCORE_WEBSOCKETS_SERVER_COMPONENT_HPP */
