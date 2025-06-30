#pragma once
#include "Singleton.h"

template<typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>>
{
	friend Singleton<ResourceMgr<T>>;

protected:
	ResourceMgr() = default;
	virtual ~ResourceMgr()
	{
		for (auto pair : resources)
		{
			delete pair.second;
		}
		resources.clear();
	}

	ResourceMgr(const ResourceMgr&) = delete;
	ResourceMgr* operator=(const ResourceMgr&) = delete;

	std::unordered_map<std::string, T*> resources;

	static T Empty;

public:
	bool Load(const std::string& id)
	{
		auto it = resources.find(id);
		if (it != resources.end())
		{
			return false;
		}

		T* res = new T();
		bool success = res->loadFromFile(id);
		if (!success)
		{
			return false;
		}

		resources.insert({ id,res });
	}
	
	void Load(const std::vector<std::string>& ids)
	{
		for (const auto& id : ids)
		{
			bool success = Load(id);

			if (!success)
			{
				std::cout << "Load 실패" << std::endl;
			}
		}
	}

	bool Unload(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end())
		{
			return false;
		}

		delete it->second;
		resources.erase(it);
		return true;
	}

	void Unload(const std::vector<std::string>& ids)
	{
		for (const auto& id : ids)
		{
			bool success = Unload(id);

			if (!success)
			{
				std::cout << "Unload 실패" << std::endl;
			}
		}
	}

	T& Get(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end())
		{
			return Empty;
		}
		return *(it->second);
	}
};

template<typename T>
T ResourceMgr<T>::Empty;

#define TEXTURE_MGR (ResourceMgr<sf::Texture>::Instance())
#define FONT_MGR (ResourceMgr<sf::Font>::Instance())
#define SOUNDBUFFER_MGR (ResourceMgr<sf::SoundBuffer>::Instance())