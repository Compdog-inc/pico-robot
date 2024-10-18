#include "kinematics/differentialdrive.h"

DifferentialDriveKinematics::DifferentialDriveKinematics(Units<float> trackWidth) : trackWidth(trackWidth)
{
}

ChassisSpeeds<float> DifferentialDriveKinematics::toChassisSpeeds(DifferentialDriveWheelSpeeds<float> wheelSpeeds)
{
    return ChassisSpeeds<float>(
        Units<float>::meters((wheelSpeeds.right.meters() + wheelSpeeds.left.meters()) / 2),
        Units<float>::meters(0),
        Units<float>::radians((wheelSpeeds.right.meters() - wheelSpeeds.left.meters()) / trackWidth.meters()));
}

DifferentialDriveWheelSpeeds<float> DifferentialDriveKinematics::toWheelSpeeds(ChassisSpeeds<float> chassisSpeeds)
{
    return DifferentialDriveWheelSpeeds<float>(
        Units<float>::meters(
            chassisSpeeds.forwardVelocity.meters() -
            chassisSpeeds.angularVelocity.radians() *
                trackWidth.meters() / 2),
        Units<float>::meters(
            chassisSpeeds.forwardVelocity.meters() +
            chassisSpeeds.angularVelocity.radians() *
                trackWidth.meters() / 2));
}