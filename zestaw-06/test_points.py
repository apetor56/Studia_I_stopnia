import unittest
from points import Point

class TestPoint(unittest.TestCase):
    def setUp(self):
        self.p1 = Point(1, 1)
        self.p2 = Point(2, 2)
        self.p3 = Point(3, 4)
        self.p4 = Point(5, 12)
        self.p5 = Point(7, 9)
        self.p6 = Point(-2, 4)
        self.p7 = Point(-2, 4)
        self.p8 = Point(-2, 4)

    def test_str(self):
        self.assertEqual(str(self.p1), "(1, 1)")
        self.assertEqual(str(self.p2), "(2, 2)")
        self.assertEqual(str(self.p3), "(3, 4)")

    def test_repr(self):
        self.assertEqual(repr(self.p1), "Point(1, 1)")
        self.assertEqual(repr(self.p2), "Point(2, 2)")
        self.assertEqual(repr(self.p3), "Point(3, 4)")

    def test_eq(self):
        self.assertEqual(self.p1 == self.p2, False)
        self.assertEqual(self.p6 == self.p7, True)
        self.assertEqual(self.p3 == self.p4, False)

    def test_nq(self):
        self.assertEqual(self.p1 != self.p2, True)
        self.assertEqual(self.p6 != self.p7, False)
        self.assertEqual(self.p3 != self.p4, True)

    def test_add(self):
        self.assertEqual(self.p4 + self.p5, Point(12, 21))
        self.assertEqual(self.p3 + self.p6, Point(1, 8))
        self.assertEqual(self.p7 + self.p8, Point(-4, 8))

    def test_sub(self):
        self.assertEqual(self.p4 - self.p5, Point(-2, 3))
        self.assertEqual(self.p3 - self.p6, Point(5, 0))
        self.assertEqual(self.p7 - self.p8, Point(0, 0))

    def test_mul(self):
        self.assertEqual(self.p1 * self.p2, 4)
        self.assertEqual(self.p2 * self.p3, 14)
        self.assertEqual(self.p3 * self.p4, 63)

    def test_cross(self):
        self.assertEqual(Point.cross(self.p3, self.p4), 16)
        self.assertEqual(Point.cross(self.p7, self.p8), 0)

    def test_length(self):
        self.assertEqual(Point.length(self.p3), 5)
        self.assertEqual(Point.length(self.p4), 13)

if __name__ == '__main__':
    unittest.main()