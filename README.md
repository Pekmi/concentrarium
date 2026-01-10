# Concentrarium

## 🛠 Prerequisites (System Requirements)

Before building, ensure you have the following installed on your machine. You do **not** need to install libraries (GLFW/GLM) manually; they are bundled in this repository.

### Windows
* **Visual Studio 2022** (Community Edition)
    * *Workload required:* "Desktop development with C++"
* **CMake** (Version 3.25 or higher) -> [Download](https://cmake.org/download/)
* **GPU Drivers** updated to support OpenGL 4.6

### macOS
* **Xcode Command Line Tools** (`xcode-select --install`)
* **CMake** (`brew install cmake`)

### Linux (Debian/Ubuntu)
* GCC/G++ and CMake:
    ```bash
    sudo apt update
    sudo apt install build-essential cmake xorg-dev libwayland-dev libxkbcommon-dev
    ```

---

## 🚀 How to Build

We use CMake to handle the build system. Run the following commands in your terminal:

```bash
# 1. Clone the repository (if you haven't already)
git clone [https://github.com/YOUR_USERNAME/concentrarium.git](https://github.com/YOUR_USERNAME/concentrarium.git)
cd concentrarium

# 2. Create a build directory (keeps your project clean)
mkdir build
cd build

# 3. Configure the project (Generates Visual Studio solution or Makefiles)
cmake ..

# 4. Compile
cmake --build .