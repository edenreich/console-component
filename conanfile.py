from conans import ConanFile, CMake
from conans.tools import download, unzip
import os


class ConsolePackage(ConanFile):
    name = "console-component"
    version = "1.0.2"
    license = "MIT"
    author = "Eden Reich <eden.reich@gmail.com>"
    url = "https://github.com/edenreich/console-component"
    description = "An easy to use component for building powerful console applications written in C++"
    topics = (
        "cpp", "cpp14", "console", 
        "console-component", "cli", 
        "command-line", "commandline", 
        "cmake", "cross-platform", 
        "cpp-component", "cpp17"
    )
    homepage = "https://github.com/edenreich/console-component"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    cmake = None
    options = {"shared": [True, False]}
    default_options = {"shared": False}

    def build(self):
        zip_binaries = "binaries_{}.zip".format(self.version)
        zip_includes = "includes_{}.zip".format(self.version)
        download("https://github.com/edenreich/console-component/releases/download/v{}/binaries.zip".format(self.version), zip_binaries, retry=3, retry_wait=5)
        download("https://github.com/edenreich/console-component/releases/download/v{}/includes.zip".format(self.version), zip_includes, retry=3, retry_wait=5)
        unzip(zip_binaries, "dist/lib")
        unzip(zip_includes, "dist/include")
        os.unlink(zip_binaries)
        os.unlink(zip_includes)

        cmake = CMake(self)
        cmake.configure()
        cmake.install()
        self.copy("*", dst="include", src="dist/include")
        self.copy("*", dst="lib", src="dist/lib")

    def package(self):
        self.copy("*")
        

    def package_info(self):
        self.cpp_info.libs = ["console-component"]
