# not-MIDIocre
Turning a Linux-run laptop keyboard into a MIDI keyboard and controlling LEDs with each corresponding note (Similar steps for Mac and Windows, but different applications required).

# Getting Started
## For converting your laptop's keyboard into a MIDI keyboard
1) Download the compiled version or the source code and other dependencies for Virtual MIDI Piano Keyboard from http://vmpk.sourceforge.net/#Download
For Linux, sudo apt install vmpk
2) Clone with Amsynth repository from https://github.com/amsynth/amsynth and follow the instructions to compile it using 'make'.
For Linux, sudo apt install amsynth
3) Download the zip file or source code and other dependencies for QjackCtl from https://qjackctl.sourceforge.io/qjackctl-downloads.html#Git
For Linux, sudo apt install qjackctl
4) Download Timidity and any other dependencies from https://sourceforge.net/projects/timidity/
For Linux, sudo apt install timidity

## For converting an Arduino into a MIDI device
(If you have an Arduino with a USB port, skip this section and move on to the next) MIDI cannot interface with an Arduino if it doesn't have a USB connection, hence, we need to use 'ttymidi'.
1) Read and download 'ttymidi' from http://projectgus.github.io/hairless-midiserial/ (No need to download Hairless MIDI serial if you are using 'ttymidi'.
2) Carefully read the README.txt for 'ttymidi' before compiling it.
3) Vim into Makefile and change 'gcc src/ttymidi.c -o ttymidi -lasound' to 'gcc src/ttymidi.c -o ttymidi -lasound -lpthread' to avoid unexpected errors.
4) Follow instructions on http://www.varal.org/ttymidi/#miditable to convert your Arduino into a MIDI device.

## For getting started to 
1) Clone 'ardumidi' library from https://github.com/projectgus/hairless-midiserial/tree/master/ardumidi and add that to your Arduino library.
Do not use Arduino MIDI (MIDI.h) library because it does not recognize MIDI notes inputted into the Arduino IDE.
2) Change your port and device according to the ones being used by you.
To check the port, type 'cd /dev' in the terminal and 'ls' to display all ports. It's most likely the required port will be '/dev/ttyACMx' or '/dev/ttyUSBx' (where x is any number).
3) Follow my code as an example and modify it to do what you want.
