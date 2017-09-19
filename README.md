# pkuchive
 [![Build Status](https://travis-ci.org/enkerewpo/pkuchive.svg?branch=master)](https://travis-ci.org/enkerewpo/pkuchive)
 [![PyPI](https://img.shields.io/pypi/v/pkuchive.svg)](https://pypi.python.org/pypi/pkuchive)
 
A tool for OIer to tag the archive folder provided by PKU openjudge achieve service.

Written by [Kvar_ispw17](mailto:enkerewpo@gmail.com) on Python 2.7
## What is this ?
When you download your archive from PKU openjudge website, you will receive a folder with only problems' number in it.
Under the `pkuchive`'s help, your folder will be tag-on by the problems' titles which provides a pretty archive folder.
```
BEFORE:                                AFTER:
YOUR FOLDER                            YOUR FOLDER
   |----------- 1001                      |----------- 1001 A+B Problem
   |----------- 1002                      |----------- 1002 Exponentiation
   |----------- 1003                      |----------- 1003 487-3279
   |----------- 1004                      |----------- 1004 Hangover
   ...                                    ...
```

current version `1.0.3` release on 2017.9.16
## Setup
### 1. Get your POJ archive
Goto [PKU JudgeOnline](http://poj.org/) and login. Click the link `archive` on the right to download the `*.tgz` file.
### 2. Install pip
Goto [https://www.python.org/downloads/](https://www.python.org/downloads/) and choose __2.x version of Python__ to download.
Moreover, pip is required to install the pkuchive program. Remember to install [pip](https://pypi.python.org/pypi/pip/9.0.1).

## Installing pkuchive
type this in your shell:
```
 $ sudo pip install pkuchive
```

## Startup
everywhere in shell you can access pkuchive just by typing its name.

```
 $ pkuchive

pkuchive usage:
     -i [dir] : selection the directory that contains your
                problems code folders           
     -h       : show this helping page
     -ver     : show the version of pkuchive
```

## Change log
### 2017.9.16
  add pkuchive to pip with PyPI.
### 2017.7.6 
  fixed filename for Chinese character by using decode UTF-8 [Kvar_ispw17].
