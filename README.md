# libinfra - C99 Utility Library

This library implements common programming utilities.
It is oriented towards the [Infra Standard](https://infra.spec.whatwg.org/).
More features will be implemented as the need arises within dependent code.

Features
--------
- Generic object interface
- Garbage-collected UTF-8 strings
- Stack data structure
- Locale-independent ASCII functions

Dependencies
------------
- C99 compiler
- libgrapheme

Build
-----
```$ make```

Linker Flags
------------
```-linfra -lgrapheme```
