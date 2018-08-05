class BigInt {
public:
  static const int MAXDIGITS = 2600; // 1000! < 10^2600

  vector<int> digits;
  int numdigits;

  void init() {
    digits.assign(MAXDIGITS, 0);
    numdigits = 1;
  }

  // CONSTUCTORS

  BigInt() {
    init();
  }

  template<typename T>
  BigInt(const T& x) {
    init();
    assign(x);
  }

  // OPERATORS

  template<typename T> BigInt&  operator =  (const T &rhs)       { return assign(rhs);                    }
  template<typename T> bool     operator == (const T &rhs) const { return *this == BigInt(rhs);           }
  template<typename T> bool     operator != (const T &rhs) const { return !(*this == rhs);                }
  template<typename T> bool     operator <  (const T &rhs) const { return *this < BigInt(rhs);            }
  template<typename T> bool     operator >  (const T &rhs) const { return !(*this < rhs && *this == rhs); }
  template<typename T> bool     operator <= (const T &rhs) const { return !(*this > rhs);                 }
  template<typename T> bool     operator >= (const T &rhs) const { return !(*this < rhs);                 }
  template<typename T> BigInt&  operator += (const T &rhs)       { return add(rhs);                       }
  template<typename T> BigInt   operator +  (const T &rhs)       { return (*this) += rhs;                 }
  template<typename T> BigInt&  operator *= (const T &rhs)       { return multiply(rhs);                  }
  template<typename T> BigInt   operator *  (const T &rhs)       { return (*this) *= rhs;                 }
  template<typename T> BigInt&  operator << (const T d   )       { return leftshift(d);                   }

  bool operator == (const BigInt &rhs) const {
    if (rhs.numdigits != numdigits) return false;
    for (int j = MAXDIGITS-numdigits; j < MAXDIGITS; ++j)
      if (digits[j] != rhs.digits[j]) return false;
    return true;
  }

  bool operator < (const BigInt &rhs) const {
    if (rhs.numdigits != numdigits) return numdigits < rhs.numdigits;
    for (int j = MAXDIGITS-numdigits; j < MAXDIGITS; ++j)
      if (digits[j] != rhs.digits[j])
        return digits[j] < rhs.digits[j];
    return false;
  }

  friend ostream& operator << (ostream& out, BigInt& b);

  // REAL OPERATORS

  template<typename T>
  BigInt& assign(const T &x) {
    T y = x;
    int j = MAXDIGITS-1;
    while (1) {
      digits[j] = y % 10;
      y /= 10;
      if (y == 0) break;
      ++numdigits;
    }
    return *this;
  }

  BigInt& assign(const string b) {
    numdigits = b.length();
    for (int j = MAXDIGITS-1; j >= MAXDIGITS-numdigits; --j)
      digits[j] = b[j] - '0';
    return *this;
  }

  BigInt& assign(const BigInt& b) {
    numdigits = b.numdigits;
    for (int j = MAXDIGITS-1; j >= MAXDIGITS-numdigits; --j)
      digits[j] = b.digits[j];
    return *this;
  }

  template<typename T>
  BigInt& add(const T &rhs) {
    return add(BigInt(rhs));
  }

  BigInt& add(const BigInt &rhs) {
    int i = 0, j = MAXDIGITS-1;
    while (i < rhs.numdigits) {
      digits[j] += rhs.digits[j];
      if (digits[j] > 9) {
        digits[j] -= 10;
        ++digits[j-1];
      }
      ++i, --j;
    }
    numdigits = max(numdigits, rhs.numdigits);
    if (digits[MAXDIGITS-numdigits-1] > 0) ++numdigits;
    return *this;
  }

  BigInt& leftshift(const int d) {
    if (numdigits == 1 && digits[MAXDIGITS-1] == 0) return *this;
    for (int j = MAXDIGITS-numdigits; j < MAXDIGITS; ++j)
      swap(digits[j-d], digits[j]);
    numdigits += d;
    return *this;
  }

  template<typename T>
  BigInt& multiply(const T &rhs) {
    return multiply(BigInt(rhs));
  }

  BigInt& multiply(const BigInt &rhs) {
    BigInt help(*this);
    BigInt ans(0);
    for (int j = MAXDIGITS-1; j >= MAXDIGITS-rhs.numdigits; --j) {
      for (int k = 0; k < rhs.digits[j]; ++k)
        ans.add(help);
      help.leftshift(1);
    }
    assign(ans);
    return *this;
  }

};

ostream& operator << (ostream& out, BigInt& b) {
  for (int i = b.MAXDIGITS - b.numdigits; i < b.MAXDIGITS; ++i)
    out << b.digits[i];
  return out;
}
