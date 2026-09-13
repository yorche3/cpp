cc_library(
    name = "naive_sort_lib",
    srcs = ["src/naive_sort.cpp"],
    hdrs = ["include/naive_sort.h"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "naive_sort_tests",
    size = "small",
    srcs = ["tests/naive_sort_test.cpp"],
    deps = [
        ":naive_sort_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
