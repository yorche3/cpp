cc_library(
    name = "data_structures_basics_lib",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "data_structures_basics_tests",
    size = "small",
    srcs = ["tests/data_structures_basics_test.cpp"],
    deps = [
        ":data_structures_basics_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
