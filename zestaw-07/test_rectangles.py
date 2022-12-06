import unittest
from rectangles import Rectangle
from points import Point

class TestRectangle(unittest.TestCase):
    def setUp(self):
        self.r1 = Rectangle(0, 0, 4, 4)
        self.r2 = Rectangle(-3, -3, 3, 3)
        self.r3 = Rectangle(2, 0, 5, 9)
        self.r4 = Rectangle(2, 0, 5, 9)

    def test_init(self):
        with self.assertRaises(TypeError):
            Rectangle('aa', 5, [1, 2, 3], ()) 

        with self.assertRaises(TypeError):
            Rectangle(0, map, list, [[[]]])

        with self.assertRaises(ValueError):
            Rectangle(0, 5, 0, 4)

        with self.assertRaises(ValueError):
            Rectangle(0, -3, 4, -3)

    def test_str(self):
        self.assertEqual(str(self.r1), "[(0, 0), (4, 4)]")
        self.assertEqual(str(self.r2), "[(-3, -3), (3, 3)]")
        self.assertEqual(str(self.r3), "[(2, 0), (5, 9)]")

    def test_repr(self):
        self.assertEqual(repr(self.r1), "Rectangle[(0, 0), (4, 4)]")
        self.assertEqual(repr(self.r2), "Rectangle[(-3, -3), (3, 3)]")
        self.assertEqual(repr(self.r3), "Rectangle[(2, 0), (5, 9)]")

    def test_eq(self):
        self.assertEqual(self.r1 == self.r2, False)
        self.assertEqual(self.r2 == self.r3, False)
        self.assertEqual(self.r3 == self.r4, True)

        with self.assertRaises(TypeError):
            self.r1 == 5
        with self.assertRaises(TypeError):
            self.r1 == 3.14
        with self.assertRaises(TypeError):
            self.r1 == 'aaa'
        with self.assertRaises(TypeError):
            self.r1 == (())

    def test_nq(self):
        self.assertEqual(self.r1 != self.r2, True)
        self.assertEqual(self.r2 != self.r3, True)
        self.assertEqual(self.r3 != self.r4, False)

        with self.assertRaises(TypeError):
            self.r1 != 5
        with self.assertRaises(TypeError):
            self.r1 != 3.14
        with self.assertRaises(TypeError):
            self.r1 != 'aaa'
        with self.assertRaises(TypeError):
            self.r1 != (())

    def test_center(self):
        self.assertEqual(self.r1.center(), Point(2, 2))
        self.assertEqual(self.r2.center(), Point(0, 0))
        self.assertEqual(self.r3.center(), Point(3.5, 4.5))

    def test_area(self):
        self.assertEqual(self.r1.area(), 16)
        self.assertEqual(self.r2.area(), 36)
        self.assertEqual(self.r3.area(), 27)

    def test_move(self):
        self.r1.move(1, 2)
        self.assertEqual(self.r1.pt1, Point(1, 2))
        self.assertEqual(self.r1.pt2, Point(5, 6))

        self.r2.move(3, 5)
        self.assertEqual(self.r2.pt1, Point(0, 2))
        self.assertEqual(self.r2.pt2, Point(6, 8))

        self.r3.move(-5, -5)
        self.assertEqual(self.r3.pt1, Point(-3, -5))
        self.assertEqual(self.r3.pt2, Point(0, 4))

        with self.assertRaises(TypeError):
            self.r1.move('aaa', [[]])
        with self.assertRaises(TypeError):
            self.r1.move(-4, '-4')
        with self.assertRaises(TypeError):
            self.r1.move(15.5, list)
        with self.assertRaises(TypeError):
            self.r1.move('44', 17)

    def test_intersection(self):
        self.assertEqual(Rectangle(0, 0, 4, 4).intersection(Rectangle(1, 1, 5, 5)),
                         Rectangle(1, 1, 4, 4))
        
        with self.assertRaises(ValueError):
            Rectangle(10, 20, 40, 50).intersection(Rectangle(1, 1, 5, 5))

    def test_cover(self):
        self.assertEqual(Rectangle(0, 0, 4, 4).cover(Rectangle(1, 1, 5, 5)),
                         Rectangle(0, 0, 5, 5))

        with self.assertRaises(TypeError):
            self.r1.cover(5)

    def test_make4(self):
        self.assertEqual(Rectangle(0, 0, 4, 4).make4(),
                        (
                            Rectangle(0, 2, 2, 4),
                            Rectangle(2, 2, 4, 4),
                            Rectangle(2, 0, 4, 2),
                            Rectangle(0, 0, 2, 2)
                        ))
    
if __name__ == '__main__':
    unittest.main()