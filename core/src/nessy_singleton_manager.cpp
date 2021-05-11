#include "nessy_singleton_base.h"
#include "nessy_singleton_manager.h"


namespace Nessy
{
	CSingletonManager::CSingletonManager(){}

	CSingletonManager::~CSingletonManager()
	{
		while( !m_InstancesList.empty() )
		{
			m_InstancesList.top()->_Kill();
			m_InstancesList.pop();
		}
	}
} //namespace Nessy
