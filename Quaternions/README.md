# Quaterions - Python project
### Author: Łukasz Tenerowicz

---
## 1. Introduction
Quaterions are numbers that extend complex numbers. In addition to $i$ imaginary part we have there two extra complex numbers: $j$ and $k$. Basic form of quaterions looks as follow: <br>

$$
    q = s + x*i + y*j + z*k,
$$

where $s, x, y, z \in \R$ and $i, j, k \in \Complex$. Additionly there are some relations between imaginary parts:

$$
    i^2 = j^2 = k^2 = -1
$$

and:

$$
    ij = k \ \ \ \ \ \ jk = i \ \ \ \ \ ki=j \\
    ji = -k \ \ \ \ kj = -i \ \ \ \ ik = -j
$$
These relationships closely resemble cross product rules and indeed we can describe $i, j, k$ numbers as unit vectors along consecutively $x, y, z$ axis. 

$$\\$$

We can also present quaterion as ordered pair. Then our number takes that form:

$$
    q = (s, \vec v),
$$

where $s \in \R$ and $\vec v = (x, y, z), \vec v \in \R^3$. First element in pair describes real part while vector $\vec v$ contains information about imaginary part.

$$\\$$

Quaterions are often used in computer graphics, especialy in object rotations. Using quaterions instead of common rotation matrices and Euler angles prevent **Gimbal lock** occuring.

---

## 2. Implementation
`quaterion.py` source file contains implementation of such quaterion operation like: <br>
- checking if quaterions are (not) equal,
- quaterions addition,
- quaterion multiplying by scalar or another quaterion,
- dividing quaterion by non-zero scalar,
- checking if quaterion is a pure or real quaterion,
- quaterion conjugate,
- getting quaterion magnitude,
- making normalized quaterion,
- checking if quaterion is normalized,
- computing quaterions dot product,
- computing angle between two quaterions.

---

## 3. Testes
File `test_quaterion.py` contains testes for all enumerated above functions. All testes were implemented with `unittest` package. To run testes, simply open your terminal and type `py test_quaterion.py`. Make sure you are using Python in 3.0+ version.