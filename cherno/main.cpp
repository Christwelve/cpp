// #include "header.hpp"
#include <iostream>

class Log 
{
	private:
		int m_LogLevel;

	public:
		void SetLevel(int level)
		{

		}
		void Warn(const char* message)
		{
			
		}

};

int main()
{
	Log log;
	log.SetLevel(1);
	log.Warn("Hello!");

	std::cin.get();
	return 0;
}
