// Last updated: 10/12/2026, 9:54:51 PM
bool isPowerOfTwo(int n) {
    return n>0 && (n & (n-1)) == 0;
}