#include <cstdio>

#include <args.hpp>

struct Arguments : public ArgumentParser
{
    std::string              input;
    std::string              output;
    bool                     parallel = false;
    std::vector<std::string> extra;

    Arguments(int argc, const char* const* argv) : ArgumentParser("Example")
    {
        addPositional("input", input, "Input file", true);
        addString("-output", output, "Output file");
        addBool("-parallel", parallel, "Process the input on multiple threads");
        addExtra(extra);
        parseOrExit(argc, argv);
    }
};

int main(int argc, char** argv)
{
    Arguments args(argc, argv);
    printf("input: '%s'\n", args.input.c_str());
    printf("output: '%s'\n", args.output.c_str());
    printf("parallel: %s\n", args.parallel ? "yes" : "no");
    if (!args.extra.empty())
    {
        printf("extra arguments:\n");
        for (const auto& arg : args.extra)
        {
            printf("  '%s'\n", arg.c_str());
        }
    }
    return EXIT_SUCCESS;
}
