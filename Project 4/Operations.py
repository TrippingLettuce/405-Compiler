import os

def readtxt()->str:
    os.chdir('Calc')
    return os.listdir()

def compute(list_of_text_files:list):
    print(list_of_text_files)
    for file in list_of_text_files:
        if file.endswith('.txt'):
            with open(file, 'r') as f:
                string = f.read()
            results = compstring(string)
            writeresults(results, file)
        
        
def compstring(string:str)->str:
    return str(eval(string))

def writeresults(results:str, file:str)->None:
    with open(f'Results/{file}_results.txt', 'w') as f:
        f.write(results)
        
if __name__ == '__main__':
    listTF = readtxt()
    compute(listTF)
    