
import numpy
a = numpy.load("/home/nlevisrael/hypergr/ntxh/ar/../xd/clo43sd/CLO-43SD/mfcc/YTWAFC1601.mfcc.npy", allow_pickle=True, encoding='latin1')
numpy.save("/home/nlevisrael/hypergr/ntxh/ar/../xd/clo43sd/CLO-43SD/mfcc-py2/YTWAFC1601.mfcc.2.npy", a, fix_imports=True)