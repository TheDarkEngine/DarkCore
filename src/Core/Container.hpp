#ifndef DARKCORE_CORE_CONTAINER_HPP
#define DARKCORE_CORE_CONTAINER_HPP

#ifdef _MSC_VER
#	pragma once
#endif /* _MSC_VER */

namespace DarkCore
{
	class Container
	{
	public:
		DarkCoreAPI Container(std::initializer_list<Component *> components = {});
		virtual DarkCoreAPI ~Container();

		virtual DarkCoreAPI bool Initialize();
		virtual DarkCoreAPI void Finalize();

		template<class T> inline T *GetComponent(const std::string &name = "")
		{
			for (auto i : this->Components)
			{
				if (name != "")
				{
					if (i->Name == name)
						return reinterpret_cast<T *>(i);
				}
				else
				{
					T * result = reinterpret_cast<T *>(i);

					if (result)
						return result;
				}
			}

			return NULL;
		}

	protected:
		std::vector<Component *> Components;
	};
}

#endif /* DARKCORE_CORE_CONTAINER_HPP */
