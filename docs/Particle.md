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

| Type | Name                       | Description                                                  |
| ---- | -------------------------- | ------------------------------------------------------------ |
| void | integrate(double duration) | This method updates the position based on velocity and the velocity based on the acceleration<sup>[1](#<sup>1</sup> Integrator Implementation)</sup>. |



#### Implementation Details

##### <sup>1</sup> Integrator Implementation

The updated position, <img src="https://latex.codecogs.com/gif.latex?p'" title="p'" />, is given by the equation <img src="https://latex.codecogs.com/gif.latex?p'&space;=&space;p&space;&plus;&space;\dot{p}t" title="p' = p + \dot{p}t" />, where <img src="https://latex.codecogs.com/gif.latex?\dot{p}" title="\dot{p}" /> is the velocity and *t* is the time in seconds.

The updated velocity,<img src="https://latex.codecogs.com/gif.latex?\dot{p}'" title="\dot{p}'" />, is given by the equation, <img src="https://latex.codecogs.com/gif.latex?\dot{p}'&space;=&space;\dot{p}d^t&space;&plus;&space;\ddot{p}t" title="\dot{p}' = \dot{p}d^t + \ddot{p}t" />, where *d* is the dampening value, *t* is the time in seconds, and <img src="https://latex.codecogs.com/gif.latex?\ddot{p}" title="\ddot{p}" /> is the acceleration. During each integration step, the velocity is dampened according to the defined amount. However, since the duration of time for each call of `integrate()` is variable, the dampening value is now based on time, so that velocity is not dampened the same amount for a long and a short duration.