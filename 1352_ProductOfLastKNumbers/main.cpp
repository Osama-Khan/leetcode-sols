#include <vector>

// Uses prefix product array with zero-index tracking to generate product of last k numbers.
class ProductOfNumbers {
private:
  // Array containing prefix products
  std::vector<int> pfxMults;
  // Index of last zero encountered
  int indexOfLastZero = -1;

public:
  ProductOfNumbers() { pfxMults = std::vector<int>(); }

  void add(int num) {
    int prev = 1;
    // Multiply with previous elements if pfxMults has elements
    if (!pfxMults.empty()) {
      prev = pfxMults.back();
      // Dont multiply with zero
      prev = prev == 0 ? 1 : prev;
    }
    pfxMults.push_back(prev * num);

    // Update index of 0
    if (num == 0) indexOfLastZero = pfxMults.size() - 1;
  }

  int getProduct(int k) {
    // We can check if there is a zero in range of k using last zero index,
    // in these cases, the product will be 0.
    if (indexOfLastZero >= 0 && pfxMults.size() - indexOfLastZero <= k) return 0;

    // k being size of our elements would just return the last product
    if (pfxMults.size() == k) return pfxMults.back();

    // Divide the latest prefix with the prefix just out of range of k to get
    // product of k elements.
    int divisor = pfxMults[pfxMults.size() - k - 1];
    if (divisor == 0) return pfxMults.back();
    return pfxMults.back() / divisor;
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
