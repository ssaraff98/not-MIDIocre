#include <ardumidi.h>

const int ledPin1 = 8;
const int ledPin2 = 7;
const int ledPin3 = 6;
const int ledPin4 = 5;
const int ledPin5 = 4;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

int counter = 0;

void loop()
{
  while (midi_message_available() > 0) {

    MidiMessage m = read_midi_message();

    if (m.command == MIDI_NOTE_ON) {
      if((m.param1 == 48) || (m.param1 == 53) || (m.param1 == 58) || (m.param1 == 63) || (m.param1 == 68) || (m.param1 == 73)){
      digitalWrite(ledPin1, HIGH);
      }
      else if((m.param1 == 49) || (m.param1 == 54) || (m.param1 == 59) || (m.param1 == 64) || (m.param1 == 69) || (m.param1 == 74)){
      digitalWrite(ledPin2, HIGH);
      }
      else if((m.param1 == 50) || (m.param1 == 55) || (m.param1 == 60) || (m.param1 == 65) || (m.param1 == 70) || (m.param1 == 75)){
      digitalWrite(ledPin3, HIGH);
      }
      else if((m.param1 == 51) || (m.param1 == 56) || (m.param1 == 61) || (m.param1 == 66) || (m.param1 == 71) || (m.param1 == 76)){
      digitalWrite(ledPin4, HIGH);
      }
      else if((m.param1 == 52) || (m.param1 == 57) || (m.param1 == 62) || (m.param1 == 67) || (m.param1 == 72)){
      digitalWrite(ledPin5, HIGH);
      }
    } 

    else if (m.command == MIDI_NOTE_OFF) {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
    }
  }
}
