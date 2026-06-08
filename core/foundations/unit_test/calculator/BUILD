cc_library(
    name = "calculator_lib",
    srcs = ["src/calculator.cpp"],
    hdrs = ["include/calculator.h"],
    # Esto permite que los archivos incluyan el header como "calculator.h" 
    # o respeten las rutas relativas actuales.
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "calculator_test",
    size = "small",
    srcs = ["tests/calculator_tests.cpp"],
    deps = [
        ":calculator_lib",
        "@com_google_googletest//:gtest_main",
    ],
)