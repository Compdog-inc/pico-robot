#ifndef _KINEMATICS_COMMON_H_
#define _KINEMATICS_COMMON_H_

#include <stdlib.h>
#include "math/units.h"

template <typename T>
    requires arithmetic<T>
struct ChassisSpeeds
{
public:
    ChassisSpeeds() : forwardVelocity(Units<T>::meters(0)), sidewaysVelocity(Units<T>::meters(0)), angularVelocity(Units<T>::meters(0))
    {
    }
    ChassisSpeeds(Units<T> forwardVelocity, Units<T> sidewaysVelocity, Units<T> angularVelocity) : forwardVelocity(forwardVelocity), sidewaysVelocity(sidewaysVelocity), angularVelocity(angularVelocity)
    {
    }

    Units<T> forwardVelocity;
    Units<T> sidewaysVelocity;
    Units<T> angularVelocity;
};

#endif