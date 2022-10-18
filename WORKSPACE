workspace(name = "main")


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")



########################################
# source dependencies built with CMake #
########################################

_ALL_CONTENT = """\
filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)
"""

# Setup rules_foreign_cc (CMake integration)
http_archive(
    name = "rules_foreign_cc",
    strip_prefix = "rules_foreign_cc-8d540605805fb69e24c6bf5dc885b0403d74746a", # 0.9.0
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/8d540605805fb69e24c6bf5dc885b0403d74746a.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()


#VTK
http_archive(
    name = "vtk",
    build_file_content = _ALL_CONTENT,
    sha256 = "276f35541a46ef5963ae6667ee60b9cb19c9dc5cb28ae68db71fd8577620b0fc",
    strip_prefix = "VTK-9.2.0.rc2",
    urls = ["https://www.vtk.org/files/release/9.2/VTK-9.2.0.rc2.tar.gz"],
)

# arrayfire
http_archive(
      name = "arrayfire",
      build_file_content = _ALL_CONTENT,
      sha256 = "2d01b35adade2433078f57e2233844679aabfdb06a41e6992a6b27c65302d3fe",
      strip_prefix = "arrayfire-full-3.8.2",
      urls = ["https://github.com/arrayfire/arrayfire/releases/download/v3.8.2/arrayfire-full-3.8.2.tar.bz2"],
)

# oneDNN
http_archive(
      name = "oneDNN",
      build_file_content = _ALL_CONTENT,
      sha256 = "0ff70240378aa26e1fc3edf66d14964e614ef2f9278514182cd43b34ced9af21",
      strip_prefix = "oneDNN-2.6.1",
      urls = ["https://github.com/oneapi-src/oneDNN/archive/refs/tags/v2.6.1.tar.gz"],
)

# flashlight
http_archive(
      name = "flashlight",
      build_file_content = _ALL_CONTENT,
      sha256 = "6557f65ef2fbacc867bb6721d9134d0bc15d29e7413cbce0ae5e28d857164029",
      strip_prefix = "flashlight-0.3.2",
      urls = ["https://github.com/flashlight/flashlight/archive/refs/tags/v0.3.2.tar.gz"],
);