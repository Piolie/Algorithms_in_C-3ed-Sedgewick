MAKE NOTES
----------

To write the makefiles, I followed the guide at

- [A Simple Makefile Tutorial](https://cs.colby.edu/maxwell/courses/tutorials/maketutor/)

Even though this exercises are all small projects, I've run into some dependency issues while trying to build them.
For example, in E03.10, I had to `#include "Point.h"` inside _triangle.h_, so that it would be available for _triangle.h_ and for _E03.10.c_ when it includes it. Relying on this hidden dependency is bad practice: there is potential for double includes and missing headers.
For E03.10, two possible solutions are:
- Add header guards to _Point.h_, and include it wherever it is needed. The guards will prevent double includes and the dependencies will be more explicit.
- Extend _triangle.h_ to include the point definition and don't include point. I'll go with that.
