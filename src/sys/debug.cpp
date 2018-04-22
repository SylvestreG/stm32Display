#include <vector>

Vector<int> vec;
Vector<char *> vec2;

Vector<char *> debug()
{
  Vector<char *> *p;
  p = &vec2;

  p = new Vector<char *>;

  return *p;
}
