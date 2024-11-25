# pico-robot
A robotics library for the Raspberry PI Pico

### Features:

- Provides cross-platform on-board led control
- Utility for CPU temperature reading
- Forward and inverse differential drive kinematics
- Utility for getting random values
- Templated `Units` type for describing values together with units (with support for converting from one unit to another)
- `Vector` types with support for quaternion creation from euler angles
- `Transform` type that combines a `vec3` position and `vec4` rotation quaternion
- Full compile time support for `Units` and `Vector` types
- Support for packing `Units` and `Vector` types into msgpack format (through the [cppack](https://github.com/mikeloomisgg/cppack) library).
- `SerializedPacket` framework for creating packets meant to be sent over the network.
- Provides a `Xbox` control packet for sending xbox gamepad inputs over the network.
- No dependencies on libraries ensure maximum flexibility
