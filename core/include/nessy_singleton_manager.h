#ifndef __NESSY_SINGLETON_MANAGER_H__
#define __NESSY_SINGLETON_MANAGER_H__

#include <stack>
#include "nessy_types.h"


namespace Nessy
{
	class CSingletonBase;


	class CSingletonManager
	{
	     private :
		std::stack<CSingletonBase *> m_InstancesList;

		CSingletonManager();
		~CSingletonManager();


	     public :
		static void Add( CSingletonBase * Singleton )
		{
			static CSingletonManager Instance;
			Instance.m_InstancesList.push(Singleton);
		}

		static Integer NumberOfInstances()
		{
			static CSingletonManager Instance;
			return Integer(Instance.m_InstancesList.size());
		}
	};
} // namespace Nessy

#endif //__NESSY_SINGLETON_MANAGER_H__
