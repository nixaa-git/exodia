#pragma once

#include <map>
#include <list>
#include <vector>

class NetAvatar {};

class NetObjectManager
{
public:
	void* vftable;
	std::map<int, NetAvatar> m_netIDMap;
	std::list<void*> m_netObjects;
	std::vector<std::list<void*>> m_objectRenderLayers;
	std::list<void*>::iterator m_iterator;
};