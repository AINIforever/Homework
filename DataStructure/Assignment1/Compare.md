1. (&rc==&c) reutrns false, because the type of &rc is "const int *" while the type of &c is "char", they are not compatible.
2. (&ri==&i) returns true, because they are both reference of integers