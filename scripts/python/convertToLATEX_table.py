import os
import sys


if __name__ == '__main__':
    # erase comma in the end of each line if it exists
    data_folder = sys.argv[1]
    for filename in os.listdir(data_folder):
        if filename.endswith('.csv'):
            with open(filename, 'r') as f:
                lines = f.readlines()
            with open(filename+".tmp", 'w') as f:
                for line in lines:
                    for c in line:
                        if c == ',':
                            f.write(' & ')
                        elif c == '\n':
                            f.write(" \\\\ " + '\n')
                        else:
                            f.write(c)
            print(f'{filename} done')
