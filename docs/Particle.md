# Particle

The particle class contains objects with position but without orientation.

#### Protected Properties

| Type                  | Name         | Description                                                  |
| --------------------- | ------------ | ------------------------------------------------------------ |
| [Vector3](Vector3.md) | position     | This is a vector representation of the particle position     |
| [Vector3](Vector3.md) | velocity     | This is a vector representation of the particle velocity     |
| [Vector3](Vector3.md) | acceleration | This is a vector representation of the particle acceleration |
| double                | damping      | This property accounts for numerical inaccuracy with respect to Newton's first law. According to the law, an object in motion will stay in motion unless acted upon by an outside force. If there are no forces acting on an object however, objects might actually accelerate because of this inaccuracy. Thus, we use damping which approximates a kind of drag. If an object is to be treated as if there are no forces acting upon it, damping should be set to 0.999, not 1. |

