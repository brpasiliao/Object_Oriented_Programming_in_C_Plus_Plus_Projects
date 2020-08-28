bool test(int *q, int c) {
  for (int i = 0; i < c; i++)
    if (*(q+i) == *(q+c) || ((c - i) == abs(*(q+c) - *(q+i)))) return false;
  return true;
}

int queens(int n) {
  int *q = new int[8], a = 0, c = -1;

  while (true) { // column loop
    c++;

    if (c > (n-1)) {
      a++;
      c--;
    }
    else q[c] = -1;

    while (true) { // row loop
      q[c]++;

      if (q[c] > (n-1)) {
        c--;
        if (c < 0) {
          delete[]q;
          return a;
        }
      }
      else if (test(q, c)) break;
    }
  }
}

int main() {
  int n = 12;
  for (int i = 1; i <= n; ++i)
    cout << "There are " << queens(i)
    << " solutions to the " << i << " queens problem.\n";
  return 0;
}
