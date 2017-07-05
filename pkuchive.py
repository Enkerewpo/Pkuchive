import sys
import getopt
import os
dic = open("POJ_Html\\archive_map.arc", "r")
def init() :
    for w in range(1000, 4000) :
        line = dic.readline()
        if not line:
            break
        str_full = str(line)[:-1]
        

def procedure(dir_name) :
    l = 1000
    r = 4000
    tar = int(dir_name)
    


def usage() :
        print("pkuchive usage:")
        print("     -i [dir] : selection the directory that contains your problems code folders")

if __name__=='__main__':  
    opts, args = getopt.getopt(sys.argv[1:], "hi:")
    input_file = ''
    for op, value in opts:
        if op == '-i' :
            init()
            input_file = value
            path = os.getcwd()
            path += '\\'
            path += input_file
            
            for dir in os.listdir(path) :
                procedure(dir)
        elif op == '-h' :
            usage()
            sys.exit()
