#ifndef __NESSY_SINGLETON_H__
#define __NESSY_SINGLETON_H__

#include "nessy_singleton_base.h"
#include "nessy_singleton_manager.h"


namespace Nessy
{
	template <class T> class CSingleton : public CSingletonBase
	{
	     private :
		static T * m_Instance;

		void _Kill()
		{
			if( m_Instance != NULL )
			{
				delete m_Instance;
				m_Instance = NULL;
			}
		}


	     protected :
		CSingleton(){}
		virtual ~CSingleton(){}


	     public :
		static T * Instance()
		{
			if( !m_Instance )
			{
				m_Instance = new T;
				CSingletonManager::Add(m_Instance);
			}

			return m_Instance;
		}
	};

	template <class T> T * CSingleton<T>::m_Instance = NULL;
} // namespace Nessy

#endif //__NESSY_SINGLETON_H__
