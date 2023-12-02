import unittest
from singlelist import *


class TestSingleList(unittest.TestCase):

    def test_remove_tail(self):
        list1 = SingleList()
        list1.insert_head(Node(7))
        list1.insert_head(Node(2))
        list1.insert_head(Node(1))

        self.assertEqual(list1.remove_tail().data, 7)
        self.assertEqual(list1.remove_tail().data, 2)
        self.assertEqual(list1.remove_tail().data, 1)
        self.assertEqual(list1.head, None)
        self.assertEqual(list1.length, 0)

        with self.assertRaises(ValueError):
            list1.remove_tail()

    def test_join(self):
        list1 = SingleList()
        list1.insert_head(Node(1))
        list1.insert_head(Node(2))
        list1.insert_head(Node(3))

        list2 = SingleList()
        list2.insert_head(Node(4))
        list2.insert_head(Node(5))
        list2.insert_head(Node(6))

        list1.join(list2)

        self.assertEqual(list1.head.data, 3)
        self.assertEqual(list1.tail.data, 4)
        self.assertEqual(list1.length, 6)
        self.assertEqual(list2.head, None)
        self.assertEqual(list2.tail, None)
        self.assertEqual(list2.length, 0)

if __name__ == '__main__':
    unittest.main()