import unittest
from stack import Stack

class TestStack(unittest.TestCase):
    def setUp(self):
        self.stack = Stack()

    def test_is_empty(self):
        self.assertTrue(self.stack.is_empty())
        self.stack.push(54)
        self.assertFalse(self.stack.is_empty())

    def test_is_full(self):
        self.assertFalse(self.stack.is_full())
        for i in range(5):
            self.stack.push(i)
        self.assertTrue(self.stack.is_full())

    def test_push(self):
        self.stack.push(1)
        self.assertFalse(self.stack.is_empty())
        self.assertEqual(self.stack.pop(), 1)

    def test_pop(self):
        self.stack.push(1)
        self.assertEqual(self.stack.pop(), 1)
        self.assertTrue(self.stack.is_empty())

    def test_push_too_many(self):
        for i in range(5):
            self.stack.push(i)
        with self.assertRaises(ValueError):
            self.stack.push(189)

    def test_pop_too_many(self):
        with self.assertRaises(ValueError):
            self.stack.pop()

if __name__ == '__main__':
    unittest.main()