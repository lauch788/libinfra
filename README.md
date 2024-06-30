# libinfra - C99 Utility Library

This library implements common programming utilities.
It is oriented towards the [Infra Standard](https://infra.spec.whatwg.org/).
More features will be implemented as the need arises within dependent code.

Features
--------
- Stack data structure
- Queue data structure
- Garbage-collected UTF-8 strings
- Locale-independent ASCII functions
- Locale-independent Unicode functions

Dependencies
------------
- C99 compiler
- libgrapheme

Build
-----
```$ make```

Linker Flags
------------
``pkg-config --libs libinfra``

```-linfra -lgrapheme```

