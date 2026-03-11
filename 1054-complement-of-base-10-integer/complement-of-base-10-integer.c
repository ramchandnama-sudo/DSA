int bitwiseComplement(int n) {
    return (n==0)?1:n^((1<<(32-__builtin_clz(n)))-1);
}