#ifndef DARKCORE_LOGGING_LOG_COMPONENT_HPP
#define DARKCORE_LOGGING_LOG_COMPONENT_HPP

namespace DarkCore
{
	class LogComponent : public Component
	{
	public:
		DarkCoreAPI LogComponent(const std::string &logPath, const std::string &name = "LogComponent", Container *parent = NULL);

		DarkCoreAPI bool Initialize();
		DarkCoreAPI void Finalize();

		DarkCoreAPI void WriteToLog(const std::string &message);

		DarkCoreAPI friend std::ostream &operator<<(LogComponent &logComponent, const std::string &message);

	protected:
		std::string LogPath;
		std::ofstream LogStream;
	};
}

#endif /* DARKCORE_LOGGING_LOG_COMPONENT_HPP */
