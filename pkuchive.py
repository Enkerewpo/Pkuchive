#-*-coding:utf-8-*-
import sys
import getopt
import os
dic = open("POJ_Html\\archive_map.arc", "r")

def procedure(dir_name) :
    dir_name = str(dir_name)
    return dict['1001'] 
def version() :
    print("")
    print("pkuchive 1.0.0 by Kvar_ispw17 with Python 2.7.13")
    print("email : enkerewpo@gmail.com")

def usage() :
        print("\npkuchive usage:")
        print("     -i [dir] : selection the directory that contains your")
        print("                problems code folders without ending with \"\\\"")
        print("     -h       : show this helping page")
        print("     -ver     : show the version of pkuchive")

if __name__=='__main__':  
    opts, args = getopt.getopt(sys.argv[1:], "hi:|ver")
    input_file = ''
    dict = {}
    for w in range(1000, 4000) :
        line = dic.readline()
        if not line:
            break
        str_full = str(line)[:-1]
        A = str(str_full[:4])
        B = str(str_full[5:])
        dict[A] = B
    for op, value in opts:
        if op == '-i' :
            input_file = value
            path = os.getcwd()
            path += '\\'
            path += input_file
            
            for dir in os.listdir(path) :
                strf = dict[dir]
                strd = dir + ' ' + strf
                strd = strd.decode('utf-8')
                os.rename(os.path.join(path, dir), os.path.join(path,strd))
        elif op == '-h' :
            usage()
            sys.exit()
        elif op == '-v' :
            version()
            sys.exit()
