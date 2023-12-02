import pytest
from rectangles import Rectangle
from points import Point


def test_from_points():
    p1, p2 = Point(3, 4), Point(5, 12)
    assert str(Rectangle.from_points((p1, p2))) == '[(3, 4), (5, 12)]'
    assert repr(Rectangle.from_points((p1, p2))) == 'Rectangle[(3, 4), (5, 12)]'
    assert Rectangle.from_points((p1, p2)) == Rectangle(3, 4, 5, 12)


def test_properties():
    r = Rectangle(3, 6, 5, 11)
    assert r.top == 11
    assert r.bottom == 6
    assert r.left == 3
    assert r.right == 5
    assert r.width == 2
    assert r.height == 5
    assert r.top_left == Point(3, 11)
    assert r.top_right == Point(5, 11)
    assert r.bottom_left == Point(3, 6)
    assert r.bottom_right == Point(5, 6)
    assert r.center == Point(4, 8.5)

if __name__ == '__main__':
    pytest.main()