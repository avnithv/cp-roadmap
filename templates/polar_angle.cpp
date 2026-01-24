tcT> cross(T x1, T x2, T y1, T y2) {
    return x1 * y2 - y1 * x2;
}

bool cmp(pi &a, pi &b) {
    int x1 = a.f, y1 = a.s, x2 = b.f, y2 = b.s;
    int ah = (y1 < 0 or (y1 == 0 and x1 < 0));
    int bh = (y2 < 0 or (y2 == 0 and x2 < 0));
    if (ah != bh) return ah < bh;
    return cross(a, b) > 0;
}
