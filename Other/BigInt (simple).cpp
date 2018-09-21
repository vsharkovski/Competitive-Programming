int MAXDIGITS = 2600; // 1000! has 2568 decimal digits

class Big {
public:
  vi digits;
  int numdigits;

  void init() {
    digits.assign(MAXDIGITS, 0);
    numdigits = 1;
  }

  Big() {
    init();
  }

  Big(int x) {
    init();
    int j = MAXDIGITS-1;
    while (1) {
      digits[j] = x % 10;
      x /= 10;
      if (x == 0) break;
      ++numdigits;
    }
  }

  Big(Big& b) {
    init();
    assign(b);
  }

  void assign(Big& b) {
    numdigits = b.numdigits;
    for (int j = MAXDIGITS-1; j >= MAXDIGITS-b.numdigits; --j) {
      digits[j] = b.digits[j];
    }
  }

  bool operator<(const Big &rhs) const {
    if (rhs.numdigits != numdigits) return numdigits < rhs.numdigits;
    for (int j = MAXDIGITS-numdigits; j < MAXDIGITS; ++j) {
      if (digits[j] != rhs.digits[j]) return digits[j] < rhs.digits[j];
    }
    return false;
  }

  void add(Big &rhs) {
    int i = 0, j = MAXDIGITS-1;
    while (i < rhs.numdigits) {
      digits[j] += rhs.digits[j];
      if (digits[j] > 9) {
        digits[j] -= 10;
        ++digits[j-1];
      }
      ++i;
      --j;
    }
    numdigits = max(numdigits, rhs.numdigits);
    if (digits[MAXDIGITS-numdigits-1] > 0) ++numdigits;
  }

  void add(int rhs) {
    Big succ(rhs);
    add(succ);
  }

  void leftshift(const int d) {
    if (numdigits == 1 && digits[MAXDIGITS-1] == 0) return;
    for (int j = MAXDIGITS-numdigits; j < MAXDIGITS; ++j) {
      swap(digits[j-d], digits[j]);
    }
    numdigits += d;
  }

  void multiply(Big &rhs) {
    Big help(*this);
    Big ans(0);
    for (int j = MAXDIGITS-1; j >= MAXDIGITS-rhs.numdigits; --j) {
      for (int k = 0; k < rhs.digits[j]; ++k) {
        ans.add(help);
      }
      help.leftshift(1);
    }
    assign(ans);
  }

  friend ostream &operator<<(ostream& out, Big& b);
};

ostream &operator<<(ostream& out, Big& b) {
  for (int i = MAXDIGITS-b.numdigits; i < MAXDIGITS; ++i) {
    out << b.digits[i];
  }
  return out;
}
