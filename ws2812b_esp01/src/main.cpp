#include <NeoPixelBus.h>

#define pixelCount 8
#define pixelPin 2  // make sure to set this to the correct pin

#define colorSaturation 128

NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart800KbpsMethod> strip(PixelCount, PixelPin);
RgbColor red = RgbColor(colorSaturation, 0, 0);
RgbColor green = RgbColor(0, colorSaturation, 0);
RgbColor blue = RgbColor(0, 0, colorSaturation);
RgbColor white = RgbColor(colorSaturation);
RgbColor black = RgbColor(0);

const RgbColor colors[3] = {red, green, blue};

int pos = 0;


void setup()
{
    // this resets all the neopixels to an off state
    strip.Begin();
    strip.Show();
}


void loop()
{
    delay(1000);

    for (int i = 0; i < pixelCount; i++) {
      strip.SetPixelColor(i, colors[pos++]);
      if (pos > 2)
        pos = 0;
    }

    strip.Show();
}
