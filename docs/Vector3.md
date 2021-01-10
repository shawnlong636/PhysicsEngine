# Vector3

The Vector3 class represents a vector in <img src="https://render.githubusercontent.com/render/math?math=\mathbb{R}^3"> and is part of the `phys` namespace.

#### Public Properties

| Type   | Name | Description                  |
| ------ | ---- | ---------------------------- |
| double | x    | *x* coordinate of the vector |
| double | y    | *y* coordinate of the vector |
| double | z    | *z* coordinate of the vector |

#### Public Methods

| Type    | Name                                                         | Description                                                  |
| ------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
|         | Vector3()                                                    | Empty constructor. All coordinates initialized to 0.         |
|         | Vector3(const double [x](#Properties), const double [y](#Properties), const double [z](#Properties)) | Constructor that accepts coordinates as parameters.          |
| void    | invert()                                                     | Reverses the direction of a vector by scaling by -1.         |
| double  | dotProduct(const Vector3& v)                                 | Returns the numerical value of the dot product of a vector with respect to another. Since this is a member function, the first vector is the one the method is called on, and the second is the parameter. |
| Vector3 | crossProduct(const Vector3& v)                               | Returns a vector which is orthogonal to the current vector and the parameter. Implementation based on simplification of the determinant for these two vector functions. ([Details](#Cross Product)) |
| double  | magnitude()                                                  | Returns magnitude of the vector expressed by <img src="https://latex.codecogs.com/gif.latex?\sqrt{x^2&plus;y^2&plus;z^2}" title="\sqrt{x^2+y^2+z^2}" /> |
| void    | normalize                                                    | Normalizes the vector by dividing each component by the `magnitude()` of the vector. The result is a vector with magnitude 1. |

#### Static Methods

| Type           | Name                                                     | Description                                                  |
| -------------- | -------------------------------------------------------- | ------------------------------------------------------------ |
| static Vector3 | crossProduct(const Vector3& v1, const Vector3& v2)       | Returns a vector which is orthogonal to vectors *v1* and *v2*. Implementation based on simplification of the determinant for these two vector functions. ([Details](#Cross Product)) |
| static void    | makeOrthonormalBasis(Vector3* a, Vector3* b, Vector3* c) | Given non-null vectors *a* *b*, and *c*, this method converts *a*, *b* and *c* into an orthonormal basis, using a <u>right-handed coordinate system</u>. If *a*, *b* or *c* are null, it throws a `std::invalid_argument` exception. Utilizes `normalize()` and `crossProduct()` to obtain the normal orthogonal vectors. |



#### Overloaded Operators

| Type    | Name                             | Description                                                  |
| ------- | -------------------------------- | ------------------------------------------------------------ |
| Vector3 | operator+(const Vector3& v)      | Simple vector addition, component by component.              |
| Vector3 | operator-(const Vector3& v)      | Simple vector subtraction, component by component            |
| void    | operator+=(const Vector3& v)     | Simple vector addition that overwrites the current vector rather than return another. This modifies the vector that it is called on. |
| void    | operator-=(const Vector3& v)     | Simple vector subtraction that overwrites the current vector rather than return another. This modifies the vector that it is called on. |
| Vector3 | operator*(const double& scalar)  | Returns the scalar multiple of the vector using the given parameter. |
| void    | Operator*=(const double& scalar) | Overwrites the current vector with the scalar multiple of itself using the given parameter. |



### Implementation Details

##### Cross Product

<img src="https://latex.codecogs.com/gif.latex?\begin{align*}&space;\vec{a}&space;&=&space;\langle&space;a_x,a_y,a_z&space;\rangle&space;&&space;\vec{b}&=&space;\langle&space;b_x,b_y,b_z&space;\rangle&space;\end{align*}&space;\newline&space;\begin{align*}&space;\vec{a}&space;\times&space;\vec{b}&space;&=&space;\begin{vmatrix}\vec{i}&space;&&space;\vec{j}&space;&&space;\vec{k}\\&space;a_x&space;&&space;a_y&space;&&space;a_z&space;\\&space;b_x&space;&&space;b_y&space;&&space;b_z&space;\end{vmatrix}\\[1em]&space;&=&space;\begin{vmatrix}a_y&space;&&space;a_z\\&space;b_y&space;&&space;b_z&space;\end{vmatrix}\vec{i}&space;-&space;\begin{vmatrix}a_x&space;&&space;a_z\\&space;b_x&space;&&space;b_z&space;\end{vmatrix}\vec{j}&space;&plus;&space;\begin{vmatrix}a_x&space;&&space;a_y\\&space;b_x&space;&&space;b_y&space;\end{vmatrix}\vec{k}\\[1em]&space;&=&space;(a_y&space;b_z&space;-&space;a_z&space;b_y)\vec{i}&space;-&space;(a_x&space;b_z&space;-&space;a_z&space;b_x)\vec{j}&space;&plus;&space;(a_x&space;b_y&space;-&space;a_y&space;b_x)\vec{k}\\[1em]&space;&=&space;(a_y&space;b_z&space;-&space;a_z&space;b_y)\vec{i}&space;&plus;&space;(a_z&space;b_x&space;-&space;a_x&space;b_z&space;)\vec{j}&space;&plus;&space;(a_x&space;b_y&space;-&space;a_y&space;b_x)\vec{k}\\[1em]&space;\vec{a}&space;\times&space;\vec{b}&space;&=&space;\langle&space;a_y&space;b_z&space;-&space;a_z&space;b_y,&space;a_z&space;b_x&space;-&space;a_x&space;b_z,&space;a_x&space;b_y&space;-&space;a_y&space;b_x&space;\rangle&space;\end{align*}" title="\begin{align*} \vec{a} &= \langle a_x,a_y,a_z \rangle & \vec{b}&= \langle b_x,b_y,b_z \rangle \end{align*} \newline \begin{align*} \vec{a} \times \vec{b} &= \begin{vmatrix}\vec{i} & \vec{j} & \vec{k}\\ a_x & a_y & a_z \\ b_x & b_y & b_z \end{vmatrix}\\[1em] &= \begin{vmatrix}a_y & a_z\\ b_y & b_z \end{vmatrix}\vec{i} - \begin{vmatrix}a_x & a_z\\ b_x & b_z \end{vmatrix}\vec{j} + \begin{vmatrix}a_x & a_y\\ b_x & b_y \end{vmatrix}\vec{k}\\[1em] &= (a_y b_z - a_z b_y)\vec{i} - (a_x b_z - a_z b_x)\vec{j} + (a_x b_y - a_y b_x)\vec{k}\\[1em] &= (a_y b_z - a_z b_y)\vec{i} + (a_z b_x - a_x b_z )\vec{j} + (a_x b_y - a_y b_x)\vec{k}\\[1em] \vec{a} \times \vec{b} &= \langle a_y b_z - a_z b_y, a_z b_x - a_x b_z, a_x b_y - a_y b_x \rangle \end{align*}" />

