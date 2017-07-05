import sys
import getopt

def usage() :
        print("pkuchive usage:")
        print("     -i [dir] : selection the directory that contains your problems code folders")

if __name__=='__main__':  
    opts, args = getopt.getopt(sys.argv[1:], "hi:")
    input_file = ''
    for op, value in opts:
        if op == '-i' :
            input_file = value
        elif op == '-h' :
            usage()
            sys.exit()
