
#include <Arduino.h>
#include <Wire.h>
#include <stdint.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <assets/logos.h>
#include <assets/display_definition.h>


#define 12832
//#define 12864
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int NUM_SLIDERS = 6;
int sliderIndex = 0;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3, A6, A7};
int analogSliderValues[NUM_SLIDERS];
int prevSliderValues[NUM_SLIDERS];

unsigned long displayTimer = 0;
const unsigned long displayDuration = 5000; // Display duration in milliseconds









int boxX = 45;      // Adjust the X position as needed
int boxY = 0;       // Adjust the Y position as needed
int boxWidth = 83;  // Adjust the box width as needed
int boxHeight = 32; // Adjust the box height to match the bitmap
int VolumeValue = 1024;
int boxFillPadding = 2;
int boxFillX = boxX + boxFillPadding;
int boxFillY = boxY + boxFillPadding;
int boxFillHeight = boxHeight - boxFillPadding - boxFillPadding;
int boxFillWidth = boxWidth - boxFillPadding - boxFillPadding;
int fillWidth = map(VolumeValue, 0, 1023, 0, boxFillWidth);

bool sliderValueChanged = false; // Flag to check if any slider value has changed
const int CHANGE_THRESHOLD = 25; // Change threshold value

void handleSliderChange(int sliderIndex);
void displayProgressBars(int sliderIndex);
void displayLogo(int sliderIndex);

void updateSliderValues()
{
    //Serial.println("updateSliderValues");
    for (int i = 0; i < NUM_SLIDERS; i++)
    {
        analogSliderValues[i] = analogRead(analogInputs[i]);
    }
}

void sendSliderValues()
{
    //Serial.println("sendSliderValues");
    String builtString = String("");

    for (int i = 0; i < NUM_SLIDERS; i++)
    {
        builtString += String((int)analogSliderValues[i]);

        if (i < NUM_SLIDERS - 1)
        {
            builtString += String("|");
        }
    }

    Serial.println(builtString);
}

void printSliderValues()
{
    for (int i = 0; i < NUM_SLIDERS; i++)
    {
        String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
        Serial.write(printedString.c_str());

        if (i < NUM_SLIDERS - 1)
        {
            Serial.write(" | ");
        }
        else
        {
            Serial.write("\n");
        }
    }
}

void handleSliderChange(int sliderIndex)
{
    //Serial.println("sendSliderValues");
    // Perform actions based on the changed slider
    // You can use the sliderIndex parameter to identify the specific slider
   
   
        display.clearDisplay();
        displayProgressBars(sliderIndex);
        displayLogo(sliderIndex);
    
    //delay(10);
    //displayTimer = millis();
    }


