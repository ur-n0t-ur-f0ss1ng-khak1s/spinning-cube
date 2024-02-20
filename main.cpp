#include "screen.h"
#include "cube.h"
#include <numeric>

struct vec3
{
  float x,y,z;
};

struct connection
{
  int a,b;
};
void rotate(vec3& point, float x = 1, float y = 1, float z = 1)
{
  float rad = 0;

  rad = x;
  point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
  point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

  rad = y;
  point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
  point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;

  rad = z;
  point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
  point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;
}

void line(Screen& screen, float x1, float y1, float x2, float y2)
{
  float dx = x2 - x1;
  float dy = y2 - y1;

  float length = std::sqrt(dx * dx + dy * dy);
  float angle = std::atan2(dy,dx);

  for(float i = 0; i < length; i++)
  {
    screen.pixel(x1 + std::cos(angle) * i, y1 + std::sin(angle) * i);
  }
}

void renderCube(Cube& cube)
{
    points = cube.points;
    connections = cube.connections;
    for(auto& p : points)
    {
      p.x -= centeroid.x;
      p.y -= centeroid.y;
      p.z -= centeroid.z;
      rotate(p, 0.002, 0.001, 0.004);
      p.x += centeroid.x;
      p.y += centeroid.y;
      p.z += centeroid.z;

      screen.pixel(p.x,p.y);
      screen.pixel(p.x,p.y);
    }

    for(auto& conn : connections)
    {
      line(screen, points[conn.a].x,
                   points[conn.a].y,
                   points[conn.b].x,
                   points[conn.b].y);
    } 
}

int main()
{
  Screen screen;

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

  while(true)
  {
    renderCube(Cube);
    screen.show();
    screen.clear();
    screen.input();
    SDL_Delay(30);
  }
  return 0;
}
