# Building Guide

This guide will help you build the project on your local machine. The process will require you to provide two items:
- A decompressed ROM of the US version of the game.
- An elf file created from [this commit](https://github.com/zeldaret/mm/tree/23beee0717364de43ca9a82957cc910cf818de90) of the Majora's Mask decompilation.

We'll walk you through acquiring these, running the required processes and finally building the project.

## 1. Clone the Zelda64Recomp Repository
This project makes use of submodules so you will need to clone the repository with the `--recurse-submodules` flag.

```bash
git clone --recurse-submodules
# if you forgot to clone with --recurse-submodules
# cd /path/to/cloned/repo && git submodule update --init --recursive
```

## 2. Install Dependencies

You will need a few dependencies. For Linux we provide the instructions for Ubuntu, but you can find the equivalent packages for your preferred distro.

```bash
# For Ubuntu, simply run:
sudo apt-get install cmake ninja libsdl2-dev libgtk-3-dev lld llvm clang-15

# For Windows, you can use Chocolatey:
choco cmake install ninja sdl2 gtk3 llvm
```

## 3. Creating the ELF file & decompressed ROM
You will need to build [this commit](https://github.com/zeldaret/mm/tree/23beee0717364de43ca9a82957cc910cf818de90) of the Majora's Mask decompilation. Follow their build instructions to generate the ELF file and decompressed ROM. While building you may get the following build error:
```bash
RuntimeError: 'jr' instruction does not have an 'jump label' field
```

To fix this you will have to modify the problematic file `tools/disasm/disasm.py` at line 1115. Replace the line:
```diff
- elif insn.isJump():
+ elif insn.isJumpWithAddress():
```

Upon successful build it will generate the two required files. Copy them to the root of the Zelda64Recomp repository:
- `mm.us.rev1.rom_uncompressed.elf`
- `mm.us.rev1.rom_uncompressed.z64`

## 4. Generating the C code

Now that you have the required files, we have to build [N64Recomp](https://github.com/Mr-Wiseguy/N64Recomp) and run it to generate the C code to be compiled. The building instructions can be found in that repo. That will build the executables: `N64Recomp` and `RSPRecomp` which you should copy to the root of the Zelda64Recomp repository.

After that, go back to the repository root, and run the following commands:
```bash
./N64Recomp[.exe] us.rev1.toml
./RSPRecomp[.exe] aspMain.us.rev1.toml
./RSPRecomp[.exe] njpgdspMain.us.rev1.toml
```

## 5. Building the Project

Finally, you can build the project! We'll use be using CMake:
```bash
cmake -S . -B cmake-build -G Ninja -DCMAKE_BUILD_TYPE=Release # or Debug if you want to debug
cmake --build build-cmake --target Zelda64Recompiled -j$(nproc) --config Release # or Debug
```

## 6. Profit

Voilà! You should now have a `Zelda64Recompiled[.exe]` file in the `build-cmake` directory!

_Note: In the game itself, you should be using a standard ROM, not the decompressed one._