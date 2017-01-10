typedef struct { long quot, rem; } ldiv_t;

ldiv_t ldiv(long num, long den) { return (ldiv_t) { num / den, num % den }; }
