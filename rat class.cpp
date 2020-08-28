#include <iostream>
using namespace std;

class Rat{
  private:
    int n;
    int d;

  public:

    Rat(){
      n = 0;
      d = 1;
    }

    Rat(int i){
      n = i;
      d = 1;
    }

    Rat(int i, int j){
      n = i;
      d = j;
      lowestTerm(n,d);
    }

    int getN() {return n;}
    int getD() {return d;}
    void setN(int i) {
      n = i;
      lowestTerm(n,d);
      }
    void setD(int i) {
      d = i;
      lowestTerm(n,d);
    }
    void lowestTerm(int i, int j) {
      int ans = 1;
      for (int x = 2; x <= min(i, j); x++) {
        if ((i%x == 0) && (j%x == 0)) ans = x;
      }

      n = n/ans;
      d = d/ans;
    }


    Rat operator+(Rat r){
      Rat t;
      t.n = n*r.d + d*r.n;
      t.d = d*r.d;
      return t;
    }

    Rat operator-(Rat r){
      Rat t;
      t.n = n*r.d - d*r.n;
      t.d = d*r.d;
      return t;
    }

    Rat operator*(Rat r){
      Rat t;
      t.n = n*r.n;
      t.d = d*r.d;
      return t;
    }

    Rat operator/(Rat r){
      Rat t;
      t.n = n*r.d;
      t.d = d*r.n;
      return t;
    }

  friend ostream& operator<<(ostream& os, Rat r);
  friend istream& operator>>(istream& is, Rat& r);
};

ostream& operator<<(ostream& os, Rat r) {
  if (r.n < r.d) os << r.n << "/" << r.d << endl;
  else {
    if ((r.n%r.d) == 0) os << r.n/r.d << "/" << 1 << endl;
    else os << r.n/r.d << " " << r.n%r.d << "/" << r.d << endl;
  }
  return os;
}

istream& operator>>(istream& is, Rat& r) {
  is >> r.n >> r.d;
  return is;
}

int main(){
  Rat x(1,2), y(2,3), z;
  z = x+y; // 7/6
  cout << z; // 1 1/6

  x.setN(3); // 3/2
  y.setD(2); // 1/1
  z = x+y; // 5/2
  cout << z; // 2 1/2

  cin >> x; // 4 2
  cout << x; // 2/1

  z = x+5; // 7/1
  cout<<z;

  system("pause");
  return 0;
}
