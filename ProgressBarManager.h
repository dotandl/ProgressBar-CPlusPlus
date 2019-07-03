/*
 * ========================================
 * [---------ProgressBarManager.h---------]
 * ========================================
 * Contains declaration of ProgressBarManager class
 *
 * Created by andl on 2.07.2019
 * Last modified by andl on 3.07.2019
 */

#pragma once

#include <iostream>

using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif

namespace ProgressBar
{

/*
 * Class: ProgressBarManager
 * Progress bar's management class
 */
class ProgressBarManager
{
private:
	/*
	 * Field: lastProgressBarLenght
	 * Variable storing length of last-showed progress bar
	 */
	uint8_t lastProgressBarLength;

public:
	/*
	 * Method: SetProgressBar
	 * Method displaying a progress bar
	 * ================================
	 * Arguments:
	 * percents: Percentage value which
	 *           will be displayed
	 * text: Text which will be
	 *       displayed at the start of
	 *       widget
	 * ================================
	 * Exceptions:
	 * out_of_range: Thrown when
	 *               percents' value is
	 *               more than 100
	 */
	void SetProgressBar(uint8_t percents, string text);

	/*
	 * Method: SetProgressBar
	 * Method displaying a progress bar with additional text
	 * =====================================================
	 * Arguments:
	 * percents: Percentage value which will be displayed
	 * text: Text which will be displayed at the start of
	 *       widget
	 * additionalText: Text which will be displayed in
	 *                 brackets as additional information
	 * =====================================================
	 * Exceptions:
	 * out_of_range: Thrown when percents' value is more
	 *               than 100
	 */
	void SetProgressBar(uint8_t percents, string text, string additionalText);

	/*
	 * Method: UpdateProgressBar
	 * Method updating a progress bar
	 * ==============================
	 * Arguments:
	 * percents: Percentage value
	 *           which will be
	 *           displayed
	 * text: Text which will be
	 *       displayed at the start
	 *       of widget
	 * ==============================
	 * Exceptions:
	 * out_of_range: Thrown when
	 *               percents' value
	 *               is more than 100
	 */
	void UpdateProgressBar(uint8_t percents, string text);

	/*
	 * Method: UpdateProgressBar
	 * Method updating a progress bar with additional text
	 * ===================================================
	 * Arguments:
	 * percents: Percentage value which will be displayed
	 * text: Text which will be displayed at the start of
	 *       widget
	 * additionalText: Text which will be displayed in
	 *                 brackets as additional information
	 * ===================================================
	 * Exceptions:
	 * out_of_range: Thrown when percents' value is more
	 *               than 100
	 */
	void UpdateProgressBar(uint8_t percents, string text, string additionalText);

	/*
	 * Method: ClearProgressBar
	 * Method clearing a progress bar
	 */
	void ClearProgressBar();
};

}

#ifdef __cplusplus
}
#endif
