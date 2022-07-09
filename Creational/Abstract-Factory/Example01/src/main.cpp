#include <iostream>

using namespace std;


// We can create some COLOR enum to illustrate.
enum Color {
    NONE,
    RED,
    GREEN,
    BLUE,
    WHITE,
    BLACK 
};

// Firstly, we need to create base classes for products such as Wheel, Chassis.
class Wheel {
    private:
        Color color;
    protected:
        // Provide mechanism for only car vendors to re-paint products.
        virtual void setColor(Color p_color) { 
            this->color = p_color;
        }
    public:
        Wheel() : color(NONE) {}
        Color getColor() { // All people can get products color.
            return this->color;
        }
};

class Chassis {
    private:
        Color color;
    protected:
        // Provide mechanism for only car vendors to re-paint products.
        virtual void setColor(Color p_color) {
            this->color = p_color;
        }
    public:
        Chassis() : color(NONE) {}
        Color getColor() { // All people can get products color.
            return this->color;
        }
};

// Secondly, we need to create an Abstract Factory class which represent a generic factory
// to produce products such as Wheel, Chassis.
class CarFactory {
    public:
        virtual ~CarFactory() {}
        virtual Wheel* createWheel() = 0;
        virtual Chassis* createChassis() = 0;
};

// Based on CarFactory, 2 companies named Toyota and Tesla will produce same products 
// but different styles. We will create 2 class of those factories and their products.
class ToyotaWheel : public Wheel {
    public:
        ToyotaWheel() {
            this->setColor(WHITE); // Re-paint the wheel. White is brand color of Toyota.
        };
};

class ToyotaChassis : public Chassis {
    public:
        ToyotaChassis() {
            this->setColor(WHITE); // Re-paint the chassis. White is brand color of Toyota.
        };
};

class ToyotaFactory : public CarFactory {
    public:
        ~ToyotaFactory() {}
        Wheel* createWheel() {
            return new ToyotaWheel();
        }
        Chassis* createChassis() {
            return new ToyotaChassis();
        }
};

class TeslaWheel : public Wheel {
    public:
        TeslaWheel() {
            this->setColor(BLUE); // Re-paint the wheel. Blue is brand color of Tesla.
        }
};

class TeslaChassis : public Chassis {
    public:
        TeslaChassis() {
            this->setColor(BLUE); // Re-paint the chassis. Blue is brand color of Tesla.
        }
};

class TeslaFactory : public CarFactory {
    public:
        ~TeslaFactory() {}
        Wheel* createWheel() {
            return new TeslaWheel();
        }
        Chassis* createChassis() {
            return new TeslaChassis();
        }
};

int main() {
    // Create 2 factories
    ToyotaFactory* Toyota = new ToyotaFactory();
    TeslaFactory* Tesla = new TeslaFactory();

    // With the same Wheel, but the color is white if it's produced from Toyota,
    // whereas the color is blue if it's produced from Tesla.
    Wheel* wheel01 = Toyota->createWheel();
    if(wheel01->getColor() == WHITE) {
        cout << "Wheel's color of Toyota is White" << endl;
    } else {
        cout << "Error!!!" << endl;
    }

    Wheel* wheel02 = Tesla->createWheel();
    if(wheel02->getColor() == BLUE) {
        cout << "Wheel's color of Tesla is Blue" << endl;
    } else {
        cout << "Error!!!" << endl;
    }

    delete wheel02;
    delete wheel01;

    delete Tesla;
    delete Toyota;

    return 0;
}