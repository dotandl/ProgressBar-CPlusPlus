# Usage
First include library file:
```cpp
#include <ProgressBar.h>
```
Next import namespace:
```cpp
using namespace ProgressBar;
```

After that create `ProgressBarManager` class instance:
```cpp
ProgressBarManager manager; // It will create class instance for classic progress bar...
ProgressBarManager manager(ProgressBarType::color); // ...but if You want, you can decide which progress bar type will be created
```

`ProgressBarManager` can run in 2 modes: `color` or `classic`.If you specify `color` mode in the constructor, `ProgressBarManager` will check whether user's terminal supports colors and use them, otherwise `classic` mode will be chosen. If you don't specify the mode in the constructor, `classic` mode will be used by default.

On pictures was shown `classic` mode.

### Progress Bar
![Progress bar in action](img/ProgressBar.png)

There are 3 methods in `ProgressBarManager` which manages the progress bar:
- `SetProgressBar`
- `UpdateProgressBar`
- `ClearProgressBar`

To set progress bar, use `SetProgressBar` method. If you want to change text/value of progress bar, call `UpdateProgresBar`. To delete call `ClearProgressBar`.

Code I used (on picture):
```cpp
ProgressBarManager manager;
manager.SetProgressBar(50, "This is half-filled progress bar:", "hi I'm text from brackets");
```
#
### Progress Indicator
![Progress indicator in action](img/ProgressIndicator.png)

There are 3 methods in `ProgressBarManager` which manages the progress indiicator:
- `SetProgressIndicator`
- `UpdateProgressIndicator`
- `ClearProgressIndicator`

To set progress indicator, use `SetProgressIndicator` method. If you want to change text on progress indicator, call `UpdateProgressIndicator` method. To delete call `ClearProgressIndicator`.
Progress indicator **works asynchronously**.

Code I used (on picture):
```cpp
ProgressBarManager manager;
future<void> f = async(launch::async, [&manager]
{
    manager.SetProgressIndicator("This is progress indicator (with marquee effect)");
});
```
