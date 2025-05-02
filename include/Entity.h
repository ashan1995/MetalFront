#include <iostream>
#include <tuple>

class Entity
{
	std::tuple<int> m_components;
	size_t m_id = 0;
	bool m_alive = true;

public:
	Entity();

	template <typename T>
	T& get()
	{
		return std::get<T>(m_components);
	}

	/*template <typename T>
	T& has()
	{
		return std::get<T>().exists;
	}*/

	template <typename T>
	void remove()
	{
		std::get<T>() = T();
	}

	template <typename T, typename... TArgs>
	T& add(TArgs&& mArgs)
	{
		auto& component = get<T>();
		component = T(std::forward<TArgs>(mArgs)...);
		//component.exist = true;
		return component;

	}


};