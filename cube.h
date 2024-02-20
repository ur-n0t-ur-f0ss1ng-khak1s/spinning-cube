//read c++ tutorial on classes
class Cube
{
  public:
  Cube(std::vector<vec3> points)
  {

  }
}
//main cube init
 std::vector<vec3> points {
    {100,100,100},
    {200,100,100},
    {200,200,100},
    {100,200,100},

    {100,100,200},
    {200,100,200},
    {200,200,200},
    {100,200,200}
  };

  std::vector<connection> connections
  {
    {0,4},
    {1,5},
    {2,6},
    {3,7},

    {0,1},
    {1,2},
    {2,3},
    {3,0},

    {4,5},
    {5,6},
    {6,7},
    {7,4},
  };

  vec3 centeroid{0,0,0};
  for(auto& p : points)
  {
    centeroid.x += p.x;
    centeroid.y += p.y;
    centeroid.z += p.z;
  }
  centeroid.x /= points.size();
  centeroid.y /= points.size();
  centeroid.z /= points.size();


