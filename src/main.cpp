#include <iostream>
#include <Windows.h>
#include <string>

/// <summary>
/// Prototype 
/// </summary>
/// <returns></returns>
std::string GetTime();

/// <summary>
/// Main
/// </summary>
/// <returns></returns>
int main() 
{
	std::string date = GetTime();

	printf(date.c_str());
}

/// <summary>
/// Get the current time
/// </summary>
/// <returns>return actual time</returns>
std::string GetTime()
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	int year = st.wYear;
	int month = st.wMonth;
	int day = st.wDay;
	int hour = st.wHour;
	int minute = st.wMinute;

	std::string yearS = std::to_string(year);
	yearS += " - ";
	std::string monthS = std::to_string(month);
	monthS += ".";
	std::string dayS = std::to_string(day);
	dayS += ".";
	std::string hourS = std::to_string(hour);
	hourS += "h";
	std::string minuteS = std::to_string(minute);

	std::string startDate = "\n";
	startDate += dayS + monthS + yearS + hourS + minuteS;

	return startDate;
}