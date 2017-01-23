#define weak(x) typeof(x) __attribute__((weak,alias("weak"#x))) x
