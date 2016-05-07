int x = 4;
int y = 5;
bool b = x < y;
bool a = false;

int func(){return 1;}

void main() {
  x = y;
  b = 2.0;
  b = 3;
  b = x;
  b = false;
  bool f = b;
  int q = b;
  q = 2.0;
  q = 3;
  x++;
  x--;
  b++;
  b--;
  ++x;
  ++b;
  x = b < x;
  x = x + x;
  x = x + b;
  b = x - b;
  b = (x == x);
  b = (b != x);
}

