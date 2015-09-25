#include <DarkCore.hpp>

namespace DarkCore
{
	std::ostream &operator<<(LogComponent &logComponent, const std::string &message)
	{
		return logComponent.LogStream << message << std::endl;
	}

	LogComponent::LogComponent(const std::string &logPath, Container *parent)
		: Component("LogComponent", parent), LogPath(logPath), LogStream(std::ofstream()) {}

	bool LogComponent::Initialize()
	{
		this->LogStream.open(this->LogPath, std::ios::out | std::ios::app);

		*this << "DarkCore Logging Component Initialized";

		return true;
	}

	void LogComponent::Finalize()
	{
		*this << "DarkCore Logging Component Finalized";

		// Maybe find a better place for this:
		// this->LogStream.close();
	}

	void LogComponent::WriteToLog(const std::string &message)
	{
		*this << message;
	}
}
