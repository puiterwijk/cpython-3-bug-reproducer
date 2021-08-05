#!/usr/bin/sh -xe
python3 setup.py build_ext -i
python3 -c 'import tests.testlib'
