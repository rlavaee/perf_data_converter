#include "quipper_lib.h"

#include "compat/test.h"

namespace {

TEST(QuipperLibTest, ValidOldPerfCommandLine) {
  int argc = 6;
  const char* argv[] = {"quipper", "10", "perf", "record", "-e", "cycles"};
  std::vector<std::string> perf_args;
  int perf_duration = 0;

  EXPECT_TRUE(ParseOldPerfArguments(argc, argv, &perf_duration, &perf_args));
  EXPECT_EQ(10, perf_duration);
  for (size_t i = 0; i < perf_args.size(); ++i) {
    EXPECT_EQ(argv[i + 2], perf_args[i]);
  }
}

TEST(QuipperLibTest, InValidOldPerfCommandLine) {
  int argc = 6;
  const char* argv[] = {
      "quipper", "--duration",    "10",   "--perf_path",
      "perf",    "--output_file", "file", "-- record -e cycles"};
  std::vector<std::string> perf_args;
  int perf_duration = 0;

  EXPECT_FALSE(ParseOldPerfArguments(argc, argv, &perf_duration, &perf_args));
}

}  // namespace
