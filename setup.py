from setuptools import setup

import pkuchive

setup(
    name='pkuchive',
    packages=['pkuchive'],
    version='1.0.8',
    description='A tool for OIer to tag the archive folder provided by PKU openjudge (POJ) archive service.',
    author='Kvar_ispw17',
    author_email='enkerewpo@gmail.com',
    url='https://github.com/enkerewpo/pkuchive',
    download_url='https://github.com/enkerewpo/pkuchive/releases/download/1.0.1/pkuchive_release_1.0.2_20170916.tar.gz',
    keywords=['acm-icpc', 'noip', 'noi', 'openjudge '],
    license="GPL3",
    classifiers=[
         "Programming Language :: Python :: 2.7",
    ],
    data_files=[('pkuchive_data', ['pkuchive/archive_map.arc'])],
    entry_points={
        "console_scripts": [
            "pkuchive = pkuchive.__main__:main",
        ],
    },
)
