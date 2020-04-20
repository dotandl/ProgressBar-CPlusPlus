/*
 * ========================================
 * [---------ProgressBarManager.h---------]
 * ========================================
 * Contains declaration of ProgressBarManager class
 *
 * Created by andl on 2.07.2019
 * Last modified by andl on 8.09.2019
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
 * Enum: ProgressBarType
 * Enum defining type of Progress Bar
*/
enum ProgressBarType
{
	/*
	 * Enum value: classic
	 * Value telling Progress Bar to don't use any colors (for Unix consoles doesn't support escape sequences)
	 */
	classic,

	/*
	 * Enum value: color
	 * Value telling Progress Bar to use colors
	 */
	color
};

/*
 * Class: ProgressBarManager
 * Progress bar's management class
 */
class ProgressBarManager
{
private:
	/*
	 * Field: type
	 * Variable storing type of Progress Bar
	 */
	ProgressBarType type;

	/*
	 * Field: lastProgressBarLength
	 * Variable storing length of last-showed progress bar
	 */
	size_t lastProgressBarLength;

	/*
	 * Field: progressIndicatorOn
	 * Variable showing state of progress indicator working
	 */
	bool progressIndicatorOn = NULL;

	/*
	 * Method: CheckForColorSupport
	 * Method checking color support
	 */
	bool CheckForColorSupport();

public:
	/*
	 * Default empty constructor
	 */
	ProgressBarManager();

	/*
	 * Constructor defining type of ProgressBar
	 * ========================================
	 * Arguments:
	 * type: Type of Progress Bar (if terminal
	 *       doesn't support color, it will be
	 *       classic)
	 */
	ProgressBarManager(ProgressBarType type);

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

	/*
	 * Method: SetProgressIndicator
	 * Method displaying a progress indicator
	 * ======================================
	 * Arguments:
	 * text: Text which will be displayed at
	 *       the start of widget
	 */
	void SetProgressIndicator(string text);

	/*
	 * Method: SetProgressIndicator
	 * Method displaying a progress indicator with additional text
	 * ===========================================================
	 * Arguments:
	 * text: Text which will be displayed at the start of widget
	 * additionalText: Text which will be displayed in brackets as
	 *                 additional information
	 */
	void SetProgressIndicator(string text, string additionalText);

	/*
	 * Method: UpdateProgressIndicator
	 * Method updating text on progress indicator
	 * ==========================================
	 * Arguments:
	 * text: Text which will be displayed at the
	 *       start of widget
	 */
	void UpdateProgressIndicator(string text);

	/*
	 * Method: UpdateProgressIndicator
	 * Method updating text and additional text on progress indicator
	 * ==============================================================
	 * Arguments:
	 * text: Text which will be displayed at the start of widget
	 * additionalText: Text which will be displayed in brackets as
	 *                 additional information
	 */
	void UpdateProgressIndicator(string text, string additionalText);

	/*
	 * Method: ClearProgressIndicator
	 * Method clearing a progress indicator
	 */
	void ClearProgressIndicator();

};

}

#ifdef __cplusplus
}
#endif
