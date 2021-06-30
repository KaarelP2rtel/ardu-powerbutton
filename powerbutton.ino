#include <Bounce2.h>

Bounce2::Button button = Bounce2::Button();

int count = 0;
unsigned int buttonLastReleased = 0;
unsigned int buttonLastPressed = 0;
int powerPin = 3;
int resetPin = 4;
int ledPin = 13;

void setup()
{
    button.attach(2, INPUT_PULLUP);
    button.interval(10);
    button.setPressedState(LOW);

    pinMode(powerPin, OUTPUT);
    pinMode(resetPin, OUTPUT);
    pinMode(ledPin, OUTPUT);

    digitalWrite(powerPin, HIGH);
    digitalWrite(resetPin, HIGH);
    digitalWrite(ledPin, LOW);

    //Serial.begin(115200);
}

void loop()
{
    button.update();
    if (button.released())
    {
        count++;
        buttonLastReleased = millis();
    }
    if (button.pressed())
    {
        buttonLastPressed = millis();
    }

    if (count == 3 && millisSince(buttonLastReleased) > 500)
    {
        tapPowerPin(100);
        count = 0;
    }

    if (count == 2 && button.isPressed() && millisSince(buttonLastPressed) > 500)
    {
        pressPowerPin();
        while (button.isPressed())
        {
            button.update();
        }
        releasePowerPin();

        count = 0;
    }
    if (count == 5 && millisSince(buttonLastReleased) > 500)
    {
        tapResetPin(100);
        count = 0;
    }

    if (millisSince(buttonLastReleased) > 1000)
    {
        count = 0;
    }
}

int millisSince(unsigned int timestamp)
{
    return millis() - timestamp;
}

void pressPowerPin()
{   
    
    digitalWrite(powerPin, LOW);
    digitalWrite(ledPin, HIGH);
    Serial.println("Power pin pressed");
}
void releasePowerPin()
{
    
    digitalWrite(powerPin, HIGH);
    digitalWrite(ledPin, LOW);
    Serial.println("Power pin released");
}
void tapPowerPin(int millis)
{
    Serial.print("Tapping power pin for ");
    Serial.println(millis);
    pressPowerPin();
    delay(millis);
    releasePowerPin();
}

void tapResetPin(int millis)
{
    Serial.print("Tapping reset pin for ");
    Serial.println(millis);
    digitalWrite(resetPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(millis);
    digitalWrite(resetPin, HIGH);
    digitalWrite(ledPin, LOW);
    Serial.println("Released");
}
