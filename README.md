## tstap

A Qt app for tracking mouse/touchscreen pointer movements.

Used to evaluate a BeagleBone Black touchscreen.

Assuming Qt5 dev libraries and headers are already installed.

### Build natively

    $ qmake && make

### Operation

Run from a remote ssh shell so you can see the output.

The app will run fullscreen so you won't see the output otherwise.

The coordinates of mouse press/release events are written to stdout.

You can test with a USB mouse or by using the touchscreen directly.

Output is X Y for each event shown like this

    $ ./tstap
    Down: 40 120
    Up  : 40 120

    Down: 430 250
    Up  : 430 250

    ...

    
### Run under X11

    $ export DISPLAY=:0.0
    $ ./tstap

### Run without X

Not verified 

    $ ./tstap -platform linuxfb 

