#include <sstream>
#include <iostream>
#include <cstdarg>
#include "nessy_logger.h"


namespace Nessy
{
	//------------------------------ ILogger interface ---------------------------------
	ILogger::~ILogger(){}

	void ILogger::Log( const char * Format, ... )
	{
		char sBuffer[512];

		va_list Params;
		va_start(Params, Format);
		vsprintf(sBuffer, Format, Params);
		va_end(Params);

		Write(sBuffer);
	}

	std::string ILogger::CurrentDate() const
	{
		char sTime[24];

		time_t CurrentTime = time(NULL);
		strftime(sTime, sizeof(sTime), "%d/%m/%Y", localtime(&CurrentTime));

		return sTime;
	}

	std::string ILogger::CurrentTime() const
	{
		char sTime[24];

		time_t CurrentTime = time(NULL);
		strftime(sTime, sizeof(sTime), "%H:%M:%S", localtime(&CurrentTime));

		return sTime;
	}

	//------------------------------- CFileLogger class --------------------------------
	CFileLogger::CFileLogger() : m_FileName("output.log"), m_File(m_FileName.c_str())
	{
		if( m_File )
		{
			m_File << "---------------------------------" << std::endl;
			m_File << "| Start - " << CurrentDate() << " @ " << CurrentTime() << " |" << std::endl;
			m_File << "---------------------------------" << std::endl << std::endl;
		}
	}

	CFileLogger::~CFileLogger()
	{
		if( m_File )
		{
			m_File << "---------------------------------" << std::endl;
			m_File << "| End - " << CurrentDate() << " @ " << CurrentTime() << "   |" << std::endl;
			m_File << "---------------------------------" << std::endl;

			m_File.close();
		}
	}

	void CFileLogger::SetFileName( const std::string & FileName )
	{
		m_FileName = FileName;
	}

	void CFileLogger::Write( const std::string & Message )
	{
		if( m_File )
			m_File << Message << std::flush;
	}

	//------------------------------ CScreenLogger class -------------------------------
	CScreenLogger::CScreenLogger(){}

	CScreenLogger::~CScreenLogger(){}

	void CScreenLogger::Write( const std::string & Message )
	{
		std::cout << Message;
	}
} //namespace Nessy
