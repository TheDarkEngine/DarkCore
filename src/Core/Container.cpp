#include <DarkCore.hpp>

namespace DarkCore
{
	Container::Container(std::initializer_list<Component *> components)
		: Components(components)
	{
		for (auto i : this->Components)
			if (i)
				i->Parent = this;
	}

	Container::~Container()
	{
		this->Finalize();
	}

	bool Container::Initialize()
	{
		for (auto i : this->Components)
			if (i && !i->Initialize())
				return false;

		return true;
	}

	void Container::Finalize()
	{
		for (auto i = this->Components.rbegin(); i != this->Components.rend(); i++)
			if (*i)
				(*i)->Finalize();
	}
}
