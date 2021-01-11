## PhysicsEngine

This project follows along with Ian Millington's [Game Physics Engine Development](https://www.amazon.com/Game-Physics-Engine-Development-Commercial-Grade/dp/0123819768) and is is meant to serve as a demonstration of core understanding. This engine is written in C++, built with CMake and tested using gtest and GitHub Actions for CI.



#### Table of Contents

1. [Introduction](#Introduction)
2. [Vectors](#Vectors)
3. [Particles](#Particles)



#### Introduction

This engine was written to provide a framework for use in games, but could certainly be extended for other purposes as well. Documentation for each class is included in the [docs folder](docs/). The engine itself is broken up into sections, with descriptions and links to included classes under the corresponding sections. 



#### Vectors

Vectors in the engine exist in <img src="https://latex.codecogs.com/gif.latex?\mathbb{R}^3" title="\mathbb{R}^3" />, or in other words they are 3 Dimmensional. The primary class to store these vectors as objects is [Vector3](docs/Vector3.md). These objects contain methods for various types of vector manipulation and arithmetic, including scalar and vector products, as well as the creation of an orthogonal Basis.



#### Particles

A particle is defined as an object that has position but no orientation. Some objects that are treated as particles may technically have orientation, such as a bullet, but it is not useful to track that orientation for the purposes of the engine. As expected, the primary class that stores particle objects is [Particle](docs/Particle.md). This class has an aggregate relationship with [Vector3](docs/Vector3.md) as each particle contains vectors for position, velocity and acceleration.
