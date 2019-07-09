#!/usr/bin/env python2
#
# Combine generic and chip-specific .y files to stdout.
#

import sys

def print_up_to(str, f):
    while 1:
        line = f.readline()
        if not line:
            break
        if str and line[:len(str)] == str:
            break
        else:
            print line,

def main():
    y1 = open(sys.argv[1])
    y2 = open(sys.argv[2])
    
    print_up_to('%{', y1)
    print_up_to('%{', y2)
    print '%{'
    
    print_up_to('%}', y1)
    print_up_to('%}', y2)
    print '%}'    
    
    print_up_to('%%', y1)
    print_up_to('%%', y2)
    print '%%'    
    
    print_up_to('%%', y1)
    print_up_to('%%', y2)
    print '%%'    

    print_up_to(None, y1)
    print_up_to(None, y2)



if __name__ == "__main__":
    main()
