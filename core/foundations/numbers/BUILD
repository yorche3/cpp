cc_library(
    name = "numbers_lib",
    srcs = ["src/numbers.cpp"],
    hdrs = ["include/numbers.h"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "numbers_recursive_tests",
    size = "small",
    srcs = ["tests/numbers_recursive_tests.cpp"],
    deps = [
        ":numbers_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "numbers_iterative_tests",
    size = "small",
    srcs = ["tests/numbers_iterative_tests.cpp"],
    deps = [
        ":numbers_lib",
        "@com_google_googletest//:gtest_main",
    ],
)