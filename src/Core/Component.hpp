#ifndef DARKCORE_CORE_COMPONENT_HPP
#define DARKCORE_CORE_COMPONENT_HPP

#ifdef _MSC_VER
#	pragma once
#endif /* _MSC_VER */

namespace DarkCore
{
	class Component
	{
		friend class Container;

	protected:
		std::string Name;
		Container *Parent;

	public:
		DarkCoreAPI Component(const std::string &name, Container *parent = NULL);
		virtual DarkCoreAPI ~Component();

		virtual DarkCoreAPI bool Initialize() = 0;
		virtual DarkCoreAPI void Finalize();

		DarkCoreAPI std::string &GetName();
		DarkCoreAPI Container *GetParent();

		template<class T> inline T *GetSibling(const std::string &name = "")
		{
			if (this->Parent == NULL)
				return NULL;

			return this->Parent->GetComponent<T>(name);
		}
	};
}

#endif /* DARKCORE_CORE_COMPONENT_HPP */
