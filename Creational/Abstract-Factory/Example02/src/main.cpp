#include <iostream>

using namespace std;

// We can create some style of corner for illustration.
enum CornerStyle {
    NONE,
    SHARP,
    ROUNDED
};

// Firstly, we need to create base classes for products such as Button, Chart.
class Button {
    private:
        CornerStyle corner;
    protected:
        // Provide mechanism for platforms can re-design products.
        void setCornerStyle(CornerStyle p_corner) {
            this->corner = p_corner;
        }
    public:
        Button() : corner(NONE) {}
        virtual ~Button() {}
        CornerStyle getCornerStyle() {
            return this->corner;
        }
};

class Chart {
    private:
        CornerStyle corner;
    protected:
        // Provide mechanism for platforms can re-design products.
        void setCornerStyle(CornerStyle p_corner) {
            this->corner = p_corner;
        }
    public:
        Chart() : corner(NONE) {}
        virtual ~Chart() {}
        CornerStyle getCornerStyle() {
            return this->corner;
        }
};

// Secondly, we need to create an Abstract Factory class which represent a generic factory
// to produce products such as Button, Chart.
class GUIFactory {
    public:
        virtual ~GUIFactory() {}
        virtual Button* createButton() = 0;
        virtual Chart* createChart() = 0;
};

// Based on GUIFactory, 2 platform liked Windows and MacOS will produce 
// same products but different styles. We will create 
// 2 class of those factories and their products.
class WinButton : public Button {
    public:
        WinButton() {
            this->setCornerStyle(SHARP); // Re-design the corner for Windows.
        }
        ~WinButton() {}
};

class WinChart : public Chart {
    public:
        WinChart() {
            this->setCornerStyle(SHARP); // Re-design the corner for Windows.
        }
        ~WinChart() {}
};

class WinFactory : GUIFactory {
    public:
        ~WinFactory() {}
        Button* createButton() {
            return new WinButton();
        }
        Chart* createChart() {
            return new WinChart();
        }
};

class MacButton : public Button {
    public:
        MacButton() {
            this->setCornerStyle(ROUNDED); //Re-design the corner for MacOS.
        }
        ~MacButton() {}
};

class MacChart : public Chart {
    public:
        MacChart() {
            this->setCornerStyle(ROUNDED); //Re-design the corner for MacOS.
        }
        ~MacChart() {}
};

class MacFactory : public GUIFactory {
    public:
        ~MacFactory() {}
        Button* createButton() {
            return new MacButton();
        }
        Chart* createChart() {
            return new MacChart();
        }
};

int main() {
    WinFactory* Windows = new WinFactory();
    MacFactory* MacOS = new MacFactory();

    // With the same Button, but it's sharp for Windows,
    // whereas it's rounded for MacOS.
    Button* button01 = Windows->createButton();
    if(button01->getCornerStyle() == SHARP) {
        cout << "Corner style of Windows Button is Sharp." << endl;
    } else {
        cout << "Error!!!" << endl;
    }

    Button* button02 = MacOS->createButton();
    if(button02->getCornerStyle() == ROUNDED) {
        cout << "Corner style of MacOS Button is Rounded." << endl;
    } else {
        cout << "Error!!!" << endl;
    }

    return 0;
}


