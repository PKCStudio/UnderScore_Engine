#include <fstream>
#include <filesystem>
#include <thread>
#include <string>

#include "USLoggerTypes.h"
#include "../USHelpers/USHelpers.h"

#ifndef USLogger_HEADER
#define USLogger_HEADER
namespace UnderScore::Engine::Logger
{
	class USLogger
	{

	public:
		static USLogger& GetInstance();

		void logError(const char* errorTxt);
		void logInfo(const char* infoTxt);
		void logWarning(const char* warningTxt);
		void logDebug(const char* warningTxt);


	private:
		void logText(const char* txt, USLoggerTypes type);
	};

}

#endif