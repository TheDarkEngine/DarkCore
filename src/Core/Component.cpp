#include <DarkCore.hpp>

namespace DarkCore
{
	Component::Component(const std::string &name, Container *parent)
		: Name(name), Parent(parent) {}

	Component::~Component()
	{
		this->Finalize();
	}

	void Component::Finalize()
	{
		// Empty default method
	}

	std::string &Component::GetName()
	{
		return this->Name;
	}

	Container *Component::GetParent()
	{
		return this->Parent;
	}



}
