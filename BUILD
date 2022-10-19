load("@rules_cc//cc:defs.bzl", "cc_binary")



cc_binary(
    name = "str2vec",
    srcs = ["cc/str2vec.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        ":arrayfire",
    ],
)


cc_binary(
    name = "mnist",
    srcs = ["cc/mnist.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        ":arrayfire",
        ":flashlight",
    ],
)


cc_binary(
    name = "tff",
    srcs = ["cc/tff.cpp"],
    visibility = ["//visibility:public"],
    linkopts = [
        "-fno-strict-aliasing",
        "-fwrapv",
        "-fexcess-precision=standard",
        "-fPIC",
        "-shared",
    ],
    linkshared=True,
    linkstatic=True,
    deps = [
        "@postgres14//:pg_headers",
    ],
)


cc_binary(
    name = "main",
    srcs = ["cc/main.cpp"],
    visibility = ["//visibility:public"],
)


#################
## cmake builds #
#################
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

# vtk
cmake(
    name = "vtk",
    cache_entries = {
        "QT_QMAKE_EXECUTABLE:PATH": "/opt/Qt/5.15.2/gcc_64/bin/qmake",
        "CMAKE_PREFIX_PATH:PATH": "/opt/Qt/5.15.2/gcc_64/lib/cmake ",
        "BUILD_SHARED_LIBS:BOOL": "ON",
        "VTK_GROUP_ENABLE_Qt:STRING": "YES",
        "VTK_Group_Qt:BOOL": "YES",
        "VTK_MODULE_ENABLE_VTK_GUISupportQt:STRING": "YES",
        "VTK_MODULE_ENABLE_VTK_GUISupportQtQuick:STRING": "YES",
        "VTK_MODULE_ENABLE_VTK_GUISupportQtSQL:STRING": "YES",
        "VTK_MODULE_ENABLE_VTK_RenderingQt:STRING": "YES",
        "VTK_MODULE_ENABLE_VTK_ViewsQt:STRING": "YES",
        "VTK_QT_VERSION:STRING": "5",
    },
    build_args = [
        "--verbose",
        "--",
        "-j `nproc`",
    ],
    lib_source = "@vtk//:all_srcs",
    #out_shared_libs = [
    #  "libaf.so", 
    #  "libaf.so.3", 
    #  "libafcpu.so",
    #  "libafcpu.so.3",
    #],
    visibility = ["//visibility:public"],
)




#################
## cmake builds #
#################
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

# arrayfire
cmake(
    name = "arrayfire",
    cache_entries = {
        "CMAKE_BUILD_TYPE": "Release",
        "AF_BUILD_CPU": "ON",
        "AF_BUILD_CUDA": "OFF",
        "AF_BUILD_OPENCL": "OFF",
        "AF_BUILD_EXAMPLES": "OFF",
        "AF_WITH_IMAGEIO": "OFF",
        "BUILD_TESTING": "OFF",
        "AF_BUILD_DOCS": "OFF",
    },
    build_args = [
        "--verbose",
        "--",
        "-j `nproc`",
    ],
    lib_source = "@arrayfire//:all_srcs",
    out_shared_libs = [
      "libaf.so", 
      "libaf.so.3", 
      "libafcpu.so",
      "libafcpu.so.3",
    ],
    visibility = ["//visibility:public"],
)

# oneDNN
cmake(
    name = "oneDNN",
    cache_entries = {
        "CMAKE_BUILD_TYPE": "Release",
        "DNNL_BUILD_EXAMPLES": "OFF",
    },
    build_args = [
        "--verbose",
        "--",
        "-j `nproc`",
    ],
    lib_source = "@oneDNN//:all_srcs",
    out_shared_libs = [
      "libdnnl.so",
      "libdnnl.so.2",
    ],
    visibility = ["//visibility:public"],
)

# flashlight
cmake(
    name = "flashlight",
    deps = [
      "//:oneDNN",
      "//:arrayfire",
    ],
    cache_entries = {
        "CMAKE_BUILD_TYPE": "Release",
        "FL_BUILD_ALL_LIBS": "ON",
        "FL_BACKEND": "CPU",
        "DNNL_DIR": "$EXT_BUILD_DEPS/oneDNN/lib/cmake/dnnl",
    },
    build_args = [
        "--verbose",
        "--",
        "-j `nproc`",
    ],
    tags = [
      "requires-network"
    ],
    lib_source = "@flashlight//:all_srcs",
    out_static_libs = ["libflashlight.a"],
    visibility = ["//visibility:public"],
)




######################
## Generate packages #
######################

load("@rules_pkg//pkg:mappings.bzl", "pkg_attributes", "pkg_filegroup", "pkg_files", "pkg_mkdirs", "strip_prefix")
load("@rules_pkg//pkg:tar.bzl", "pkg_tar")
load("@rules_pkg//pkg:zip.bzl", "pkg_zip")
load("@rules_pkg//pkg:deb.bzl", "pkg_deb")

pkg_files(
    name = "libaf",
    srcs = [
        ":arrayfire",
    ],
    prefix = "/tmp/lib/x86_64-linux-gnu",
)


#genrule(
#    name = "generate_files",
#    outs = [
#        "etc/example.conf",
#        "usr/bin/a_binary",
#    ],
#    cmd = "for i in $(OUTS); do echo 1 >$$i; done",
#)

pkg_tar(
    name = "transf",
    strip_prefix = "/cc",
    package_dir = "/tmp/bazeltest",
    srcs = ["cc/str2vec.cpp"],
    mode = "0755",
)

pkg_tar(
    name = "mnist1",
    strip_prefix = "/cc",
    package_dir = "/tmp/bazeltest1",
    srcs = ["cc/str2vec"],
    mode = "0755",
)

pkg_tar(
    name = "pack",
    extension = "tar.gz",
    deps = [
        ":transf",
        ":mnist1",
    ],
)

pkg_deb(
    name = "switch",
    architecture = "amd64",
    built_using = "unzip",
    data = ":pack",
    depends = ["unzip"],
    description = "A test package",
    package = "switch",
    version = "1.0.0",
    maintainer = "Bazel",
)