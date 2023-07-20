# 
Screej is OLED Slider Display and Controller based on Deej
This Arduino sketch is designed to control an OLED display and interact with multiple analog sliders. 
It displays progress bars for each slider and changes the logo/icon on the screen based on the slider values. 
The OLED display used in this code is an Adafruit SSD1306 display 0.91'.


How to Use
note that you will need to follow the instructions of the software of the deej projet:
https://github.com/omriharel/deej

Hardware Setup:

Connect your Arduino board to the OLED display via the I2C interface (using the Wire library).
Connect analog sliders to the analog pins A0 to A5 on the Arduino board.
Libraries:

Make sure you have installed the required libraries:
Adafruit GFX Library (Adafruit_GFX.h)
Adafruit SSD1306 Library (Adafruit_SSD1306.h)
Wire Library (Wire.h)
Standard Integer Library (stdint.h)
The assets/logos.h and assets/display_definition.h files are assumed to contain the logos/icons for display.
Define Display Configuration (Optional):


Slider Setup:

The code assumes there are 6 analog sliders connected to pins A0 to A5, but you can adjust NUM_SLIDERS and analogInputs arrays as per your setup.
Display Settings:

The code sets up the display and clears it. It displays a "welcome_Back" logo at startup.
Loop Function:

In the loop() function, the analog slider values are continuously read and stored in the analogSliderValues array.
The code checks if any slider value has changed by comparing it with the previous value (prevSliderValues). If the difference is above the CHANGE_THRESHOLD, the code considers the slider value as changed.
If a slider value changes, it triggers the handleSliderChange() function to display the corresponding progress bar and logo on the OLED screen.
The progress bar represents the slider's analog value as a filled rectangle inside a defined box.
The logo/icon on the screen changes based on the first slider's value (analogSliderValues[0]).
If no slider value changes for a certain duration (displayDuration), the code resets the slider index to zero, clearing the display.
Slider Icons:

The code includes different logos/icons for the first slider value (analogSliderValues[0]), and each icon corresponds to a specific range of values.
The code includes four icons (volume_mute, volume_low, volume_mid, volume_max) to represent different volume levels.
It also includes icons for opera, spotify, game, discord, and mic to represent different applications or functionalities.
Depending on your specific use case, you can modify or replace these icons.
Timeout Handling:

The code implements a timeout feature. If the first slider's value remains above a certain threshold (968) for a specific duration (displayTimeoutDuration), it sets the timeoutFl flag, indicating a timeout event.
When the timeout event occurs, the display is cleared and no new progress bars or logos are displayed until the first slider value changes below the threshold.
Serial Communication (Optional):

The code includes sendSliderValues() and printSliderValues() functions that send and print the slider values over the serial communication. You can use these functions for debugging or communication purposes.
Note
Ensure you have the appropriate bitmap files (e.g., volume_mute, volume_low, etc.) corresponding to each logo/icon defined in the code. These bitmap files should be included in the assets folder along with the logos.h and display_definition.h files.

Please make sure to customize the code and the bitmap files according to your specific hardware and use case. The provided code is a starting point for creating an OLED slider display and controller, and it can be further expanded and adapted to suit your requirements.