void displayProgressBars(int sliderIndex){
    VolumeValue = analogSliderValues[sliderIndex];
    display.drawRect(boxX, boxY, boxWidth, boxHeight, WHITE); //draw the outside box

    // Map the slider value to a percentage
    // fillWidth = map(VolumeValue, 0 , 1023, 0, boxFillWidth); 
    fillWidth = map(VolumeValue, 1023, 0, 0, boxFillWidth); // if inverted
    display.fillRect(boxFillX, boxFillY, fillWidth, boxFillHeight, WHITE); // Display the volume progress bar
    
}
void displayLogo(int sliderIndex)
{
    // uncomment if not inverted
    /*if (sliderIndex == 0) {
        if (analogSliderValues[0] < 55)
        {
            display.drawXBitmap(0, 0, volume_mute, volume_mute_width, volume_mute_height, SSD1306_WHITE);
            Serial.println("volume mute");
        }
         else if (54 < analogSliderValues[0] && analogSliderValues[0] < 500)
        {
            display.drawXBitmap(0, 0, volume_low, volume_low_width, volume_low_height, SSD1306_WHITE);
            Serial.println("volume low");
        }
        else if (499 < analogSliderValues[0] && analogSliderValues[0] < 800)
        {
            display.drawXBitmap(0, 0, volume_mid, volume_mid_width, volume_mid_height, SSD1306_WHITE);
            Serial.println("volume mid");
        }
        else if (799 < analogSliderValues[0] && analogSliderValues[0])
        {
            display.drawXBitmap(0, 0, volume_max, volume_max_width, volume_max_height, SSD1306_WHITE);
            Serial.println("volume max");
        }
        display.display();
    }*/

    //comment if not inverted
    if (sliderIndex == 0) {
        if (analogSliderValues[0] > 968)
        {
            display.drawXBitmap(0, 0, volume_mute, volume_mute_width, volume_mute_height, SSD1306_WHITE);
            //Serial.println("volume mute");
        }
         else if (968 >= analogSliderValues[0] && analogSliderValues[0] >= 700)
        {
            display.drawXBitmap(0, 0, volume_low, volume_low_width, volume_low_height, SSD1306_WHITE);
            //Serial.println("volume low");
        }
        else if (700 > analogSliderValues[0] && analogSliderValues[0] > 300)
        {
            display.drawXBitmap(0, 0, volume_mid, volume_mid_width, volume_mid_height, SSD1306_WHITE);
            //Serial.println("volume mid");
        }
        else if (300 >= analogSliderValues[0] && analogSliderValues[0])
        {
            display.drawXBitmap(0, 0, volume_max, volume_max_width, volume_max_height, SSD1306_WHITE);
            //Serial.println("volume max");
        }
        display.display();
    }


    //rest of the code
        
    if (sliderIndex == 1) {

        display.drawXBitmap(0, 0, opera, opera_width, opera_height, SSD1306_WHITE);
        display.display();
        //Serial.println("opera");
}
if (sliderIndex == 2) {

        display.drawXBitmap(0, 0, spotify, spotify_width, spotify_height, SSD1306_WHITE);
        display.display();
        //Serial.println("Spotify");
 }
 if (sliderIndex == 3) {

        display.drawXBitmap(0, 0, game, game_width, game_height, SSD1306_WHITE);
        display.display();
        //Serial.println("game");

}if (sliderIndex == 4) {

        display.drawXBitmap(0, 0, discord, discord_width, discord_height, SSD1306_WHITE);
        display.display();
        //Serial.println("discord");

}
if (sliderIndex == 5) {

        if (analogSliderValues[5] >= 875)
        {
            display.drawXBitmap(0, 0, mic_mute, mic_mute_width, mic_mute_height, SSD1306_WHITE);
            //Serial.println("mic mute");
            display.display();
        }
        else{
            display.drawXBitmap(4, 0, mic, mic_width, mic_height, SSD1306_WHITE);
        //Serial.println("mic");

        display.display();
        }
    }
}

void setup(void)
{
    for (int i = 0; i < 5; i++)
    {
        pinMode(analogInputs[i], INPUT);
    }
    /*for (int i = 6; i < 8; i++)
    {
        pinMode(analogInputs[i], INPUT);
    }*/
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }
    display.setRotation(0);

    // Clear the buffer
    display.clearDisplay();
    Serial.begin(9600);
    // Set the display size
    display.clearDisplay();
    display.drawXBitmap(0, 0, welcome_Back, welcome_Back_width, welcome_Back_height, SSD1306_WHITE);
    display.display();
    //Serial.println("welcome_Back");
    delay(100);
}

void loop(void)
{ // Fill the box from left to right
    //Serial.println("loop");
    updateSliderValues();
//handleSliderChange(sliderIndex);

    
    // Check if any slider value has changed
    for (int i = 0; i < NUM_SLIDERS; i++)
    {   
        //sendSliderValues();// Actually send data (all the time)

        if (abs(analogSliderValues[i] - prevSliderValues[i]) >= CHANGE_THRESHOLD)
        {
            sliderValueChanged = true;
            prevSliderValues[i] = analogSliderValues[i];
            displayTimer = millis();
            sliderIndex = i;
            //Serial.println(sliderIndex);
            //printSliderValues(); // For debug
            // Check if it's time to display the progress bars
            // Slider value has changed, determine which slider it was
        handleSliderChange(sliderIndex);
        sendSliderValues();// Actually send data (all the time)
            
            
        }
        else if (millis() - displayTimer >= displayDuration && sliderValueChanged != false){
        sliderIndex = 0;
        sliderValueChanged = false;
        handleSliderChange(sliderIndex);
        sendSliderValues();// Actually send data (all the time)
    }
        // Update the previous slider values

        // Update the previous slider values
        //memcpy(prevSliderValues, analogSliderValues, sizeof(analogSliderValues));

//Serial.println(sliderIndex);
    }
    
}
