#include "USLogger.h"

namespace UnderScore::Engine::Logger
{
	USLogger& USLogger::GetInstance()
	{
		static USLogger logger;
		return logger;
	}

	void USLogger::logError(const char* errorTxt)
	{
		this->logText(errorTxt, USLoggerTypes::Error);
	}

	void USLogger::logInfo(const char* infoTxt)
	{
		this->logText(infoTxt, USLoggerTypes::Info);

	}
	void USLogger::logWarning(const char* warningTxt)
	{
		this->logText(warningTxt, USLoggerTypes::Warning);

	}
	void USLogger::logDebug(const char* warningTxt)
	{
		this->logText(warningTxt, USLoggerTypes::Debug);

	}

	void write(std::string txt)
	{
		auto path = std::filesystem::current_path().string() + "\\logs\\";
		if (!std::filesystem::is_directory(path) || !std::filesystem::exists(path)) { // Check if src folder exists
			std::filesystem::create_directory(path); // create src folder
		}

		auto pathLog = path + "log_" + UnderScore::Engine::Helpers::USHelper_GetCurrentDate() + ".txt";
		const char* logPath = path.c_str();
		std::fstream logFile = std::fstream(logPath, std::ios::app);
		logFile << txt;
		logFile.close();
	}

	void USLogger::logText(const char* txt, USLoggerTypes type)
	{
		std::string logFile;
		switch (type)
		{
		case USLoggerTypes::Info:
			logFile += UnderScore::Engine::Helpers::USHelper_GetCurrentDateAndTime() +" Info: " + txt + "\n";
			break;
		case USLoggerTypes::Warning:
			logFile += UnderScore::Engine::Helpers::USHelper_GetCurrentDateAndTime() + " Warning: " + txt + "\n";
			break;
		case USLoggerTypes::Error:
			logFile += UnderScore::Engine::Helpers::USHelper_GetCurrentDateAndTime() + " Error: " + txt + "\n";
			break;
		case USLoggerTypes::Debug:
			logFile += UnderScore::Engine::Helpers::USHelper_GetCurrentDateAndTime() + " Debug: " + txt + "\n";
			break;
		default:
			break;
		}

		std::thread logThread = std::thread(&write, logFile);
		logThread.detach();
	}
}
