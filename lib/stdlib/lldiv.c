typedef struct { long quot, rem; } lldiv_t;
lldiv_t lldiv(long num, long den) { return (lldiv_t) { num / den, num % den }; }
