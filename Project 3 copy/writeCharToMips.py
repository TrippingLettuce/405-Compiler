import os
import sys
from WriteFloatsMips import get_terminal_args, read_assembly_file, over_write_mips_file


def insert_char_val(lines:list, val:str)->list:
    """Inserts the float value to the lines
    @param lines: The lines to be inserted
    @param val: The value to be inserted
    """
    for i, line in enumerate(lines):
        if line.startswith('\tCHAR: .byte'):
            lines[i] = f"\tCHAR: .byte '{val}'\n"
    return lines
                
if __name__ == '__main__':
    val = get_terminal_args()
    lines = read_assembly_file()
    new_lines = insert_char_val(lines, val)
    over_write_mips_file(new_lines)