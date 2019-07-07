/*
 * ========================================
 * [--------ProgressBarManager.cpp--------]
 * ========================================
 * Contains definitions of ProgressBarManager class' methods
 *
 * Created by andl on 2.07.2019
 * Last modified by andl on 7.07.2019
 */

#include <thread>
#include <chrono>

#include "ProgressBarManager.h"

namespace ProgressBar
{

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
	lastProgressBarLength = progressBar.length();

	cout << endl << progressBar;
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
	lastProgressBarLength = progressBar.length();

	cout << endl << progressBar;
}

void ProgressBarManager::UpdateProgressBar(uint8_t percents, string text)
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

void ProgressBarManager::UpdateProgressBar(uint8_t percents, string text, string additionalText)
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

void ProgressBarManager::ClearProgressBar()
{
	cout << '\r' << string(lastProgressBarLength, ' ') << '\r';
}

void ProgressBarManager::SetProgressIndicator(string text)
{
	progressIndicatorOn = true;
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
			lastProgressBarLength = progressBar.length();

			cout << '\r' << progressBar << flush;

			this_thread::sleep_for(chrono::milliseconds(250));
		}
	}
}

void ProgressBarManager::SetProgressIndicator(string text, string additionalText)
{
	progressIndicatorOn = true;
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
			lastProgressBarLength = progressBar.length();

			cout << '\r' << progressBar << flush;

			this_thread::sleep_for(chrono::milliseconds(250));
		}
	}
}

void ProgressBarManager::UpdateProgressIndicator(string text)
{
	ClearProgressIndicator();
	this_thread::sleep_for(100ms);

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

void ProgressBarManager::UpdateProgressIndicator(string text, string additionalText)
{
	ClearProgressIndicator();
	this_thread::sleep_for(100ms);

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

void ProgressBarManager::ClearProgressIndicator()
{
	progressIndicatorOn = false;
	cout << '\r' << string(lastProgressBarLength, ' ') << '\r';
}

}
