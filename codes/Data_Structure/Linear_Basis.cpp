template<int BITS>
struct linear_basis {
    array<uint64_t, BITS> basis;
    linear_basis() { basis.fill(0); }
    void add(uint64_t x) {
        for(int i = BITS - 1; i >= 0; i--) if((x >> i) & 1) {
            if(basis[i] == 0) {
                basis[i] = x;
                continue;
            }
            x ^= basis[i];
        }
    }
    bool valid(uint64_t x) {
        for(int i = BITS - 1; i >= 0; i--)
            if((x >> i) & 1) x ^= basis[i];
        return x == 0;
    }
    // max xor sum: xor sum of all basis
    // min xor sum: zero(if possible) or min_element
}; // not tested
