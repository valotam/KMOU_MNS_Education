#include <iostream>

class Point3D {
 private:
  int x_, y_, z_;  // Private data members

 public:
  Point3D(int x = 0, int y = 0, int z = 0);  // Constructor
  int X() const;                           // Getters
  int Y() const;
  int Z() const;
  void SetX(int x);  // Setters
  void SetY(int y);
  void SetZ(int z);
  void Print() const;

  Point3D operator+(const Point3D& point) {
    int new_x = this->x_ + point.x_;
    int new_y = this->y_ + point.y_;
    int new_z = this->z_ + point.z_;

    return Point3D(new_x, new_y, new_z);
  }

  friend std::ostream& operator<<(std::ostream& ostr, const Point3D& point) {
    return ostr << "(" << point.X() << "," << point.Y() << "," << point.Z() << ")";
  }
};

int main() {
  Point3D p0(2, 5, 3);
  Point3D p1(1, 0, 2);

  Point3D p2 = p0 + p1;
  //Point3D p2(p0.X() + p1.X(), p0.Y() + p1.Y(), p0.Z() + p1.Z());
  //p2.Print();
  std::cout << p2 << std::endl;
  
  return 0;
}

// Constructor - The default values are specified in the declaration
Point3D::Point3D(int x, int y, int z)
    : x_(x), y_(y), z_(z) {}  // Using initializer list

// Getters
int Point3D::X() const { return x_; }
int Point3D::Y() const { return y_; }
int Point3D::Z() const { return z_; }

// Setters
void Point3D::SetX(int x) { this->x_ = x; }
void Point3D::SetY(int y) { this->y_ = y; }
void Point3D::SetZ(int z) { this->z_ = z; }

// Public Functions
void Point3D::Print() const {
  std::cout << "(" << x_ << "," << y_ << "," << z_ << ")" << std::endl;
}
