#ifndef __ENGUNITS_MATHS_H
#define __ENGUNITS_MATHS_H

#include <cmath>
#include<type_traits>

#include "../engunits/_abstract/abstract_base.h"
#include "../engunits/length.h"
#include "../engunits/mass.h"
#include "../engunits/constants.h"
#include "../engunits/force.h"

namespace engunits::maths{

double cos(const double &value) { return std::cos(value); }
double sin(const double &value) { return std::sin(value); }
double tan(const double &value) { return std::tan(value); }
double acos(const double &value) { return std::acos(value); }
double asin(const double &value) { return std::asin(value); }
double atan(const double &value) { return std::atan(value); }
double cosh(const double &value) { return std::cosh(value); }
double sinh(const double &value) { return std::sinh(value); }
double tanh(const double &value) { return std::tanh(value); }
double acosh(const double &value) { return std::acosh(value); }
double asinh(const double &value) { return std::asinh(value); }
double atanh(const double &value) { return std::atanh(value); }

template <template<typename> typename S, typename T>
double cos(const abstract::PhysicalUnit<S, T> &unit) { return std::cos(unit.scalar()); }
template <template<typename> typename S, typename T>
double sin(const abstract::PhysicalUnit<S, T> &unit) { return std::sin(unit.scalar()); }
template <template<typename> typename S, typename T>
double tan(const abstract::PhysicalUnit<S, T> &unit) { return std::tan(unit.scalar()); }

constexpr force::Newtons calculate_fgrav(const mass::kilograms& mass1, const mass::kilograms& mass2, 
    const length::meters& radius){
        return (constant::G * mass1.scalar() * mass2.scalar() / (radius.scalar() * radius.scalar()));
}

} // namespace engunits::maths

#endif