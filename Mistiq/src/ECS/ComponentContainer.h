#pragma once
#include <iostream>
#include <map>

#include "Entity.h"
#include "Component.h"

namespace Mistiq
{
	class BaseComponentContainer
	{
	public:
		BaseComponentContainer() {}
		virtual ~BaseComponentContainer() {}

		virtual bool Remove(Entity& entity) = 0;
	};
	template<class C = Component>
	class ComponentContainer final : public BaseComponentContainer
	{
	public:
		ComponentContainer();
		~ComponentContainer();

	private:
		bool Add(Entity& entity, std::shared_ptr<C> component);
		bool Remove(Entity& entity) override;

		std::shared_ptr<C> Get(Entity& entity);
		std::map<Entity, std::shared_ptr<C>> GetComponents();

	private:
		std::map<Entity, std::shared_ptr<C>> m_Storage;
		unsigned int m_ID;

		friend class ECSManager;
	};

	template <class C>
	ComponentContainer<C>::ComponentContainer()
	{
	}

	template <class C>
	ComponentContainer<C>::~ComponentContainer()
	{
	}

	template <class C>
	bool ComponentContainer<C>::Add(Entity& entity, std::shared_ptr<C> component)
	{
		m_Storage.insert(std::make_pair(entity, component));
		return true;
	}

	template <class C>
	bool ComponentContainer<C>::Remove(Entity& entity)
	{
		auto it = m_Storage.find(entity);
		m_Storage.erase(it);
		return true;
	}

	template <class C>
	std::shared_ptr<C> ComponentContainer<C>::Get(Entity& entity)
	{
		auto it = m_Storage.find(entity);
        if(it == m_Storage.end())
        {
			return nullptr;
        }
		return it->second;
	}

	template <class C>
	std::map<Entity, std::shared_ptr<C>> ComponentContainer<C>::GetComponents()
	{
		return m_Storage;
	}
}