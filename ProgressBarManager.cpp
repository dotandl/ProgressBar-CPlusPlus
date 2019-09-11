/*
 * ========================================
 * [--------ProgressBarManager.cpp--------]
 * ========================================
 * Contains definitions of ProgressBarManager class' methods
 *
 * Created by andl on 2.07.2019
 * Last modified by andl on 7.09.2019
 */

#ifndef _WIN32
# include <termios.h>
# include <unistd.h>
#else
# include <windows.h>
#endif

#include "ProgressBarManager.h"

#include <string>
#include <thread>

namespace ProgressBar
{

bool ProgressBarManager::CheckForColorSupport()
{
#ifndef _WIN32
	const string termEnv = string(getenv("TERM"));

	if (!termEnv.empty())
	{
		const string terms[] =
			{ "xterm", "xterm-256", "xterm-256color","vt100", "color", "ansi", "cygwin", "linux" };
		
		for (const string term : terms)
		{
			if (termEnv == term)
				return true;
		}
	}

	return false;
#else
	return true;
#endif
}

ProgressBarManager::ProgressBarManager() : type(ProgressBarType::classic) { }

ProgressBarManager::ProgressBarManager(ProgressBarType type) : type(type)
{
	if (type == ProgressBarType::color && !this->CheckForColorSupport())
		this->type = ProgressBarType::classic;
}

#pragma region ProgressBar

void ProgressBarManager::SetProgressBar(uint8_t percents, string text)
{
	string progressIndicator = "["; 
	if (percents > 100)
		throw out_of_range("Cannot be more than 100 percents!");
	else if (percents == 0)
		progressIndicator += "--------------------";
	else if (percents >= 1 && percents <= 5)
		progressIndicator += "#-------------------";
	else if (percents >= 6 && percents <= 10)
		progressIndicator += "##------------------";
	else if (percents >= 11 && percents <= 15)
		progressIndicator += "###-----------------";
	else if (percents >= 16 && percents <= 20)
		progressIndicator += "####----------------";
	else if (percents >= 21 && percents <= 25)
		progressIndicator += "#####---------------";
	else if (percents >= 26 && percents <= 30)
		progressIndicator += "######--------------";
	else if (percents >= 31 && percents <= 35)
		progressIndicator += "#######-------------";
	else if (percents >= 36 && percents <= 40)
		progressIndicator += "########------------";
	else if (percents >= 41 && percents <= 45)
		progressIndicator += "#########-----------";
	else if (percents >= 46 && percents <= 50)
		progressIndicator += "##########----------";
	else if (percents >= 51 && percents <= 55)
		progressIndicator += "###########---------";
	else if (percents >= 56 && percents <= 60)
		progressIndicator += "############--------";
	else if (percents >= 61 && percents <= 65)
		progressIndicator += "#############-------";
	else if (percents >= 66 && percents <= 70)
		progressIndicator += "##############------";
	else if (percents >= 71 && percents <= 75)
		progressIndicator += "###############-----";
	else if (percents >= 76 && percents <= 80)
		progressIndicator += "################----";
	else if (percents >= 81 && percents <= 85)
		progressIndicator += "#################---";
	else if (percents >= 86 && percents <= 90)
		progressIndicator += "##################--";
	else if (percents >= 91 && percents <= 95)
		progressIndicator += "###################-";
	else if (percents >= 96 && percents <= 100)
		progressIndicator += "####################";

	progressIndicator += "]";
	string progressBar = text + " " + to_string(percents) + "% " + progressIndicator;

	if (type == ProgressBarType::classic)
	{
		lastProgressBarLength = progressBar.length();
		cout << endl << progressBar;
	}
	else
	{
#ifndef _WIN32
		// Make stdin non-blocking
		// https://stackoverflow.com/questions/8101079/making-stdin-non-blocking
		termios ttystate, ttysave;
		tcgetattr(STDIN_FILENO, &ttystate);
		ttysave = ttystate;
		ttystate.c_lflag &= ~(ICANON | ECHO);
		ttystate.c_cc[VMIN] = 6;
		tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);

		printf("\e[6n");
		int y, x;
		scanf("\e[%d;%dR", &y, &x);

		printf("\e[s\e[999;999H\e[6n\e[u");
		int width;
		scanf("\e[%*d;%dR", &width);

		int startPosition = (width - progressBar.length()) / 2;
		bool parity = (width - progressBar.length()) %2 == 0;
		string finalProgressBar = 
			string(startPosition + (parity ? 0 : 1), ' ') +
			progressBar + 
			string(startPosition, ' ');

		printf("\e[;H\e[30;42m");
		cout << finalProgressBar;
		printf("\e[%d;%dH\e[39;49m", y, x);

		// Restore terminal settings
		tcsetattr(STDIN_FILENO, TCSANOW, &ttysave);
#else
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(console, &bufferInfo);

		COORD xy = bufferInfo.dwCursorPosition;
		WORD colors = bufferInfo.wAttributes;
		int width = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;

		int startPosition = (width - progressBar.length()) / 2;
		bool parity = (width - progressBar.length()) % 2 == 0;
		string finalProgressBar =
			string(startPosition + (parity? 0 : 1), ' ') +
			progressBar +
			string(startPosition, ' ');

		SetConsoleCursorPosition(console, COORD { 0, 0 });
		SetConsoleTextAttribute(console, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
		
		cout << finalProgressBar;

		SetConsoleCursorPosition(console, xy);
		SetConsoleTextAttribute(console, colors);
#endif
	}
	
}

void ProgressBarManager::SetProgressBar(uint8_t percents, string text, string additionalText)
{
	string progressIndicator = "[";

	if (percents > 100)
		throw out_of_range("Cannot be more than 100 percents!");
	else if (percents == 0)
		progressIndicator += "--------------------";
	else if (percents >= 1 && percents <= 5)
		progressIndicator += "#-------------------";
	else if (percents >= 6 && percents <= 10)
		progressIndicator += "##------------------";
	else if (percents >= 11 && percents <= 15)
		progressIndicator += "###-----------------";
	else if (percents >= 16 && percents <= 20)
		progressIndicator += "####----------------";
	else if (percents >= 21 && percents <= 25)
		progressIndicator += "#####---------------";
	else if (percents >= 26 && percents <= 30)
		progressIndicator += "######--------------";
	else if (percents >= 31 && percents <= 35)
		progressIndicator += "#######-------------";
	else if (percents >= 36 && percents <= 40)
		progressIndicator += "########------------";
	else if (percents >= 41 && percents <= 45)
		progressIndicator += "#########-----------";
	else if (percents >= 46 && percents <= 50)
		progressIndicator += "##########----------";
	else if (percents >= 51 && percents <= 55)
		progressIndicator += "###########---------";
	else if (percents >= 56 && percents <= 60)
		progressIndicator += "############--------";
	else if (percents >= 61 && percents <= 65)
		progressIndicator += "#############-------";
	else if (percents >= 66 && percents <= 70)
		progressIndicator += "##############------";
	else if (percents >= 71 && percents <= 75)
		progressIndicator += "###############-----";
	else if (percents >= 76 && percents <= 80)
		progressIndicator += "################----";
	else if (percents >= 81 && percents <= 85)
		progressIndicator += "#################---";
	else if (percents >= 86 && percents <= 90)
		progressIndicator += "##################--";
	else if (percents >= 91 && percents <= 95)
		progressIndicator += "###################-";
	else if (percents >= 96 && percents <= 100)
		progressIndicator += "####################";

	progressIndicator += "]";
	string progressBar = text + " " + to_string(percents) + "% " + progressIndicator + " (" + additionalText + ")";

	if (type == ProgressBarType::classic)
	{
		lastProgressBarLength = progressBar.length();
		cout << endl << progressBar;
	}
	else
	{
#ifndef _WIN32
		// Make stdin non-blocking
		// https://stackoverflow.com/questions/8101079/making-stdin-non-blocking
		termios ttystate, ttysave;
		tcgetattr(STDIN_FILENO, &ttystate);
		ttysave = ttystate;
		ttystate.c_lflag &= ~(ICANON | ECHO);
		ttystate.c_cc[VMIN] = 6;
		tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);

		printf("\e[6n");
		int y, x;
		scanf("\e[%d;%dR", &y, &x);

		printf("\e[s\e[999;999H\e[6n\e[u");
		int width;
		scanf("\e[%*d;%dR", &width);

		int startPosition = (width - progressBar.length()) / 2;
		bool parity = (width - progressBar.length()) % 2 == 0;
		string finalProgressBar =
			string(startPosition + (parity ? 0 : 1), ' ') +
			progressBar +
			string(startPosition, ' ');

		printf("\e[;H\e[30;42m");
		cout << finalProgressBar;
		printf("\e[%d;%dH\e[39;49m", x, y);

		// Restore terminal settings
		tcsetattr(STDIN_FILENO, TCSANOW, &ttysave);
#else
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(console, &bufferInfo);

		COORD xy = bufferInfo.dwCursorPosition;
		WORD colors = bufferInfo.wAttributes;
		int width = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;

		int startPosition = (width - progressBar.length()) / 2;
		bool parity = (width - progressBar.length()) % 2 == 0;
		string finalProgressBar =
			string(startPosition + (parity? 0 : 1), ' ') +
			progressBar +
			string(startPosition, ' ');

		SetConsoleCursorPosition(console, COORD { 0, 0 });
		SetConsoleTextAttribute(console, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
		
		cout << finalProgressBar;

		SetConsoleCursorPosition(console, xy);
		SetConsoleTextAttribute(console, colors);
#endif
	}
}

void ProgressBarManager::UpdateProgressBar(uint8_t percents, string text)
{

	if (type == ProgressBarType::classic)
	{
		ClearProgressBar();

		string progressIndicator = "[";

		if (percents > 100)
			throw out_of_range("Cannot be more than 100 percents!");
		else if (percents == 0)
			progressIndicator += "--------------------";
		else if (percents >= 1 && percents <= 5)
			progressIndicator += "#-------------------";
		else if (percents >= 6 && percents <= 10)
			progressIndicator += "##------------------";
		else if (percents >= 11 && percents <= 15)
			progressIndicator += "###-----------------";
		else if (percents >= 16 && percents <= 20)
			progressIndicator += "####----------------";
		else if (percents >= 21 && percents <= 25)
			progressIndicator += "#####---------------";
		else if (percents >= 26 && percents <= 30)
			progressIndicator += "######--------------";
		else if (percents >= 31 && percents <= 35)
			progressIndicator += "#######-------------";
		else if (percents >= 36 && percents <= 40)
			progressIndicator += "########------------";
		else if (percents >= 41 && percents <= 45)
			progressIndicator += "#########-----------";
		else if (percents >= 46 && percents <= 50)
			progressIndicator += "##########----------";
		else if (percents >= 51 && percents <= 55)
			progressIndicator += "###########---------";
		else if (percents >= 56 && percents <= 60)
			progressIndicator += "############--------";
		else if (percents >= 61 && percents <= 65)
			progressIndicator += "#############-------";
		else if (percents >= 66 && percents <= 70)
			progressIndicator += "##############------";
		else if (percents >= 71 && percents <= 75)
			progressIndicator += "###############-----";
		else if (percents >= 76 && percents <= 80)
			progressIndicator += "################----";
		else if (percents >= 81 && percents <= 85)
			progressIndicator += "#################---";
		else if (percents >= 86 && percents <= 90)
			progressIndicator += "##################--";
		else if (percents >= 91 && percents <= 95)
			progressIndicator += "###################-";
		else if (percents >= 96 && percents <= 100)
			progressIndicator += "####################";

		progressIndicator += "]";

		string progressBar = text + " " + to_string(percents) + "% " + progressIndicator;

		lastProgressBarLength = progressBar.length();
		cout << '\r' << progressBar;
	}
	else
	{
		SetProgressBar(percents, text);
	}
}

void ProgressBarManager::UpdateProgressBar(uint8_t percents, string text, string additionalText)
{

	if (type == ProgressBarType::classic)
	{
		ClearProgressBar();

		string progressIndicator = "[";

		if (percents > 100)
			throw out_of_range("Cannot be more than 100 percents!");
		else if (percents == 0)
			progressIndicator += "--------------------";
		else if (percents >= 1 && percents <= 5)
			progressIndicator += "#-------------------";
		else if (percents >= 6 && percents <= 10)
			progressIndicator += "##------------------";
		else if (percents >= 11 && percents <= 15)
			progressIndicator += "###-----------------";
		else if (percents >= 16 && percents <= 20)
			progressIndicator += "####----------------";
		else if (percents >= 21 && percents <= 25)
			progressIndicator += "#####---------------";
		else if (percents >= 26 && percents <= 30)
			progressIndicator += "######--------------";
		else if (percents >= 31 && percents <= 35)
			progressIndicator += "#######-------------";
		else if (percents >= 36 && percents <= 40)
			progressIndicator += "########------------";
		else if (percents >= 41 && percents <= 45)
			progressIndicator += "#########-----------";
		else if (percents >= 46 && percents <= 50)
			progressIndicator += "##########----------";
		else if (percents >= 51 && percents <= 55)
			progressIndicator += "###########---------";
		else if (percents >= 56 && percents <= 60)
			progressIndicator += "############--------";
		else if (percents >= 61 && percents <= 65)
			progressIndicator += "#############-------";
		else if (percents >= 66 && percents <= 70)
			progressIndicator += "##############------";
		else if (percents >= 71 && percents <= 75)
			progressIndicator += "###############-----";
		else if (percents >= 76 && percents <= 80)
			progressIndicator += "################----";
		else if (percents >= 81 && percents <= 85)
			progressIndicator += "#################---";
		else if (percents >= 86 && percents <= 90)
			progressIndicator += "##################--";
		else if (percents >= 91 && percents <= 95)
			progressIndicator += "###################-";
		else if (percents >= 96 && percents <= 100)
			progressIndicator += "####################";

		progressIndicator += "]";

		string progressBar = text + " " + to_string(percents) + "% " + progressIndicator + " (" + additionalText + ")";

		lastProgressBarLength = progressBar.length();
		cout << '\r' << progressBar;
	}
	else
	{
		SetProgressBar(percents, text, additionalText);
	}
}

void ProgressBarManager::ClearProgressBar()
{
	if (type == ProgressBarType::classic)
	{
		cout << '\r' << string(lastProgressBarLength, ' ') << '\r';
	}
	else
	{
#ifndef _WIN32
		// Make stdin non-blocking
		// https://stackoverflow.com/questions/8101079/making-stdin-non-blocking
		termios ttystate, ttysave;
		tcgetattr(STDIN_FILENO, &ttystate);
		ttysave = ttystate;
		ttystate.c_lflag &= ~(ICANON | ECHO);
		ttystate.c_cc[VMIN] = 6;
		tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);

		printf("\e[6n");
		int y, x;
		scanf("\e[%d;%dR", &y, &x);

		printf("\e[s\e[999;999H\e[6n\e[u");
		int width;
		scanf("\e[%*d;%dR", &width);

		printf("\e[;H");
		cout << string(width, ' ');
		printf("\e[%d;%dH", y, x);

		// Restore terminal settings
		tcsetattr(STDIN_FILENO, TCSANOW, &ttysave);
#else
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(console, &bufferInfo);

		COORD xy = bufferInfo.dwCursorPosition;
		int width = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;

		SetConsoleCursorPosition(console, COORD { 0, 0 });

		cout << string(width, ' ');

		SetConsoleCursorPosition(console, xy);
#endif
	}
}

