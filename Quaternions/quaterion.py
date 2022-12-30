

class Quaterion:
    """Quaterion class implementation"""

    """Default quaterion constructor, takes 4 numbers"""
    def __init__(self, s = 0, x = 1, y = 1, z = 1):
        if not all(isinstance(item, (int, float)) for item in [s, x, y, z]):
            raise TypeError("given numbers must be integers or floats")
        
        self.s = s
        self.x = x
        self.y = y
        self.z = z

    """Creates quaterion from given scalar (real part) and vector(3D, describes imaginary part)"""
    @classmethod
    def from_scalar_and_vector(cls, s, v):
        if(len(v) != 3):
            raise ValueError("vector must have length of 3")

        re_list = [s]
        re_list.extend(v)
        if not all(isinstance(item, (int, float)) for item in re_list):
            raise TypeError("given numbers must be integers or floats")

        return cls(re_list[0], re_list[1], re_list[2], re_list[3])

    """Creates quaterion from another quaterion (copy)"""
    @classmethod
    def from_quaterion(cls, other):
        if not isinstance(other, Quaterion):
            raise TypeError('passed object to copy must be quaterion, not {}'.format(type(other)))

        return cls(other.s, other.x, other.y, other.z)

    """Returns quaterion in form of string"""
    def __str__(self) -> str:
        return '{} + {}i + {}j + {}k'.format(self.s, self.x, self.y, self.z)

    """Returns quaterion representation"""
    def __repr__(self) -> str:
        return  'Quaterion[{}, {}, {}, {}]'.format(self.s, self.x, self.y, self.z)

    """Checks if two quaterions are equal"""
    def __eq__(self, other) -> bool:
        if not isinstance(other, Quaterion):
            raise TypeError('other object is not a quaterion, but {}'.format(type(other)))
        
        if(self.s == other.s and self.x == other.x and self.y == other.y and self.z == other.z):
            return True

        return False

    """Checks is two quaterions are different"""
    def __ne__(self, other) -> bool:
        return not self == other

    """Returns new quaterion in result of addition of two quaterions"""
    def __add__(self, other):
        if not isinstance(other, Quaterion):
            raise TypeError('second factor in addition must be quaterion, not {}'.format(type(other)))

        return Quaterion(self.s + other.s, self.x + other.x, self.y + other.y, self.z + other.z)

    """Returns new quaterion in result of substraction one quaterion from another"""
    def __sub__(self, other):
        if not isinstance(other, Quaterion):
            raise TypeError('second factor in substraction must be quaterion, not {}'.format(type(other)))

        return Quaterion(self.s - other.s, self.x - other.x, self.y - other.y, self.z - other.z)

    """Returns quaterion product"""
    def __mul__(self, other):
        if not isinstance(other, (Quaterion, int, float)):
            raise TypeError('second factor in substraction must be quaterion, int or float, not {}'.format(type(other)))

        if type(other) == Quaterion:
            result = Quaterion()
            result.s = self.s * other.s - self.x * other.x - self.y * other.y - self.z * other.z 
            result.x = self.s * other.x + self.x * other.s + self.y * other.z - self.z * other.y 
            result.y = self.s * other.y + self.y * other.s + self.z * other.x - self.x * other.z 
            result.z = self.s * other.z + self.z * other.s + self.x * other.y - self.y * other.x

        else:
            result = Quaterion.from_quaterion(self)
            result.s *= other
            result.x *= other
            result.y *= other
            result.z *= other

        return result

    """Devides quaterion by scalar (return copy)"""
    def __truediv__(self, number):
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

    """Checks if quaterion is pure"""
    def isPure(self) -> bool:
        return self.s == 0 and (self.x != 0 or self.y != 0 or self.z != 0)

    """Checks if quaterion is real"""
    def isReal(self) -> bool:
        return self.s != 0 and (self.x == 0 and self.y == 0 and self.z == 0)

    """Returns quaterion conjugate (copy)"""
    def conjugate(self):
        result = Quaterion.from_quaterion(self)
        result.x *= -1
        result.y *= -1
        result.z *= -1

        return result

    """Returns quaterion magnitude"""
    def magnitude(self) -> float:
        return (self * self.conjugate()).s ** (0.5)

    """Return new quaterion which is result of normalization of given quaterion"""
    def makeUnit(self):
        result = Quaterion.from_quaterion(self)
        result = result / result.magnitude()

        return result

    """Checks if given quaterion is a unit quaterion"""
    def isUnit(self) -> bool:
        delta = 1e-8
        return self.magnitude() < 1 + delta and self.magnitude() > 1 - delta

    """Return inversion of given quaterion (new object)"""
    def inverse(self):
        return self.conjugate() / (self.magnitude()**2)

    """Returns dot product of given quaterions"""
    @staticmethod
    def dot(q1, q2) -> float:
        if not all(isinstance(item, Quaterion) for item in [q1, q2]):
            raise TypeError('Provided object(s) to dot product function which are not quaterions')

        return q1.s * q2.s + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z

if __name__ == '__main__':
    pass