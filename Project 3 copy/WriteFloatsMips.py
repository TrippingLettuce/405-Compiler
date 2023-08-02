import os
import sys

def get_terminal_args()->str:
    """Returns the terminal arguments"""
    args = sys.argv[1:]
    return args[0]

def read_assembly_file()->list:
    """Reads the assembly file and returns the lines
    @param file: The assembly file
    """
    for file in os.listdir():
        if file.endswith('.asm'):
            with open(file, 'r') as f:
                lines = f.readlines()
    return lines

def ineart_float_val(lines:list, val:str)->list:
    """Inserts the float value to the lines
    @param lines: The lines to be inserted
    @param val: The value to be inserted
    """
    for i, line in enumerate(lines):
        if line.startswith('\tfval: .float'):
            lines[i] = f'\tfval: .float {val}\n'
    return lines

def over_write_mips_file(new_lines:list)->None:
    """Overwrites the mips file
    @param lines: The lines to be written
    """
    for file in os.listdir():
        if file.endswith('.asm'):
            with open(file, 'w') as f:
                f.writelines(new_lines)
                
if __name__ == '__main__':
    val = get_terminal_args()
    lines = read_assembly_file()
    new_lines = ineart_float_val(lines, val)
    over_write_mips_file(new_lines)
    
    