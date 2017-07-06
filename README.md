# pkuchive
A tool for OIer to tag the archive folder provided by PKU openjudge achieve service.

Written by [Kvar_ispw17](mailto:enkerewpo@gmail.com) on Python 2.7.13

current version `1.0.1` release on 2017.7.6
## Setup
### 1. Get your POJ archive
Goto [PKU JudgeOnline](http://poj.org/) and login. Click the link `archive` on the right to download the `*.tgz` file.
### 2. Download Python
Goto [https://www.python.org/downloads/](https://www.python.org/downloads/) and choose either version of Python to download.
Python is required to run the pkuchive program. Remember to install Python.
### 3. Get release of pkuchive
Visit [https://github.com/Enkerewpo/pkuchive/releases](https://github.com/Enkerewpo/pkuchive/releases) to get pkuchive's latest version.
Once you have unziped the release file at some dirctory on you computer, __that dirctory__ will stayed being your __work dir__.

## Using pkuchive
1. Copy the folder fully to the root of your __work dir__ which contains the `pkuchive.py` file.
Let your folder just in that dir. Like the `example` folder provide with pkuchive.
2. run command:
   
   `python pkuchive.py -i [inputdir]`
   *inputdir* is the folder that contains your poblems folder.
3. enjoy!

## Change log
### 2017.7.6 
  fixed filename for Chinese character by using decode UTF-8 [Kvar_ispw17].
