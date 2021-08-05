from setuptools import setup, Extension

testlib = Extension(
    "testlib",
    sources=["tests/testlib.c"],
    # The important flag is -flto=auto
    extra_compile_args=["-Wall", "-Werror", "-flto=auto", "-O2"],
)

setup(
    name="tests",
    version="1.1",
    packages=["tests"],
    ext_package="tests",
    ext_modules=[testlib],
)
