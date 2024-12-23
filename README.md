# Immolate
A derivative of MathIsFun0's [OpenCL seed searcher for Balatro](https://github.com/MathIsFun0/Immolate/) made in C.

It is _significantly slower_, but if you are just looking for a quick seed, can save the overhead of compiling for several minutes.

## Building and running

You can configure and build with whatever CMake generator you wish, but here's a few ways about it if you don't have one already figured out.

### Windows Visual Studio
1. Install Visual Studio
2. Open the project folder
3. Configure the filter source file
  
   ![image](https://github.com/user-attachments/assets/b9a99554-5c78-49ca-a602-81c59a6d049f)

4. Set the starting seed and filter file in **Project > CMake Settings for Immolate**

   ![image](https://github.com/user-attachments/assets/88e2f7ee-e229-40ab-b080-c10dc6c72517)
   Also, make sure Debug is selected

   > Note: You can set the seed to a blank value.
5. Hit the green play button at the top of Visual Studio

### Windows Command Line
Install cmake:
```
winget install --id Kitware.CMake
```

Install Visual Studio 2022 Build Tools:
```
winget install Microsoft.VisualStudio.2022.BuildTools --force --override "--wait --passive --add Microsoft.VisualStudio.Workload.VCTools --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 --add Microsoft.VisualStudio.Component.Windows11SDK.22000"
```

Open the _x64 Native Tools Command Prompt for VS 2022_

Build:
```
cmake -DIMMOLATE_SEED="" -DIMMOLATE_FILTER="filters/perkeo_observatory.c" -G "Visual Studio 17 2022" -A x64 -B build
cmake --build .\build --config Debug
```
> Note: Build for **Debug**. Release is optimizing out important code for some reason.

Run:
```
.\build\Debug\Immolate.exe
```

### Linux (Debian)
Install dependencies:

```
sudo apt-get install cmake build-essential
```

Build:
```
cmake -DIMMOLATE_SEED="" -DIMMOLATE_FILTER="filters/perkeo_observatory.c" -B build
cmake --build ./build --config Debug
```
> Note: Build for **Debug**. Release is optimizing out important code for some reason.

Run:
```
./build/Immolate
```

## Future Plans
- None currently
