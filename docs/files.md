# Files documentation for Progress Bar for C++

## Files
- [ProgressBar.h](#ProgressBar.h)  
Main library's header file
- [ProgressBarManager.h/ProgressBarManager.cpp](#ProgressBarManagerhProgressBarManagercpp)  
Header and Source files contain `ProgressBarManager` class

## ProgressBar.h
Includes all library's header files

## ProgressBarManager.h/ProgressBarManager.cpp
`class ProgressBarManager` (in `namespace ProgressBar`)
Progress bar's management class

Members:
- `void SetProgressBar(uint8_t percents, string text)`  
   Method displaying a progress bar

   Arguments:
   - `percents` Percentage value which will be displayed
   - `text` Text which will be displayed at the start of widget

   Exceptions:
   - `out_of_range` Thrown when percents' value is more than 100
#
- `void SetProgressBar(uint8_t percents, string text, string additionalText)`  
   Method displaying a progress bar with additional text

   Arguments:
   - `percents` Percentage value which will be displayed
   - `text` Text which will be displayed at the start of widget
   - `additionalText` Text which will be displayed in brackets as additional information

   Exceptions:
   - `out_of_range` Thrown when percents' value is more than 100
#
- `void UpdateProgressBar(uint8_t percents, string text)`  
   Method updating a progress bar

   Arguments:
   - `percents` Percentage value which will be displayed
   - `text` Text which will be displayed at the start of widget

   Exceptions:
   - `out_of_range` Thrown when percents' value is more than 100
#
- `void UpdateProgressBar(uint8_t percents, string text, string additionalText)`
   Method updating a progress bar with additional text

   Arguments:
   - `percents` Percentage value which will be displayed
   - `text` Text which will be displayed at the start of widget
   - `additionalText` Text which will be displayed in brackets as additional information

   Exceptions:
   - `out_of_range` Thrown when percents' value is more than 100
#
- `void ClearProgressBar()`  
   Method clearing a progress bar
#
- `void SetProgressIndicator(string text)`  
   Method displaying a progress indicator

   Arguments:
   - `text` Text which will be displayed at the start of widget
#
- `void SetProgresIndicator(string text, string additionalText)`  
   Method displaying a progress indicator with additional text

   Arguments:
   - `text` Text which will be displayed at the start of widget
   - `additionalText` Text which will be displayed in brackets as additional information
#
- `void UpdateProgressIndicator(string text)`  
   Method updating text on progress indicator

   Arguments:
   - `text` Text which will be displayed at the start of widget
#
- `void UpdateProgressBar(string text, string additionalText)`  
   Method updating text and additional text on progress indicator

   Arguments:
   - `text` Text which will be displayed at the start of widget
   - `additionalText` Text which will be displayed in brackets as additional information
#
- `void ClearProgressBar()`  
   Method clearing a progress indicator
