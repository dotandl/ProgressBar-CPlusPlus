/*
 * ========================================
 * [--------ProgressBarManager.cpp--------]
 * ========================================
 * Contains definitions of ProgressBarManager class' methods
 *
 * Created by andl on 2.07.2019
 * Last modified by andl on 3.07.2019
 */

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

}
