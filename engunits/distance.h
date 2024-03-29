#ifndef __ENGUNITS_DISTANCE_H
#define __ENGUNITS_DISTANCE_H

#include<iostream>
#include<string>

#include "../engunits/_conversion/distance_conversion.h"
#include "../engunits/_abstract/abstract_unit.h"

namespace engunits::distance{

class inches : public DistanceUnit<inches> {
    public:
        using DistanceUnit<inches>::DistanceUnit;

        static constexpr double conversion = conversion::D_INCHES;

        const std::string symbol() const override { return "in"; }
};

class feet : public DistanceUnit<feet> {
    public:
        using DistanceUnit<feet>::DistanceUnit;

        static constexpr double conversion = conversion::D_FEET;

        const std::string symbol() const override {return "ft";}
};
}

namespace engunits::literals{

ADD_LITERALS(distance::feet, ft);
ADD_LITERALS(distance::meters, m);
ADD_LITERALS(distance::inches, in);

}

#endif