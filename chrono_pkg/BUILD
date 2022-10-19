load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
    name = "chrono",
    hdrs = [
        "cc/chrono.h",
    ],
    srcs = [
        "cc/chrono.cpp",
    ],
    visibility = ["//visibility:public"],
)





load("@rules_pkg//pkg:deb.bzl", "pkg_deb")
load("@rules_pkg//pkg:tar.bzl", "pkg_tar")
load("@rules_pkg//:pkg.bzl", "pkg_zip")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar")

"""
pkg_tar(
    name = "chrono_tar",
    srcs = [
        ":chrono",
    ],
    mode = "0644",
    package_dir = "/usr/lib",
)

pkg_tar(
    name = "chrono_tar_1",
    extension = "tar.gz",
    deps = [
        ":chrono_tar",
    ],
)

pkg_zip(
    name = "test_zip_basic",
    srcs = [
        "cc/chrono.h",
        "cc/chrono.cpp",
    ],
)
"""





pkg_tar(
    name = "chrono-tar",
    strip_prefix = "/cc",
    package_dir = "/tmp",
    srcs = [
        ":chrono",
    ],
    mode = "0755",
)

pkg_tar(
    name = "deb-data",
    extension = "tar.gz",
    deps = [
        ":chrono-tar",
    ],
)

pkg_deb(
    name = "chrono-deb",
    architecture = "amd64",
    built_using = "unzip",
    data = ":deb-data",
    depends = [
        "unzip",
    ],
    description = "A simple C++ chrono library",
    maintainer = "John Doe",
    package = "chrono",
    version = "1.0.0",
)