#pragma endregion ProgressBar

#pragma region ProgressIndicator

void ProgressBarManager::SetProgressIndicator(string text)
{
	progressIndicatorOn = true;

	if (type == ProgressBarType::classic)
		cout << endl;

	for (;;)
	{
		if (progressIndicatorOn == false)
		{
			progressIndicatorOn = NULL;
			break;
		}

		for (uint8_t i = 0; i < 4; i++)
		{
			if (progressIndicatorOn == false)
				break;

			char c = ' ';

			switch (i)
			{
			case 0:
				c = '-';
				break;
			case 1:
				c = '\\';
				break;
			case 2:
				c = '|';
				break;
			case 3:
				c = '/';
				break;
			}

			string progressBar = text + " [" + c + "]";

			if (type == ProgressBarType::classic)
			{
				lastProgressBarLength = progressBar.length();
				cout << '\r' << progressBar << flush;
			}
			else
			{
#ifndef _WIN32
				// Make stdin non-blocking
				// https://stackoverflow.com/questions/8101079/making-stdin-non-blocking
				termios ttystate, ttysave;
				tcgetattr(STDIN_FILENO, &ttystate);
				ttysave = ttystate;
				ttystate.c_lflag &= ~(ICANON | ECHO);
				ttystate.c_cc[VMIN] = 6;
				tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);	

				printf("\e[6n");
				int y, x;
				scanf("\e[%d;%dR", &y, &x);

				printf("\e[s\e[999;999H\e[6n\e[u");
				int width;
				scanf("\e[%*d;%dR", &width);

				int startPosition = (width - progressBar.length()) / 2;
				bool parity = (width - progressBar.length()) % 2 == 0;
				string finalProgressBar =
					string(startPosition + (parity ? 0 : 1), ' ') +
					progressBar +
					string(startPosition, ' ');

				printf("\e[;H\e[37;44m");
				cout << finalProgressBar << flush;
				printf("\e[%d;%dH\e[39;49m", y, x);

				// Restore terminal settings
				tcsetattr(STDIN_FILENO, TCSANOW, &ttysave);
#else
				HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

				CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
				GetConsoleScreenBufferInfo(console, &bufferInfo);

				COORD xy = bufferInfo.dwCursorPosition;
				WORD colors = bufferInfo.wAttributes;
				int width = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;
				
				int startPosition = (width - progressBar.length()) / 2;
				bool parity = (width - progressBar.length()) % 2 == 0;
				string finalProgressBar =
					string(startPosition + (parity ? 0 : 1), ' ') +
					progressBar +
					string(startPosition, ' ');

				SetConsoleCursorPosition(console, COORD { 0, 0 });
				SetConsoleTextAttribute(console, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

				cout << finalProgressBar << flush;

				SetConsoleCursorPosition(console, xy);
				SetConsoleTextAttribute(console, colors);
#endif
			}
			
			this_thread::sleep_for(chrono::milliseconds(250));
		}
	}
}

