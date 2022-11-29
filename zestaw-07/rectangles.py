from points import Point

class Rectangle:
    def __init__(self, x1, y1, x2, y2):
        if not all(isinstance(item, (float, int)) for item in [x1, x2, y1, y2]):
            raise TypeError("Get another data type than int and float")

        if not (x1 < x2 and y1 < y2):
            raise ValueError
        
        self.pt1 = Point(x1, y1)
        self.pt2 = Point(x2, y2)

    def __str__(self):         # "[(x1, y1), (x2, y2)]"
        return '[({}, {}), ({}, {})]'.format(self.pt1.x, self.pt1.y, self.pt2.x, self.pt2.y)

    def __repr__(self):        # "Rectangle(x1, y1, x2, y2)"
        return 'Rectangle[({}, {}), ({}, {})]'.format(self.pt1.x, self.pt1.y, self.pt2.x, self.pt2.y)

    def __eq__(self, other):   # obsługa rect1 == rect2
        if not isinstance(other, Rectangle):
            raise TypeError("Given argument is not type Rectangle, but {}".format(type(other)))
        return self.pt1 == other.pt1 and self.pt2 == other.pt2

    def __ne__(self, other):        # obsługa rect1 != rect2
        return not self == other

    def center(self):          # zwraca środek prostokąta
        return Point((self.pt1.x + self.pt2.x) / 2, (self.pt1.y + self.pt2.y) / 2)

    def area(self):            # pole powierzchni
        return abs((self.pt2.x - self.pt1.x) * (self.pt2.y - self.pt1.y))

    def move(self, x, y):      # przesunięcie o (x, y)
        if not all(isinstance(item, (float, int)) for item in [x, y]):
            raise TypeError("Get another data type than int and float")
        
        mv = Point(x, y)
        self.pt1 = self.pt1 + mv
        self.pt2 = self.pt2 + mv

    def intersection(self, other):
        if not isinstance(other, Rectangle):
            raise TypeError

        if self.pt1.x > other.pt2.x or self.pt2.x < other.pt1.x or self.pt1.y > other.pt2.y or self.pt2.y < other.pt1.y:
            raise ValueError
        else:
            return Rectangle(max(self.pt1.x, other.pt1.x), max(self.pt1.y, other.pt1.y), min(self.pt2.x, other.pt2.x), min(self.pt2.y, other.pt2.y))

    def cover(self, other):
        if not isinstance(other, Rectangle):
            raise TypeError
        
        return Rectangle(min(self.pt1.x, other.pt1.x), min(self.pt1.y, other.pt1.y), max(self.pt2.x, other.pt2.x), max(self.pt2.y, other.pt2.y))

    def make4(self):
        return (
            Rectangle(self.pt1.x, self.center().y, self.center().x, self.pt2.y),
            Rectangle(self.center().x, self.center().y, self.pt2.x, self.pt2.y),
            Rectangle(self.center().x, self.pt1.y, self.pt2.x, self.center().y),
            Rectangle(self.pt1.x, self.pt1.y, self.center().x, self.center().y)
        )
        