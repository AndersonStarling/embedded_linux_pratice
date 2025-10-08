# 🔍 FileStat Utility – File Information Inspector

A simple but powerful **C program** that demonstrates how to access and analyze file metadata using the **`fstat()`** API in Linux.  
The program provides essential file information such as **file size, type (regular file, directory, symbolic link)**, and **last modification time** — all via the standard POSIX file handling mechanism.

---

## 📙 Overview

This project showcases how to:
- Use **system call APIs** like `open()`, `fstat()`, `close()`.
- Extract and interpret **file attributes** (`st_mode`, `st_size`, `st_mtime`, etc).
- Apply **bitwise checking macros**: `S_ISREG`, `S_ISDIR`, `S_ISLNK` for file type.
- Print human-readable timestamps using `ctime()`.

The utility is a lightweight example for **file operations in embedded or Linux-based systems** — useful for diagnostics, debugging, and system analysis.

---

## 📁 Project Structure

```
02/
├── filestat.c # Core application logic
├── Makefile   # Build automation
├── .gitignore # Ignore build outputs
├── output/    # Output folder for compiled binaries
├── README.md  # Documentation
```

## ⚙️ Build & Run

### 🔹 Build the program
```
make all
```

### 🔹 Run the program
```
make run
```

Output example:

```
File: /etc/hostname
Size: 232    Regular File
Modify: Thu, 14 Sep 2023 14:35:02
```

# 🧠 Key Features

- Demonstrates fstat() – a key Linux system API.
- Shows how to check file types using bitwise macros.
- Displays human-readable modification time.
- Handles errors gracefully (missing file, permission issues, etc).
- Portable across all POSIX-based systems (Linux / Unix / macOS).

# 🧰 Toolchain

- Compiler: GCC
- OS: Ubuntu 22.04 / Linux
- Build System: Makefile

# 🚀 Future Enhancements

- Add more detailed attributes (permissions, ownership, access time).
- Add colorized output for better readability.
- Extend to support recursively scan directories.
- Add command-line options (e.g. --help, --mode, --name).