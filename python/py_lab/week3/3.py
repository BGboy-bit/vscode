import os
from collections import OrderedDict
aa20 = 'ARNDCQEGHILKMFPSTWYV'
seqs = OrderedDict()
file_path = 'D://vscode//python//py_lab//week3//result6.txt'

with open("seqs_fasta.txt", "r") as fout:    
    seq_id = ''
    for line in fout:
        if line[0] == ">":
            seq_id = line[1:].strip()
            seqs[seq_id] = ''
        else:
            seqs[seq_id] += line.strip()

with open(file_path, 'w') as fin:
    fin.write("ID".ljust(9))
    for i in aa20:
        fin.write(i.center(10))
    fin.write("\n")
    for seq_id, seq in seqs.items():
        fin.write(f"{seq_id}")
        summ = len(seq)
        for aa in aa20:
            fre = seq.count(aa) / summ * 100
            fin.write(f"{fre:.1f}".rjust(10))
        fin.write("\n")