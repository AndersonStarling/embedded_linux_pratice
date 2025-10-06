# 🧩 C Static & Shared Library Build Project

A minimal yet complete **C project** demonstrating how to build both **static (`.a`)** and **shared (`.so`)** libraries using **Makefile** on Linux.  
This project showcases modular design, reusable components, and build automation for scalable embedded or system-level applications.

## 📁 Project Structure

```
01/
├── app/
│ └── main.c # Application entry
├── lib/
│ ├── src/
│ │ ├── bstrutils.c # Library source
│ │ └── strutils.h # Library header
│ └── test/
│ └── main.c # Unit test for library
├── Makefile # Build automation
└── readme.md # Project documentation
```

## ⚙️ Build Targets

```
| Command | Description |
|----------|--------------|
| `make all` | Build both static and shared versions |
| `make static` | Build app linked with static library (`.a`) |
| `make shared` | Build app linked with shared library (`.so`) |
| `make run_static_app` | Run the static-linked application |
| `make run_shared_app` | Run the shared-linked application |
| `make test_lib` | Build and run the unit test for library |
| `make clean` | Clean all build artifacts |
```

## 🏗️ Output Directory Structure

After build, all outputs are stored in `output/`:

```
output/
├── app/
│ ├── static_app/ # Static linked binary
│ └── shared_app/ # Shared linked binary
├── lib/
│ ├── static_lib/ # Static library (.a)
│ └── shared_lib/ # Shared library (.so)
├── obj/
│ ├── static/ # Object files for static build
│ └── shared/ # Object files for shared build
└── test/ # Unit test binary & objects
```

## 🧠 Key Features
- Separate build for **static** and **shared** libraries.  
- Clean folder structure with modular Makefile targets.  
- Simple **unit test system** for library verification.  
- Easy to extend for larger embedded or Linux system projects.  

---

## 🧪 Example Usage

### Build static version

```
make static
```

### Build shared version

```
make shared
```

### Run library test

```
make test_lib
```

## 🧰 Toolchain

Compiler: GCC
OS: Linux / Ubuntu
Build system: GNU Make