void ProgressBarManager::SetProgressIndicator(string text, string additionalText)
{
	progressIndicatorOn = true;
	if (type == ProgressBarType::classic)
		cout << endl;

	for (;;)
	{
		if (progressIndicatorOn == false)
		{
			progressIndicatorOn = NULL;
			break;
		}

		for (uint8_t i = 0; i < 4; i++)
		{
			if (progressIndicatorOn == false)
				break;

			char c = ' ';

			switch (i)
			{
			case 0:
				c = '-';
				break;
			case 1:
				c = '\\';
				break;
			case 2:
				c = '|';
				break;
			case 3:
				c = '/';
				break;
			}

			string progressBar = text + " [" + c + "] (" + additionalText + ")";

			if (type == ProgressBarType::classic)
			{
				lastProgressBarLength = progressBar.length();
				cout << '\r' << progressBar << flush;
			}
			else
			{
#ifndef _WIN32
				// Make stdin non-blocking
				// https://stackoverflow.com/questions/8101079/making-stdin-non-blocking
				termios ttystate, ttysave;
				tcgetattr(STDIN_FILENO, &ttystate);
				ttysave = ttystate;
				ttystate.c_lflag &= ~(ICANON | ECHO);
				ttystate.c_cc[VMIN] = 6;
				tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);	

				printf("\e[6n");
				int y, x;
				scanf("\e[%d;%dR", &y, &x);

				printf("\e[s\e[999;999H\e[6n\e[u");
				int width;
				scanf("\e[%*d;%dR", &width);

				int startPosition = (width - progressBar.length()) / 2;
				bool parity = (width - progressBar.length()) % 2 == 0;

				string finalProgressBar =
					string(startPosition + (parity ? 0 : 1), ' ') +
					progressBar +
					string(startPosition, ' ');

				printf("\e[;H\e[37;44m");
				cout << finalProgressBar << flush;
				printf("\e[%d;%dH\e[39;49m", y, x);

				// Restore terminal settings
				tcsetattr(STDIN_FILENO, TCSANOW, &ttysave);
#else
				HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

				CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
				GetConsoleScreenBufferInfo(console, &bufferInfo);

				COORD xy = bufferInfo.dwCursorPosition;
				WORD colors = bufferInfo.wAttributes;
				int width = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;
				
				int startPosition = (width - progressBar.length()) / 2;
				bool parity = (width - progressBar.length()) % 2 == 0;
				string finalProgressBar =
					string(startPosition + (parity ? 0 : 1), ' ') +
					progressBar +
					string(startPosition, ' ');

				SetConsoleCursorPosition(console, COORD { 0, 0 });
				SetConsoleTextAttribute(console, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

				cout << finalProgressBar << flush;

				SetConsoleCursorPosition(console, xy);
				SetConsoleTextAttribute(console, colors);
#endif
			}

			this_thread::sleep_for(chrono::milliseconds(250));
		}
	}
}

