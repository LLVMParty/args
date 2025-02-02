# args

Minimal header-only C++11 argument parser library for simple command line tools.

## Usage

Fetch the project in your CMakeLists.txt:

```cmake
include(FetchContent)
FetchContent_Declare(args
    GIT_REPOSITORY
        "https://github.com/LLVMParty/args"
    GIT_TAG
        v1.2
)
FetchContent_MakeAvailable(args)
```

Then inherit from `ArgumentParser` and add your flags:

```cpp
#include <cstdio>
#include "args.hpp"

struct Arguments : public ArgumentParser
{
    std::string input;
    std::string output;
    bool        parallel = false;

    Arguments(int argc, const char* const* argv) : ArgumentParser("Example")
    {
        addPositional("input", input, "Input file", true);
        addString("-output", output, "Output file");
        addBool("-parallel", parallel, "Process the input on multiple threads");
        parseOrExit(argc, argv);
    }
};

int main(int argc, char** argv)
{
    Arguments args(argc, argv);
    printf("input: '%s'\n", args.input.c_str());
    printf("output: '%s'\n", args.output.c_str());
    printf("parallel: %s\n", args.parallel ? "yes" : "no");
    return EXIT_SUCCESS;
}
```
