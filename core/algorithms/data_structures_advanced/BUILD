cc_library(
    name = "data_structures_advanced_lib",
    srcs = ["src/data_structures_advanced.cpp"],
    hdrs = ["include/data_structures_advanced.h"],
    copts = ["-std=c++17"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "data_structures_advanced_tests",
    size = "small",
    srcs = ["tests/data_structures_advanced_test.cpp"],
    copts = ["-std=c++17"],
    deps = [
        ":data_structures_advanced_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
