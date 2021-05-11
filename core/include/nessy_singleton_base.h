#ifndef __NESSY_SINGLETON_BASE_H__
#define __NESSY_SINGLETON_BASE_H__


namespace Nessy
{
	class CSingletonManager;


	class CSingletonBase
	{
	     private :
		friend class CSingletonManager;
		virtual void _Kill() = 0;


	     protected :
		virtual ~CSingletonBase();
	};
} // namespace Nessy

#endif //__NESSY_SINGLETON_BASE_H__