void ProgressBarManager::UpdateProgressIndicator(string text)
{
	ClearProgressIndicator();
	this_thread::sleep_for(100ms);

	if (type == ProgressBarType::classic)
	{
		progressIndicatorOn = true;

		for (;;)
		{
			if (progressIndicatorOn == false)
			{
				progressIndicatorOn = NULL;
				break;
			}

			for (uint8_t i = 0; i < 4; i++)
			{
				if (progressIndicatorOn == false)
					break;

				char c = ' ';

				switch (i)
				{
				case 0:
					c = '-';
					break;
				case 1:
					c = '\\';
					break;
				case 2:
					c = '|';
					break;
				case 3:
					c = '/';
					break;
				}

				string progressBar = text + " [" + c + "]";
				lastProgressBarLength = progressBar.length();

				cout << '\r' << progressBar << flush;

				this_thread::sleep_for(chrono::milliseconds(250));
			}
		}
	}
	else
	{
		SetProgressIndicator(text);
	}
	
}

void ProgressBarManager::UpdateProgressIndicator(string text, string additionalText)
{
	ClearProgressIndicator();
	this_thread::sleep_for(100ms);

	if (type == ProgressBarType::classic)
	{
		progressIndicatorOn = true;

		for (;;)
		{
			if (progressIndicatorOn == false)
			{
				progressIndicatorOn = NULL;
				break;
			}

			for (uint8_t i = 0; i < 4; i++)
			{
				if (progressIndicatorOn == false)
					break;

				char c = ' ';

				switch (i)
				{
				case 0:
					c = '-';
					break;
				case 1:
					c = '\\';
					break;
				case 2:
					c = '|';
					break;
				case 3:
					c = '/';
					break;
				}

				string progressBar = text + " [" + c + "] (" + additionalText + ")";
				lastProgressBarLength = progressBar.length();

				cout << '\r' << progressBar << flush;

				this_thread::sleep_for(chrono::milliseconds(250));
			}
		}
	}
	else
	{
		SetProgressIndicator(text, additionalText);
	}
	
}

