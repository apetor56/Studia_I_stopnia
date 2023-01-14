from math import acos
from math import pi
import cmath

class Quaterion:
    """Quaterion class implementation"""

    def __init__(self, s = 0, x = 0, y = 0, z = 0):
        """Default quaterion constructor, takes 4 numbers"""
        if not all(isinstance(item, (int, float)) for item in [s, x, y, z]):
            raise TypeError("given numbers must be integers or floats")
        
        self.s = s
        self.x = x
        self.y = y
        self.z = z

    @staticmethod
    def _normalize(other):
        """Covert int, float or complex into quaterion"""
        if isinstance(other, Quaterion):
            return other
        elif isinstance(other, (int, float)):
            return Quaterion(other)
        elif(isinstance(other, complex)):
            return Quaterion(other.real, other.imag)

        raise TypeError('cannot convert to quaterion')
        
    @classmethod
    def from_scalar_and_vector(cls, s, v):
        """Creates quaterion from given scalar (real part) and vector(3D, describes imaginary part)"""
        if(len(v) != 3):
            raise ValueError("vector must have length of 3")

        return cls(s, v[0], v[1], v[2])

    @classmethod
    def from_quaterion(cls, other):
        """Creates quaterion from another quaterion (copy)"""
        if not isinstance(other, Quaterion):
            raise TypeError('passed object to copy must be quaterion, not {}'.format(type(other)))

        return cls(other.s, other.x, other.y, other.z)

    def __str__(self) -> str:
        """Returns quaterion in form of string"""
        return '{} + {}i + {}j + {}k'.format(self.s, self.x, self.y, self.z)

    def __repr__(self) -> str:
        """Returns quaterion representation"""
        return  'Quaterion[{}, {}, {}, {}]'.format(self.s, self.x, self.y, self.z)

    def __eq__(self, other) -> bool:
        """Checks if two quaterions are equal"""
        if not isinstance(other, Quaterion):
            raise TypeError('other object is not a quaterion, but {}'.format(type(other)))
        
        if(self.s == other.s and self.x == other.x and self.y == other.y and self.z == other.z):
            return True

        return False

    def __ne__(self, other) -> bool:
        """Checks is two quaterions are different"""
        return not self == other

    def __add__(self, other):
        """Returns new quaterion in result of addition of two quaterions"""
        other = Quaterion._normalize(other)

        return Quaterion(self.s + other.s, self.x + other.x, self.y + other.y, self.z + other.z)

    def __radd__(self, other):
        other = Quaterion._normalize(other)

        return self + other

    def __sub__(self, other):
        """Returns new quaterion in result of substraction one quaterion from another"""
        other = Quaterion._normalize(other)

        return Quaterion(self.s - other.s, self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, other):
        """Returns quaterion product"""
        other = Quaterion._normalize(other)

        result = Quaterion()
        result.s = self.s * other.s - self.x * other.x - self.y * other.y - self.z * other.z 
        result.x = self.s * other.x + self.x * other.s + self.y * other.z - self.z * other.y 
        result.y = self.s * other.y + self.y * other.s + self.z * other.x - self.x * other.z 
        result.z = self.s * other.z + self.z * other.s + self.x * other.y - self.y * other.x

        return result

    def __rmul__(self, other):
        other = Quaterion._normalize(other)
        
        return other * self
    
    def __truediv__(self, number):
        """Devides quaterion by scalar (return copy)"""
        if not isinstance(number, (int, float)):
            raise TypeError('expected scalar value, not {}'.format(type(number)))

        if(number == 0):
            raise ValueError('Dividing by 0 is undefined')

        result = Quaterion.from_quaterion(self)
        result.s /= number
        result.x /= number
        result.y /= number
        result.z /= number

        return result

    def isPure(self) -> bool:
        """Checks if quaterion is pure"""
        return self.s == 0 and (self.x != 0 or self.y != 0 or self.z != 0)

    def isReal(self) -> bool:
        """Checks if quaterion is real"""
        return self.s != 0 and (self.x == 0 and self.y == 0 and self.z == 0)

    def conjugate(self):
        """Returns quaterion conjugate (copy)"""
        result = Quaterion.from_quaterion(self)
        result.x *= -1
        result.y *= -1
        result.z *= -1

        return result

    def magnitude(self) -> float:
        """Returns quaterion magnitude"""
        return (self * self.conjugate()).s ** (0.5)

    def makeUnit(self):
        """Return new quaterion which is result of normalization of given quaterion"""
        result = Quaterion.from_quaterion(self)
        result = result / result.magnitude()

        return result

    def isUnit(self) -> bool:
        """Checks if given quaterion is a unit quaterion"""
        delta = 1e-8
        return self.magnitude() < 1 + delta and self.magnitude() > 1 - delta

    def inverse(self):
        """Return inversion of given quaterion (new object)"""
        return self.conjugate() / (self.magnitude()**2)

    @staticmethod
    def dot(q1, q2) -> float:
        """Returns dot product of given quaterions"""
        if not all(isinstance(item, Quaterion) for item in [q1, q2]):
            raise TypeError('Provided object(s) to dot product function which are not quaterions')

        return q1.s * q2.s + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z

    @staticmethod
    def angle(q1, q2) -> float:
        """Returns angle in degrees between two quaterions"""
        if not all(isinstance(item, Quaterion) for item in [q1, q2]):
            raise TypeError('Provided object(s) to dot product function which are not quaterions')
        
        return acos(Quaterion.dot(q1, q2) / (q1.magnitude() * q2.magnitude())) * 180.0 / pi


if __name__ == '__main__':
    pass