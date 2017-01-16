#include <sys/types.h>

long setresgid(uid_t, uid_t, uid_t);
long setegid(gid_t id) { return setresgid(-1, id, -1); }