void ProgressBarManager::ClearProgressIndicator()
{
	progressIndicatorOn = false;
	
	if (type == ProgressBarType::classic)
		cout << '\r' << string(lastProgressBarLength, ' ') << '\r';
	else
	{
#ifndef _WIN32
		// Make stdin non-blocking
		// https://stackoverflow.com/questions/8101079/making-stdin-non-blocking
		termios ttystate, ttysave;
		tcgetattr(STDIN_FILENO, &ttystate);
		ttysave = ttystate;
		ttystate.c_lflag &= ~(ICANON | ECHO);
		ttystate.c_cc[VMIN] = 6;
		tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);	

		printf("\e[6n");
		int y, x;
		scanf("\e[%d;%dR", &y, &x);

		printf("\e[s\e[999;999H\e[6n\e[u");
		int width;
		scanf("\e[%*d;%dR", &width);

		printf("\e[;H");
		cout << string(width, ' ');
		printf("\e[%d;%dH", y, x);

		// Restore terminal settings
		tcsetattr(STDIN_FILENO, TCSANOW, &ttysave);
#else
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(console, &bufferInfo);

		COORD xy = bufferInfo.dwCursorPosition;
		int width = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;

		SetConsoleCursorPosition(console, COORD { 0, 0 });

		cout << string(width, ' ');

		SetConsoleCursorPosition(console, xy);
#endif
	}
}

#pragma endregion ProgressIndicator

}
