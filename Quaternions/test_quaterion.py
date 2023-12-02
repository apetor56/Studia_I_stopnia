import unittest
from quaterion import Quaterion

class TestQuaterion(unittest.TestCase):
    def setUp(self):
        self.q1 = Quaterion(1, 2, 3, 4)
        self.q2 = Quaterion(1, 2, 3, 5)
        self.q3 = Quaterion.from_scalar_and_vector(-3, (5, 7, 9))
        self.q4 = self.q1
        self.q5 = Quaterion(4, 4, 5, 5)

    def test_constructor(self):
        self.assertEqual(self.q1.s, 1)
        self.assertEqual(self.q1.x, 2)
        self.assertEqual(self.q1.y, 3)
        self.assertEqual(self.q1.z, 4)

        self.assertEqual(self.q3.s, -3)
        self.assertEqual(self.q3.x, 5)
        self.assertEqual(self.q3.y, 7)
        self.assertEqual(self.q3.z, 9)

        with self.assertRaises(TypeError):
            Quaterion('a', 1, 2, 3)

        with self.assertRaises(TypeError):
            Quaterion('a', 1, 'c', 3)

        with self.assertRaises(TypeError):
            Quaterion('a', 'b', 2, 'd')

    # indirectly tests also quaterion constructor
    def test_from_scalar_and_vector(self):
        self.assertEqual(self.q3, Quaterion(-3, 5, 7, 9))
        self.assertEqual(self.q5, Quaterion.from_scalar_and_vector(4, [4, 5, 5]))

        with self.assertRaises(ValueError):
            Quaterion.from_scalar_and_vector(3, [1, 3])

        with self.assertRaises(ValueError):
            Quaterion.from_scalar_and_vector(3, [3])

        with self.assertRaises(ValueError):
            Quaterion.from_scalar_and_vector(3, ())

        with self.assertRaises(TypeError):
            Quaterion.from_scalar_and_vector(3, [3, 'a', 'b'])

        with self.assertRaises(TypeError):
            Quaterion.from_scalar_and_vector('a', [3, 5, 7])

        with self.assertRaises(TypeError):
            Quaterion.from_scalar_and_vector('aaa', [3, 'a', 'b'])

    def test_copy(self):
        self.assertEqual(self.q1.copy(), self.q1)
        self.assertEqual(self.q2.copy(), self.q2)
        self.assertEqual(self.q3.copy(), self.q3)

    def test_str(self):
        self.assertEqual(str(self.q1), '1 + 2i + 3j + 4k')
        self.assertEqual(str(self.q2), '1 + 2i + 3j + 5k')
        self.assertEqual(str(self.q3), '-3 + 5i + 7j + 9k')

    def test_repr(self):
        self.assertEqual(repr(self.q1), 'Quaterion[1, 2, 3, 4]')
        self.assertEqual(repr(self.q2), 'Quaterion[1, 2, 3, 5]')
        self.assertEqual(repr(self.q3), 'Quaterion[-3, 5, 7, 9]')

    def test_eq(self):
        self.assertEqual(self.q1 == self.q4, True)
        self.assertEqual(self.q1 == self.q2, False)
        self.assertEqual(self.q1 == self.q3, False)
        self.assertEqual(self.q3 == Quaterion(-3, 5, 7, 9), True)

    def test_ne(self):
        self.assertEqual(self.q1 != self.q4, False)
        self.assertEqual(self.q1 != self.q2, True)
        self.assertEqual(self.q1 != self.q3, True)
        self.assertEqual(self.q3 != Quaterion(-3, 5, 7, 9), False)

    def test_add(self):
        self.assertEqual(self.q1 + self.q1, Quaterion(2, 4, 6, 8))
        self.assertEqual(self.q1 + self.q2, Quaterion(2, 4, 6, 9))
        self.assertEqual(self.q3 + self.q5, Quaterion.from_scalar_and_vector(1, (9, 12, 14)))

        self.assertEqual(Quaterion(1, 1, 1, 1) + 7, Quaterion(8, 1, 1, 1))
        self.assertEqual(Quaterion(1, 1, 1, 1) - 7.5, Quaterion(-6.5, 1, 1, 1))
        self.assertEqual(Quaterion(1, 1, 1, 1) + complex(5, -1), Quaterion(6, 0, 1, 1))

        with self.assertRaises(TypeError):
            self.q1 + 'aaa'

    def test_radd(self):
        self.assertEqual(5 + Quaterion(1, 2, 3, 4) , Quaterion(6, 2, 3, 4))
        self.assertEqual(-10.5 + Quaterion(0, 1, 1, 1) , Quaterion(-10.5, 1, 1, 1))
        self.assertEqual(5.222 + Quaterion(-5.222, 0, 0, 0), Quaterion(0, 0, 0, 0))
        self.assertEqual(complex(6, 7) + Quaterion(4, 3, -1, -1), Quaterion(10, 10, -1, -1))

        with self.assertRaises(TypeError):
            'a' * self.q1

    def test_sub(self):
        self.assertEqual(self.q1 - self.q1, Quaterion(0, 0, 0, 0))
        self.assertEqual(self.q1 - self.q2, Quaterion(0, 0, 0, -1))
        self.assertEqual(self.q3 - self.q5, Quaterion(-7, 1, 2, 4))
        self.assertEqual(self.q5 - self.q2, Quaterion(3, 2, 2, 0))

        self.assertEqual(Quaterion(5, 1, 1, 1) - 5, Quaterion(0, 1, 1, 1))
        self.assertEqual(Quaterion(5, 1, 1, 1) - 5.5, Quaterion(-0.5, 1, 1, 1))
        self.assertEqual(Quaterion(5, 1, 1, 1) - complex(5, 1), Quaterion(0, 0, 1, 1))

        with self.assertRaises(TypeError):
            self.q1 - 'aaa'

    def test_rsub(self):
        self.assertEqual(5 - Quaterion(5, 1, 1, 1), Quaterion(0, -1, -1, -1))
        self.assertEqual(5.5 - Quaterion(5, 1, 1, 1), Quaterion(0.5, -1, -1, -1))
        self.assertEqual(complex(5, 1) - Quaterion(5, 1, 1, 1), Quaterion(0, 0, -1, -1))

        with self.assertRaises(TypeError):
            'aaa' - self.q1

    def test_mul(self):
        self.assertEqual(self.q2 * self.q3, Quaterion(-79, -9, 5, -7))
        self.assertEqual(self.q1 * self.q2, Quaterion(-32, 7, 4, 9))
        self.assertEqual(self.q2 * self.q1, Quaterion(-32, 1, 8, 9))
        self.assertEqual(self.q4 * self.q5, Quaterion(-39, 7, 23, 19))

        self.assertEqual(self.q1 * 2, Quaterion(2, 4, 6, 8))
        self.assertEqual(self.q2 * 5, Quaterion(5, 10, 15, 25))
        self.assertEqual(self.q5 * 2.5, Quaterion(10, 10, 12.5, 12.5))
        self.assertEqual(Quaterion(1, 1, 1, 1) * complex(6, 7), Quaterion(-1, 13, 13, -1))
        
        with self.assertRaises(TypeError):
            self.q1 * "abc"

        with self.assertRaises(TypeError):
            self.q1 * [1, 3]

        with self.assertRaises(TypeError):
            self.q1 * (())

    def test_rmul(self):
        self.assertEqual(5 * Quaterion(1, 2, 3, 4), Quaterion(5, 10, 15, 20))
        self.assertEqual(2.5 * Quaterion(1, 2, 3, 4), Quaterion(2.5, 5, 7.5, 10))
        self.assertEqual(-4 * Quaterion(1, 2, 3, 4), Quaterion(-4, -8, -12, -16))

        self.assertEqual(complex(6, 7) * Quaterion(1, 1, 1, 1), Quaterion(-1, 13, -1, 13))

        with self.assertRaises(TypeError):
            'a' * self.q1

    def test_div(self):
        self.assertEqual(self.q1 / 5, Quaterion(0.2, 0.4, 0.6, 0.8))
        self.assertEqual(self.q2 / 5, Quaterion(0.2, 0.4, 0.6, 1.0))
        self.assertEqual(self.q5 / 0.5, Quaterion(8, 8, 10, 10))

        with self.assertRaises(TypeError):
            self.q1 / 'aaa'

        with self.assertRaises(TypeError):
            self.q1 / self.q1

        with self.assertRaises(ValueError):
            self.q1 / 0

    def test_isPure(self):
        self.assertEqual(self.q1.isPure(), False)
        self.assertEqual(Quaterion(0, 1, 2, 0).isPure(), True)
        self.assertEqual(Quaterion(0, 0, 0, 0).isPure(), False)
        self.assertEqual(Quaterion(0, -3, 3.14, 5).isPure(), True)

    def test_isReal(self):
        self.assertEqual(self.q1.isReal(), False)
        self.assertEqual(self.q2.isReal(), False)
        self.assertEqual(Quaterion.from_scalar_and_vector(-3, [0, 0, 0]).isReal(), True)
        self.assertEqual(Quaterion(5, 0, 0, 0).isReal(), True)

    def test_conjugation(self):
        self.assertEqual(self.q1.conjugate(), Quaterion(1, -2, -3, -4))
        self.assertEqual(self.q2.conjugate(), Quaterion(1, -2, -3, -5))
        self.assertEqual(self.q5.conjugate(), Quaterion(4, -4, -5, -5))

    def test_magnitude(self):
        self.assertAlmostEqual(self.q1.magnitude(), 5.477, delta=1e-3)
        self.assertAlmostEqual(self.q2.magnitude(), 6.245, delta=1e-3)
        self.assertAlmostEqual(self.q3.magnitude(), 12.806, delta=1e-3)

    def test_makeUnit(self):
        self.assertAlmostEqual(self.q1.makeUnit().magnitude(), 1, delta=1e-6)
        self.assertAlmostEqual(self.q2.makeUnit().magnitude(), 1, delta=1e-6)
        self.assertAlmostEqual(self.q3.makeUnit().magnitude(), 1, delta=1e-6)
        self.assertAlmostEqual(self.q5.makeUnit().magnitude(), 1, delta=1e-6)

    def test_isUnit(self):
        self.assertEqual(self.q1.isUnit(), False)
        self.assertEqual(self.q2.isUnit(), False)
        self.assertEqual(self.q2.makeUnit().isUnit(), True)
        self.assertEqual(self.q5.makeUnit().isUnit(), True)

    def test_inverse(self):
        d = 1e-2
        q1i = self.q1.inverse()
        self.assertAlmostEqual(q1i.s, 0.033, delta=d)
        self.assertAlmostEqual(q1i.x, -0.067, delta=d)
        self.assertAlmostEqual(q1i.y, -0.1, delta=d)
        self.assertAlmostEqual(q1i.z, -0.133, delta=d)

        q5i = self.q5.inverse()
        self.assertAlmostEqual(q5i.s, 0.043, delta=d)
        self.assertAlmostEqual(q5i.x, -0.043, delta=d)
        self.assertAlmostEqual(q5i.y, -0.054, delta=d)
        self.assertAlmostEqual(q5i.z, -0.065, delta=d)

    def test_dot(self):
        dot1 = Quaterion.dot(self.q1, self.q2)
        dot2 = Quaterion.dot(self.q4, self.q5)
        dot3 = Quaterion.dot(self.q1, self.q4)
        self.assertEqual(dot1, 34)
        self.assertEqual(dot2, 47)
        self.assertEqual(dot3, 30)

        with self.assertRaises(TypeError):
            Quaterion.dot(self.q1, 10)

        with self.assertRaises(TypeError):
            Quaterion.dot(-5.14, 6.49)

        with self.assertRaises(TypeError):
            Quaterion.dot('abc', {{}})

    def test_angle(self):
        q1 = Quaterion(0, 1, 0, 0)
        q2 = Quaterion(0, 0, 3, 7)
        self.assertEqual(Quaterion.angle(q1, q2), 90.0)


if __name__ == '__main__':
    unittest.main()