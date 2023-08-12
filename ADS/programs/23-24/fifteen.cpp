/*
Create a remote control class that interacts with different electronic devices using message passing to perform actions like turning
on/off and adjusting volume.

Input:
    Television tv("Living Room TV");
    tv.displayStatus();

    tv.turnOn();
    tv.displayStatus();

    tv.adjustVolume(5);
    tv.turnOff();
    tv.displayStatus();

Output:
Living Room TV is OFF
Living Room TV is now ON.
Living Room TV is ON
Volume adjusted to 25
Living Room TV is now OFF.
Living Room TV is OFF

*/

#include <iostream>
#include <string>
using namespace std;

// Base class representing an Electronic Device
class ElectronicDevice {
protected:
    string deviceName;
    bool isOn;

public:
    // Constructor to initialize the device with a name and set it to off by default
    ElectronicDevice(string name) : deviceName(name), isOn(false) {}

    // Virtual function to turn on the device
    virtual void turnOn() {
        isOn = true;
        cout << deviceName << " is now ON." << endl;
    }

    // Virtual function to turn off the device
    virtual void turnOff() {
        isOn = false;
        cout << deviceName << " is now OFF." << endl;
    }

    // Virtual function to display the device's status (ON or OFF)
    virtual void displayStatus() {
        cout << deviceName << " is " << (isOn ? "ON" : "OFF") << endl;
    }
};

// Derived class representing a Television, inheriting from ElectronicDevice
class Television : public ElectronicDevice {
private:
    int volume;

public:
    // Constructor to initialize the TV with a name and volume set to 0
    Television(string name) : ElectronicDevice(name), volume(0) {}

    // Override the turnOn function to set the TV's volume to 20 when turning on
    void turnOn() override {
        ElectronicDevice::turnOn();
        volume = 20;
    }

    // Override the turnOff function to set the TV's volume to 0 when turning off
    void turnOff() override {
        ElectronicDevice::turnOff();
        volume = 0;
    }

    // Function to adjust the TV's volume by the given level
    void adjustVolume(int level) {
        if (isOn) {
            volume += level;
            cout << "Volume adjusted to " << volume << endl;
        } else {
            cout << "Turn on the TV first." << endl;
        }
    }
};

int main() {
    // Create a Television object with the name "Living Room TV"
    Television tv("Living Room TV");

    // Display the initial status of the TV (OFF by default)
    tv.displayStatus();

    // Turn on the TV and display the updated status
    tv.turnOn();
    tv.displayStatus();

    // Adjust the volume of the TV and then turn it off
    tv.adjustVolume(5);
    tv.turnOff();

    // Display the final status of the TV
    tv.displayStatus();

    return 0;
}

/*
In this code, we have two classes, ElectronicDevice and Television. The ElectronicDevice class represents a generic electronic device with a name and a status (ON or OFF). It has three virtual functions, turnOn(), turnOff(), and displayStatus(), to turn the device on or off and display its status.

The Television class is derived from ElectronicDevice and represents a specific type of electronic device, a television. It adds an additional member variable volume to represent the volume level of the TV. It overrides the turnOn() and turnOff() functions to set the volume to 20 when turning on and 0 when turning off.

In the main function, we create a Television object named "Living Room TV" and display its initial status (OFF). Then, we turn on the TV, adjust its volume by 5 units, and turn it off again. Finally, we display the final status of the TV to see that it is OFF. The use of virtual functions enables dynamic binding, allowing the correct version of the function to be called based on the object's type.

*/


