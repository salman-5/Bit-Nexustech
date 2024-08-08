# Bit - File Watcher and Version Control

## Overview

**Bit** is a file watcher and version control utility designed to monitor changes in a directory. It tracks created, modified, and deleted files, allowing you to commit changes with messages and timestamps. This tool maintains a history of changes in a versioned format, enabling you to view and revert to previous states of the monitored directory.

## Features

- Monitors a specified directory for file changes.
- Tracks created, modified, and deleted files.
- Supports committing changes with messages and timestamps.
- Maintains a history of changes in versioned text files.
- Allows listing of all committed versions.

## Installation

### Prerequisites

- **CMake**: To build the project.
- **C++17**: Required for compiling the source code.
- **GCC/Clang/Other C++ compiler**: For building the executable.

### Building from Source

   ```bash
  mkdir build
  cd build
  cmake ..
  make
````
### Usage

   ```bash
    /path/to/executable/bit /home/user/my_project
