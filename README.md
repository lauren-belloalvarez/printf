# 0x11. C - printf

## Project Description
This is a custom implementation of the famous `printf` function found in the C standard library. The project is designed to mirror the basic functionalities of the original function, allowing the user to format and print data to the standard output.

## Functionality Overview
Our `printf` function supports various format specifiers, such as:

- %c: Character
- %s: String
- %d or %i: Integer
- %b: Binary representation of an integer

Through these format specifiers, users can craft detailed and customized outputs based on their requirements.

### How to Start it

These instructions will get you a copy of the project up and running on your local machine (Linux distro) for development and testing purposes.

### Installing

You will need to clone the repository of the project. This will contain the `printf` function and all of its dependencies.

```
git clone https://github.com/lauren-belloalvarez/printf.git
```
### How to Use it

To use our custom `printf` function:

1. Include the `main.h` header in your main program.
2. Call the function `_printf` just like you would with the original `printf`.

Example:
```
#include "main.h"

int main(void)
{
    _printf("Hello, %s!", "World");
    return (0);
}
```
### Arguments

Most format specifiers have specific requirements for their associated arguments. Ensure the argument passed matches the expected data type for the format specifier.

Example:
```
_printf("This is a character: %c and this is a number: %d", 'A', 100);
```


## Authors

- Lauren Bello Alvarez

- [Emmanuel Oyibo](https://github.com/Emminex23)
