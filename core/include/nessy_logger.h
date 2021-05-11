#ifndef __NESSY_LOGGER_H__
#define __NESSY_LOGGER_H__

#include <string>
#include <fstream>
#include "nessy_singleton.h"


namespace Nessy
{
	class ILogger
	{
	     protected :
		virtual ~ILogger();

		void Log( const char * Format, ... );
		std::string CurrentDate() const;
		std::string CurrentTime() const;
		virtual void Write( const std::string & Message ) = 0;
	};

	class CFileLogger : public CSingleton<CFileLogger>, public ILogger
	{
	     private :
		friend class CSingleton<CFileLogger>;

		std::string m_FileName;
		std::ofstream m_File;

		CFileLogger();
		virtual ~CFileLogger();

		void SetFileName( const std::string & FileName );


	     public :
		virtual void Write( const std::string & Message );
	};

	class CScreenLogger : public CSingleton<CScreenLogger>, public ILogger
	{
	     private :
		friend class CSingleton<CScreenLogger>;

		CScreenLogger();
		virtual ~CScreenLogger();


	     public :
		virtual void Write( const std::string & Message );
	};
} //namespace Nessy

#endif //__NESSY_LOGGER_H__
