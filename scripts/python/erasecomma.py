import os
import sys


if __name__ == '__main__':
    # erase comma in the end of each line if it exists
    data_folder = sys.argv[1]
    for filename in os.listdir(data_folder):
        if filename.endswith('.csv'):
            with open(filename, 'r') as f:
                lines = f.readlines()
            with open(filename, 'w') as f:
                for line in lines:
                    if line[-2] == ',':
                        f.write(line[:-2]+'\n')
                    else:
                        f.write(line)
            print(f'{filename} done')
