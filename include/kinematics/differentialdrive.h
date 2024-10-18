#ifndef _DIFFERENTIAL_DRIVE_H_
#define _DIFFERENTIAL_DRIVE_H_

#include <stdlib.h>
#include <math.h>
#include "math/units.h"
#include "kinematics/common.h"

template <typename T>
    requires arithmetic<T>
struct DifferentialDriveWheelSpeeds
{
public:
    DifferentialDriveWheelSpeeds() : left(Units<T>::meters(0)), right(Units<T>::meters(0))
    {
    }
    DifferentialDriveWheelSpeeds(Units<T> left, Units<T> right) : left(left), right(right)
    {
    }

    void normalize(Units<T> maxSpeed)
    {
        Units<T> currentSpeed = Units<T>::meters(std::max(std::abs(left.meters()), std::abs(right.meters())));
        if (currentSpeed.meters() > maxSpeed.meters())
        {
            left = Units<T>::meters(left.meters() * maxSpeed.meters() / currentSpeed.meters());
            right = Units<T>::meters(right.meters() * maxSpeed.meters() / currentSpeed.meters());
        }
    }

    Units<T> left;
    Units<T> right;
};

class DifferentialDriveKinematics
{
public:
    DifferentialDriveKinematics(Units<float> trackWidth);

    ChassisSpeeds<float> toChassisSpeeds(DifferentialDriveWheelSpeeds<float> wheelSpeeds);
    DifferentialDriveWheelSpeeds<float> toWheelSpeeds(ChassisSpeeds<float> chassisSpeeds);

private:
    Units<float> trackWidth;
};

#endif