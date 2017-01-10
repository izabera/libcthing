typedef struct { int quot, rem; } div_t;
div_t div(int num, int den) { return (div_t) { num / den, num % den }; }
