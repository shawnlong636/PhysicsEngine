# Particle

The particle class contains objects with position but without orientation.



#### Protected Properties

| Type                  | Name         | Description                                                  |
| --------------------- | ------------ | ------------------------------------------------------------ |
| [Vector3](Vector3.md) | position     | This is a vector representation of the particle position     |
| [Vector3](Vector3.md) | velocity     | This is a vector representation of the particle velocity     |
| [Vector3](Vector3.md) | acceleration | This is a vector representation of the particle acceleration |
| double                | damping      | This property accounts for numerical inaccuracy with respect to Newton's first law. According to the law, an object in motion will stay in motion unless acted upon by an outside force. If there are no forces acting on an object however, objects might actually accelerate because of this inaccuracy. Thus, we use damping which approximates a kind of drag. If an object is to be treated as if there are no forces acting upon it, damping should be set to 0.999, not 1. |
| Double                | inverseMass  | This property is equivalent to <img src="https://latex.codecogs.com/gif.latex?\frac{1}{\text{mass}}" title="\frac{1}{\text{mass}}" />. The inverse mass is stored instead of the mass so that particles can have near infinite mass, but never zero mass. |



#### Public Methods

| Type                  | Name                                                         | Description                                                  |
| --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
|                       | Particle()                                                   | Default constructor for particles. The default value for `damping` is set to 0.999 and the default value for `inverseMass` is 1.0. |
| void                  | setMass(const double mass)                                   | Mutator for `inverseMass` that accepts values greater than 0. Mass is conveyed by setting *inverseMass = 1/mass*. |
| double                | getMass()const                                               | Accessor for `inverseMass`. Returns 1/inverseMass which is equivalent to the mass. If the mass is infinite (*inverseMass==0*), then `std::numeric_limits<double>::max()` is returned. |
| void                  | setInverseMass(const double inverseMass)                     | Mutator method for `inverseMass` which accepts only positive values. |
| double                | getInverseMass()const                                        | Accessor for `inverseMass`.                                  |
| bool                  | hasFiniteMass()const                                         | Returns true if `inverseMass` is not zero.                   |
| void                  | setDamping(const double damping)                             | Mutator for `damping` which accepts values greater than zero. |
| double                | getDamping()const                                            | Accessor for `damping`.                                      |
| void                  | setPosition(const double x, const double y, const double z)  | Mutator for `position`.                                      |
| void                  | setPosition(const [Vector3](Vector3.md)& v)                  | Mutator for `position`.                                      |
| [Vector3](vector3.md) | getPosition()const                                           | Accessor for `position`.                                     |
| void                  | copyPositionTo([Vector3](Vector3.md)* v)                     | Sets the coordinates of pointer v to equal the particle's current *position*. |
| void                  | setVelocity(const double x, const double y, const double z)  | Mutator for `velocity`.                                      |
| void                  | setVelocity(const [Vector3](Vector3.md)& v)                  | Mutator for `velocity`.                                      |
| [Vector3](Vector3.md) | getVelocity()const                                           | Accessor for `velocity`.                                     |
| void                  | copyPositionTo([Vector3](Vector3.md)*)                       | Sets the coordinates of pointer v to equal the particle's current *velocity*. |
| void                  | setAcceleration(const double x, const double y, const double z) | Mutator for `acceleration`.                                  |
| void                  | setAcceleration(const [Vector3](Vector3.md)& v)              | Mutator for `acceleration`.                                  |
| [Vector3](Vector3.md) | getAcceleration()const                                       | Accessor for `acceleration`.                                 |
| void                  | copyAccelerationTo([Vector3](Vector3.md)* v)                 | Sets the coordinates of pointer v to equal the particle's current *acceleration*. |
| void                  | integrate(double duration)                                   | This method updates the position based on velocity and the velocity based on the acceleration<sup>[1](#<sup>1</sup> Integrator Implementation)</sup>. |



#### Implementation Details

##### <sup>1</sup> Integrator Implementation

The updated position, <img src="https://latex.codecogs.com/gif.latex?p'" title="p'" />, is given by the equation <img src="https://latex.codecogs.com/gif.latex?p'&space;=&space;p&space;&plus;&space;\dot{p}t" title="p' = p + \dot{p}t" />, where <img src="https://latex.codecogs.com/gif.latex?\dot{p}" title="\dot{p}" /> is the velocity and *t* is the time in seconds.

The updated velocity,<img src="https://latex.codecogs.com/gif.latex?\dot{p}'" title="\dot{p}'" />, is given by the equation, <img src="https://latex.codecogs.com/gif.latex?\dot{p}'&space;=&space;\dot{p}d^t&space;&plus;&space;\ddot{p}t" title="\dot{p}' = \dot{p}d^t + \ddot{p}t" />, where *d* is the dampening value, *t* is the time in seconds, and <img src="https://latex.codecogs.com/gif.latex?\ddot{p}" title="\ddot{p}" /> is the acceleration. During each integration step, the velocity is dampened according to the defined amount. However, since the duration of time for each call of `integrate()` is variable, the dampening value is now based on time, so that velocity is not dampened the same amount for a long and a short duration.