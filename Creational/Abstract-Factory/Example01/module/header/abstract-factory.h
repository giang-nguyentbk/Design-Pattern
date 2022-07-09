#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

// Firstly, we need to create base classes for products such as Wheel, Chassis, Furniture.

class Wheel {

};

class Chassis {

};

class Furniture {

};

// Secondly, we need to create an Abstract Factory class which represent a generic factory
// to produce products such as Wheel, Chassis, Furniture.

class CarAbstractFactory {
    public:
        virtual Wheel createWheel() = 0;
        virtual Chassis createChassis() = 0;
        virtual Furniture createFurniture() = 0;
};



#endif //_ABSTRACT_FACTORY_H_