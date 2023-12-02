import unittest
from fracs import *
 
class TestFractions(unittest.TestCase):

    def setUp(self):
        self.zero = [0, 1]
        self.undefined = [0, 0]
        self.f1 = [1, 2]
        self.f2 = [1, 3]
        self.f3 = [-4, 9]
        self.f4 = [8, -11]
        self.f5 = [21, 4]
        self.f6 = [3, 6]
        self.f7 = [-8, 11]

    def test_add_frac(self):
        self.assertEqual(add_frac(self.f1, self.f2), [5, 6])
        self.assertEqual(add_frac(self.zero, self.f2), [1, 3])
        self.assertEqual(add_frac(self.f2, self.f3), [-1, 9])

    def test_sub_frac(self):
        self.assertEqual(sub_frac(self.f1, self.f2), [1, 6])
        self.assertEqual(sub_frac(self.zero, self.f2), [-1, 3])
        self.assertEqual(sub_frac(self.f2, self.f3), [7, 9])

    def test_mul_frac(self):
        self.assertEqual(mul_frac(self.f4, self.f5), [168, -44])
        self.assertEqual(mul_frac(self.zero, self.f2)[0], 0)
        self.assertEqual(mul_frac(self.f5, self.f6), [63, 24])

    def test_div_frac(self):
        self.assertEqual(div_frac(self.f1, self.f2), [3, 2])
        self.assertEqual(div_frac(self.f6, self.f2), [9, 6])
        self.assertEqual(div_frac(self.f2, self.f3), [9, -12])

    def test_is_positive(self):
        self.assertTrue(self.f1, True)
        self.assertTrue(self.f3, False)
        self.assertTrue(self.f6, True)

    def test_is_zero(self):
        self.assertTrue(self.zero, True)
        self.assertTrue(self.undefined, False)
        self.assertTrue(self.f1, False)

    def test_cmp_frac(self):
        self.assertEqual(cmp_frac(self.f1, self.f2), 1)
        self.assertEqual(cmp_frac(self.f1, self.f6), 0)
        self.assertEqual(cmp_frac(self.f1, self.f6), 0)
        self.assertEqual(cmp_frac(self.f3, self.zero), -1)
        self.assertEqual(cmp_frac(self.f4, self.f7), 0)

    def test_frac2float(self):
        self.assertAlmostEqual(frac2float(self.f1), 0.500, places=3)
        self.assertAlmostEqual(frac2float(self.f2), 0.333, places=3)
        self.assertAlmostEqual(frac2float(self.f4), -0.727, places=3)

    def tearDown(self): pass

if __name__ == '__main__':
    unittest.main()
