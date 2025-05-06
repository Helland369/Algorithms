# Algorithms

## Table of Contents

- [About](#About)
- [Dependencies](#Dependencies)
- [Install Catch2](#Install-Catch2)
- [Installation](#Installation)
- [Algorithms](#Algorithms)

# About

This is a simple C++ console application designed to implement and demonstrate various fundamental algorithms. It serves as a learning tool to understand algorithmic concepts and their performance characteristics.

# Dependencies

- [Openssl](https://www.openssl.org/) is used for the sha256 part.

- [Catch2](https://github.com/catchorg/Catch2) is used for testing.

- [Cmake](https://cmake.org/)

- [Ninja](https://ninja-build.org/)

# Install Catch2

Go to [this](https://github.com/catchorg/Catch2/releases/tag/v3.8.1) page download the `catch_amalgamated.cpp` and `catch_amalgamated.hpp`.

Make a directory called "external" inside the project directory:

```
cd Algorithms
```

```
mkdir external
```

Now copy the downloaded files (`catch_amalgamated.cpp` and `catch_amalgamated.hpp`) into the "external" directory inside the project directory.

# Installation

Clone this repository:

```
git clone git@github.com:Helland369/Algorithms.git
```

cd into the project directory:

```
cd Algorithms
```

run cmake:

```
cmake -G Ninja -S . -B build
```

cd build:

```
cd build
```

run ninja inside the build directory:
```
ninja
```

run the program:
```
./algorithms
```

run the test:
```
./tests
```

# Algorithms

| Name               | Big O notation       |
|--------------------|----------------------|
| Bubble sort        | O(n²)                |
| Merge sort         | O(n*log(n))          |
| Quick sort         | O(n log n) or O(n^2) |
| Binary search      | O(log n)             |
| Jump search        | O(sqrt n)            |
| Knuth-Morris-Pratt | O(n + m)             |
| Rabin-Karp         | O((n-m+1)m)          |
| SHA256             | O1 or On             |
