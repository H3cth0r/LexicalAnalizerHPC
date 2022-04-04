from distutils.command.build import build
import sys

from pybind11 import get_cmake_dir
# Available at setup time due to pyproject.toml
from pybind11.setup_helpers import Pybind11Extension
from setuptools import setup

__version__ = "0.0.1"

ext_modules = [Pybind11Extension(
        "hpcLexAnalizer",
        ["src/hpc_lex_analizer.cpp"],
        define_macros = [('VERSION_INFO', __version__)]
    ),
]

setup(name="python_example",
    version=__version__,
    author="Héctor Miranda",
    author_email="a01658845@tec.mx",
    url="https://github.com/H3cth0r/LexicalAnalizerHPC",
    description="library",
    long_description="",
    ext_modules=ext_modules,
    extras_require={"test":"pytest"},
    zip_safe=False,
    python_requires=">=3.6"
)