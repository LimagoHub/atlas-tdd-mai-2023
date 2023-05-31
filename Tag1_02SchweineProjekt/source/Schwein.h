#pragma once
#include <ostream>
#include <string>
#include <stdexcept>

class Schwein
{
	std::string name;
	int gewicht;

    void setGewicht(int gewicht) {
        Schwein::gewicht = gewicht;
    }

public:
	Schwein(const std::string& name = "nobody")
		: gewicht(10)
	{
        setName(name);
	}

    void fuettern();

    void setName(const std::string &name) {
        if(name == "Elsa") throw std::invalid_argument("Schwein darf nicht Elsa heissen");
        Schwein::name = name;
    }

    // Generated Code...
    const std::string &getName() const {
        return name;
    }
    int getGewicht() const {
        return gewicht;
    }



    bool operator==(const Schwein &rhs) const {
        return name == rhs.name &&
               gewicht == rhs.gewicht;
    }

    bool operator!=(const Schwein &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }

};


